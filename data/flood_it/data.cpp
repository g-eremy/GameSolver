#include "data.h"
#include "storage.h"

#include "game/flood_it/flood_it.h"
#include "game/flood_it/how_to/flood_it_playable.h"
#include "game/flood_it/how_to/flood_it_evaluable_action_try1.h"
#include "game/flood_it/how_to/flood_it_evaluable_action_try2.h"
#include "game/flood_it/how_to/flood_it_evaluable_action_try3.h"
#include "game/flood_it/how_to/flood_it_evaluable_game_try1.h"
#include "game/flood_it/how_to/flood_it_evaluable_game_try2.h"
#include "game/flood_it/how_to/flood_it_graph.h"

#include "herustic/dumb/dumb.h"
#include "herustic/brute_force/brute_force.h"
#include "herustic/glouton/glouton.h"
#include "herustic/deep/deep.h"
#include "herustic/deep/deep_action_game.h"
#include "herustic/dijkstra/dijkstra.h"

#include "lib/benchmark.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static string dumb_name = "dumb";
static string bruteforce_name = "brute_force";
static string glouton1_name = "glouton1";
static string glouton2_name = "glouton2";
static string glouton3_name = "glouton3";
static string deep1_name = "deep1";
static string deep2_name = "deep2";
static string deep3_name = "deep3";
static string dijkstra_name = "dijkstra";

static Benchmark bench_first;
static Benchmark bench_second;
static Benchmark bench_third;

template<template<class> class Herustic, template<class> class Game, class Base>
void do_herustic(Benchmark& bench, const FloodIt& flood_it, const size_t& i, const string& name)
{
	Game<Base> game(flood_it);
	Herustic<Base> herustic(game);

	bench.start();

	while(!game.isWon())
	{
		herustic.play();
	}

	string str_end = name;

	str_end += "\t";
	str_end += to_string(i);
	str_end += "\t";
	str_end += to_string(game.getSize());
	str_end += "\t";
	str_end += to_string(game.getNbColors());
	str_end += "\t";
	str_end += to_string(game.getCountMove());

	bench.end(str_end);
}

void test_first(FloodIt& f, const size_t& i)
{
    cout << "fist group" << endl;

    do_herustic<Dumb, DumbGame, FloodItPlayable<>>(bench_first, f, i, dumb_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry1<FloodItPlayable<>>>(bench_first, f, i, glouton1_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry2<FloodItPlayable<>>>(bench_first, f, i, glouton2_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry3<FloodItPlayable<>>>(bench_first, f, i, glouton3_name);
    do_herustic<Dijkstra, DijkstraGame, FloodItGraph<FloodItPlayable<>>>(bench_first, f, i, dijkstra_name);
}

void test_second(FloodIt& f, const size_t& i)
{
    if (f.getSize() > 50 || f.getNbColors() > 10)
    {
        return;
    }

    cout << "second group" << endl;

    do_herustic<Dumb, DumbGame, FloodItPlayable<>>(bench_second, f, i, dumb_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry1<FloodItPlayable<>>>(bench_second, f, i, glouton1_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry2<FloodItPlayable<>>>(bench_second, f, i, glouton2_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry3<FloodItPlayable<>>>(bench_second, f, i, glouton3_name);
    do_herustic<Dijkstra, DijkstraGame, FloodItGraph<FloodItPlayable<>>>(bench_second, f, i, dijkstra_name);
    do_herustic<Deep, DeepGame, FloodItEvaluableGameTry1<FloodItPlayable<>>>(bench_second, f, i, deep1_name);
    do_herustic<Deep, DeepGame, FloodItEvaluableGameTry2<FloodItPlayable<>>>(bench_second, f, i, deep2_name);
    do_herustic<Deep, DeepGame, DeepActionGame<FloodItEvaluableActionTry2<FloodItPlayable<>>>>(bench_second, f, i, deep3_name);
}

void test_third(FloodIt& f, const size_t& i)
{
    if (f.getSize() > 9 || f.getNbColors() > 5)
    {
        return;
    }

    cout << "third group" << endl;

    do_herustic<Dumb, DumbGame, FloodItPlayable<>>(bench_third, f, i, dumb_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry1<FloodItPlayable<>>>(bench_third, f, i, glouton1_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry2<FloodItPlayable<>>>(bench_third, f, i, glouton2_name);
    do_herustic<Glouton, GloutonGame, FloodItEvaluableActionTry3<FloodItPlayable<>>>(bench_third, f, i, glouton3_name);
    do_herustic<Dijkstra, DijkstraGame, FloodItGraph<FloodItPlayable<>>>(bench_third, f, i, dijkstra_name);
    do_herustic<Deep, DeepGame, FloodItEvaluableGameTry1<FloodItPlayable<>>>(bench_third, f, i, deep1_name);
    do_herustic<Deep, DeepGame, FloodItEvaluableGameTry2<FloodItPlayable<>>>(bench_third, f, i, deep2_name);
    do_herustic<Deep, DeepGame, DeepActionGame<FloodItEvaluableActionTry2<FloodItPlayable<>>>>(bench_third, f, i, deep3_name);
    do_herustic<BruteForce, BruteForceGame, FloodItPlayable<>>(bench_third, f, i, bruteforce_name);
}

void test_data(ostream& out_first, ostream& out_second, ostream& out_third)
{
    string head = "name\ti\tsize\tcolor\tscore\ttime\n";
    vector<void(*)(FloodIt&, const size_t&)> callbacks ({test_first, test_second, test_third});
    retrieve_objects_in_dir("./data/flood_it/files", callbacks);
    out_first << head;
    out_second << head;
    out_third << head;

    bench_first.out(out_first);
	bench_second.out(out_second);
	bench_third.out(out_third);
}
