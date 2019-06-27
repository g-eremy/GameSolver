#-------------------------------------------------
#
# Project created by QtCreator 2019-01-30T00:06:54
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game_solver
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

CONFIG(release, debug|release) {
    CONFIG += optimize_full
}

SOURCES += \
    main.cpp \
    game/flood_it/flood_it.cpp \
    game/flood_it/flood_it_cell.cpp \
    game/flood_it/flood_it_zone.cpp \
    game/flood_it/flood_it_action.cpp \
    lib/vector.tpp \
    lib/random.tpp \
    lib/benchmark.cpp \
    serialization/flood_it/flood_it_serialization.cpp \
    ui/flood_it/mainwindow.cpp \
    herustic/brute_force/brute_force.tpp \
    herustic/deep/deep.tpp \
    herustic/dumb/dumb.tpp \
    herustic/glouton/glouton.tpp \
    herustic/tabu/tabu.tpp \
    herustic/brute_force/brute_force_game.tpp \
    herustic/deep/deep_game.tpp \
    herustic/dumb/dumb_game.tpp \
    herustic/glouton/glouton_game.tpp \
    herustic/tabu/tabu_game.tpp \
    herustic/dijkstra/dijkstra.tpp \
    herustic/dijkstra/dijkstra_game.tpp \
    game/flood_it/how_to/flood_it_playable.tpp \
    game/flood_it/how_to/flood_it_graph.tpp \
    game/flood_it/how_to/flood_it_evaluable_game_try1.tpp \
    game/flood_it/how_to/flood_it_evaluable_game_try2.tpp \
    lib/lib.tpp \
    game/flood_it/how_to/flood_it_evaluable_action_try1.tpp \
    game/flood_it/how_to/flood_it_evaluable_action_try2.tpp \
    game/flood_it/how_to/flood_it_evaluable_action_try3.tpp \
    herustic/deep/deep_action_game.tpp \
    data/flood_it/data.cpp \
    data/flood_it/storage.cpp \
    lib/lib.cpp

HEADERS += \
    game/flood_it/flood_it.h \
    game/flood_it/flood_it_cell.h \
    game/flood_it/flood_it_zone.h \
    game/flood_it/flood_it_action.h \
    game/flood_it/how_to/flood_it_playable.h \
    herustic/interfaces/iaction.h \
    herustic/interfaces/iplayable.h \
    herustic/interfaces/ievaluable_game.h \
    herustic/interfaces/iherustic.h \
    herustic/interfaces/igame.h \
    herustic/interfaces/igraph.h \
    herustic/interfaces/inode.h \
    herustic/brute_force/brute_force.h \
    herustic/brute_force/brute_force_game.h \
    herustic/dumb/dumb.h \
    herustic/dumb/dumb_game.h \
    herustic/deep/deep.h \
    herustic/deep/deep_game.h \
    herustic/glouton/glouton.h \
    herustic/glouton/glouton_game.h \
    herustic/tabu/tabu.h \
    herustic/tabu/tabu_game.h \
    herustic/dijkstra/dijkstra.h \
    herustic/dijkstra/dijkstra_game.h \
    lib/random.h \
    lib/vector.h \
    serialization/flood_it/flood_it_serialization.h \
    ui/flood_it/mainwindow.h \
    lib/benchmark.h \
    game/flood_it/how_to/flood_it_graph.h \
    game/flood_it/how_to/flood_it_evaluable_game_try1.h \
    game/flood_it/how_to/flood_it_evaluable_game_try2.h \
    lib/lib.h \
    herustic/interfaces/ievaluable_action.h \
    game/flood_it/how_to/flood_it_evaluable_action_try1.h \
    game/flood_it/how_to/flood_it_evaluable_action_try2.h \
    game/flood_it/how_to/flood_it_evaluable_action_try3.h \
    herustic/deep/deep_action_game.h \
    data/flood_it/data.h \
    data/flood_it/storage.h


FORMS += \
    ui/flood_it/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
