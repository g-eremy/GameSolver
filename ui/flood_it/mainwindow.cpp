#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "herustic/dumb/dumb.h"
#include "herustic/deep/deep.h"
#include "herustic/glouton/glouton.h"
#include "herustic/brute_force/brute_force.h"
#include "herustic/dijkstra/dijkstra.h"
#include "serialization/flood_it/flood_it_serialization.h"
#include "game/flood_it/how_to/flood_it_playable.h"
#include "game/flood_it/how_to/flood_it_graph.h"
#include "game/flood_it/how_to/flood_it_evaluable_action_try1.h"
#include "game/flood_it/how_to/flood_it_evaluable_action_try2.h"
#include "game/flood_it/how_to/flood_it_evaluable_action_try3.h"
#include "game/flood_it/how_to/flood_it_evaluable_game_try1.h"
#include "game/flood_it/how_to/flood_it_evaluable_game_try2.h"
#include "herustic/deep/deep_action_game.h"
#include "lib/benchmark.h"

#include <QTimer>
#include <iostream>

using namespace std;

template<template<class> class Herustic, template<class> class Game, class Base>
void make_herustic(MainWindow* window, bool animation)
{
	Game<Base>* game = new Game<Base>(*(window->flood_it));
	Herustic<Base>* herustic = new Herustic<Base>(*game);
	window->flood_it.reset(game);
	window->launchHerustic(game, herustic, animation);
}

