#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "game/flood_it/flood_it.h"
#include "herustic/interfaces/iherustic.h"

#define DEFAULT_NBR_ELEMS 6
#define DEFAULT_NBR_COLORS 2
#define DEFAULT_HEIGHT 980
#define DEFAULT_WIDTH 840
#define DEFAULT_GRID_SIZE 800
#define DEFAULT_MARGIN 7
#define DEFAULT_BUTTON_HEIGHT 40
#define DEFAULT_BUTTON_WIDTH 100

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

	protected:
		// attributes
		Ui::MainWindow* ui;
		std::unique_ptr<FloodIt> flood_it;
		std::unique_ptr<FloodIt> flood_it_copy;

		size_t captured_zone_size;

		// methods
		virtual void makeConnect();
		virtual void resetGrid();
		virtual void resetColorGrid();
		virtual void updateGrid();
		virtual void launchHerustic(FloodIt*, IHerustic*, bool = false);

	public:
		explicit MainWindow(QWidget* = nullptr);
		virtual ~MainWindow();

		template<template<class> class Herustic, template<class> class Game, class Base>
		friend void make_herustic(MainWindow*, bool = true);

	public slots:
		virtual void play(const int&, const int&);
		virtual void newGame();
		virtual void restartGame();
		virtual void playDumb();
		virtual void playBruteForce();
        virtual void playGlouton1();
        virtual void playGlouton2();
        virtual void playGlouton3();
		virtual void playDeep1();
		virtual void playDeep2();
		virtual void playDeep3();
        virtual void playTabu();
		virtual void playDijkstra();
};

#endif // MAINWINDOW_H
