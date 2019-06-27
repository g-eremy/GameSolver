#include <QApplication>
#include "ui/flood_it/mainwindow.h"
#include "data/flood_it/data.h"
#include "data/flood_it/storage.h"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	/*ofstream ofs1 ("data/flood_it/results/result1.txt", ofstream::out);
	ofstream ofs2 ("data/flood_it/results/result2.txt", ofstream::out);
	ofstream ofs3 ("data/flood_it/results/result3.txt", ofstream::out);

    test_data(ofs1, ofs2, ofs3);

    ofs1.close();
    ofs2.close();
	ofs3.close();*/

	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	return a.exec();
}