MainWindow::MainWindow(QWidget* parent): QMainWindow(parent), ui(new Ui::MainWindow), flood_it(nullptr), flood_it_copy(nullptr)
{
	ui->setupUi(this);
	makeConnect();
	newGame();
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::makeConnect()
{
	connect(ui->tableWidget, SIGNAL(cellClicked(int,int)), this, SLOT(play(int,int)));
	connect(ui->create, SIGNAL(clicked()), this, SLOT(newGame()));
	connect(ui->restart, SIGNAL(clicked()), this, SLOT(restartGame()));
	connect(ui->dumb_h, SIGNAL(clicked()), this, SLOT(playDumb()));
	connect(ui->brute_force_h, SIGNAL(clicked()), this, SLOT(playBruteForce()));
	connect(ui->glouton_h_1, SIGNAL(clicked()), this, SLOT(playGlouton1()));
	connect(ui->glouton_h_2, SIGNAL(clicked()), this, SLOT(playGlouton2()));
	connect(ui->glouton_h_3, SIGNAL(clicked()), this, SLOT(playGlouton3()));
	connect(ui->deep1_h, SIGNAL(clicked()), this, SLOT(playDeep1()));
	connect(ui->deep2_h, SIGNAL(clicked()), this, SLOT(playDeep2()));
	connect(ui->deep3_h, SIGNAL(clicked()), this, SLOT(playDeep3()));
	connect(ui->tabu_h, SIGNAL(clicked()), this, SLOT(playTabu()));
	connect(ui->dijkstra_h, SIGNAL(clicked()), this, SLOT(playDijkstra()));
}

void MainWindow::play(const int& row, const int& column)
{
	const QColor& current_color = ui->tableWidget->item(row, column)->backgroundColor();
	size_t int_chosen = FloodItSerialization::colorToInt(current_color.name().toLocal8Bit().data());

	flood_it->play(int_chosen);
	updateGrid();
}

void MainWindow::newGame()
{
	int int_nb_elem = FloodItSerialization::indexToSize(ui->size_entry->currentIndex());
	int int_nb_colors = ui->nbr_colors->currentIndex() + 3;

	size_t sizet_nb_elem = static_cast<size_t>(int_nb_elem);
	size_t sizet_nb_colors = static_cast<size_t>(int_nb_colors);

	ui->tableWidget->setRowCount(int_nb_elem);
	ui->tableWidget->setColumnCount(int_nb_elem);

	ui->tableWidget->setMinimumHeight(DEFAULT_GRID_SIZE / int_nb_elem * int_nb_elem);
	ui->tableWidget->setMinimumWidth(DEFAULT_GRID_SIZE / int_nb_elem * int_nb_elem);

	ui->tableWidget->setMaximumHeight(DEFAULT_GRID_SIZE / int_nb_elem * int_nb_elem);
	ui->tableWidget->setMaximumWidth(DEFAULT_GRID_SIZE / int_nb_elem * int_nb_elem);

	ui->container->setSpacing(DEFAULT_MARGIN);
	ui->container->setMargin(DEFAULT_MARGIN);

	int count = ui->container->count();
	int height = ui->tableWidget->height();

	for (int i = 0; i < count; ++i)
	{
		height += DEFAULT_MARGIN;

		if (ui->container->itemAt(i)->layout() == nullptr)
			continue;

		height += ui->container->itemAt(i)->layout()->itemAt(0)->widget()->height();
	}

	setMinimumSize(
		QSize(
			ui->tableWidget->width() + (DEFAULT_MARGIN * 2),
			height + (DEFAULT_MARGIN * 2)
		)
	);

	setMaximumSize(
		QSize(
			ui->tableWidget->width() + (DEFAULT_MARGIN * 2),
			height + (DEFAULT_MARGIN * 2)
		)
	);

	flood_it.reset(new FloodIt(sizet_nb_elem, sizet_nb_colors));
	flood_it_copy.reset(new FloodIt(*flood_it));

	resetGrid();
}

void MainWindow::restartGame()
{
	flood_it.reset(new FloodIt(*flood_it_copy));

	ui->label_count->setText("0");

	resetColorGrid();
}

void MainWindow::playDumb()
{
	make_herustic<Dumb, DumbGame, FloodItPlayable<>>(this);
}

void MainWindow::playBruteForce()
{
	/* begin : make limit max */
	make_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry2<FloodItPlayable<>>>(this, false);

	size_t limit_max = flood_it->getCountMove();
	flood_it.reset(new FloodIt(*flood_it_copy));
	/* end : make limit max*/

	auto game = new BruteForceGame<FloodItPlayable<>>(*flood_it);
	auto herustic = new BruteForce<FloodItPlayable<>>(*game, limit_max + 1);

	flood_it.reset(game);
	launchHerustic(game, herustic);
}

void MainWindow::playGlouton1()
{
	make_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry1<FloodItPlayable<>>>(this);
}

void MainWindow::playGlouton2()
{
	make_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry2<FloodItPlayable<>>>(this);
}

void MainWindow::playGlouton3()
{
	make_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry3<FloodItPlayable<>>>(this);
}

void MainWindow::playDeep1()
{
	make_herustic<Deep, DeepGame, FloodItEvaluableGameTry1<FloodItPlayable<>>>(this);
}

void MainWindow::playDeep2()
{
	make_herustic<Deep, DeepGame, FloodItEvaluableGameTry2<FloodItPlayable<>>>(this);
}

void MainWindow::playDeep3()
{
	make_herustic<Deep, DeepGame, DeepActionGame<FloodItEvaluableActionTry2<FloodItPlayable<>>>>(this);
}

void MainWindow::playTabu()
{
	cout << "ok" << endl;
}

void MainWindow::playDijkstra()
{
	make_herustic<Dijkstra, DijkstraGame, FloodItGraph<FloodItPlayable<>>>(this);
}

void MainWindow::launchHerustic(FloodIt* game, IHerustic* herustic, bool animation)
{
	if (animation)
	{
		if (game->isWon())
		{
			delete herustic;
			return;
		}


		QTimer::singleShot(100, this, [this, herustic, game](){
			herustic->play();
			this->updateGrid();
			this->launchHerustic(game, herustic, true);
		});
	}
	else
	{
		while(!game->isWon())
		{
			herustic->play();
		}

		delete herustic;

		updateGrid();
		updateGrid();
	}
}

void MainWindow::resetGrid()
{
	int size;
	int nbr_elem;

	size = ui->tableWidget->height();
	nbr_elem = ui->tableWidget->rowCount();

	for (int i = 0; i < nbr_elem; ++i)
	{
		for (int j = 0; j < nbr_elem; ++j)
		{
			ui->tableWidget->setItem(j, i, new QTableWidgetItem());

			ui->tableWidget->verticalHeader()->setDefaultSectionSize(size / nbr_elem);
			ui->tableWidget->verticalHeader()->setMinimumSectionSize(size / nbr_elem);
			ui->tableWidget->verticalHeader()->setMaximumSectionSize(size / nbr_elem);

			ui->tableWidget->horizontalHeader()->setDefaultSectionSize(size / nbr_elem);
			ui->tableWidget->horizontalHeader()->setMinimumSectionSize(size / nbr_elem);
			ui->tableWidget->horizontalHeader()->setMaximumSectionSize(size / nbr_elem);
		}
	}

	resetColorGrid();
}


void MainWindow::resetColorGrid()
{
	int int_i;
	int int_j;
	int int_size;

	size_t begin_x;
	size_t begin_y;
	size_t sizet_i;
	size_t sizet_j;
	size_t sizet_size;

	char* current_color;

	begin_x = flood_it->getBeginX();
	begin_y = flood_it->getBeginY();
	captured_zone_size = flood_it->getCell(begin_x, begin_y).getZone().countCells();

	sizet_size = flood_it->getSize();
	int_size = static_cast<int>(sizet_size);

	for (int_i = 0; int_i < int_size; ++int_i)
	{
		for (int_j = 0; int_j < int_size; ++int_j)
		{
			sizet_i = static_cast<size_t>(int_i);
			sizet_j = static_cast<size_t>(int_j);

			current_color = FloodItSerialization::intToColor(flood_it->getCell(sizet_j, sizet_i).getColor());
			ui->tableWidget->item(int_i, int_j)->setBackgroundColor(current_color);
		}
	}

	ui->label_count->setText(QString::number(flood_it->getCountMove()));
}


void MainWindow::updateGrid()
{
	int int_i;
	int int_j;

	size_t sizet_i;
	size_t begin_x;
	size_t begin_y;

	char* color_captured;

	begin_x = flood_it->getBeginX();
	begin_y = flood_it->getBeginY();
	FloodItCell& begin_cell = flood_it->getCell(begin_x, begin_y);
	FloodItZone& begin_zone = begin_cell.getZone();

	color_captured = FloodItSerialization::intToColor(begin_cell.getColor());

	for (sizet_i = 0; sizet_i < captured_zone_size; ++sizet_i)
	{
		FloodItCell& current_cell = begin_zone.getCell(sizet_i);
		int_i = static_cast<int>(current_cell.getY());
		int_j = static_cast<int>(current_cell.getX());

		ui->tableWidget->item(int_i, int_j)->setBackgroundColor(color_captured);
	}

	captured_zone_size = begin_zone.countCells();
	ui->label_count->setText(QString::number(flood_it->getCountMove()));
}
