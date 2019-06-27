#include <fstream>
#include <iostream>
#include "storage.h"
#include "lib/lib.h"

using namespace std;

void store_object(const char* filename, const FloodIt& game)
{
    ofstream ofs(filename, ofstream::out);
    size_t size = game.getSize();
    size_t nb_colors = game.getNbColors();
    size_t color;

    ofs.write((char*)&size, sizeof (size));
    ofs.write((char*)&nb_colors, sizeof (nb_colors));

    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = 0; j < size; ++j)
        {
            color = game.getCell(j, i).getColor();
            ofs.write((char*)&color, sizeof (color));
        }
    }

    ofs.close();
}

void retrieve_object(const char* filename, const vector<void(*)(FloodIt&, const size_t&)>& vector_callback)
{
    ifstream ifs (filename, ifstream::in);

    size_t** matrix;

    size_t size;
    size_t nb_colors;
    size_t callbacks_size;

    void(*callback)(FloodIt&, const size_t&);

    ifs.read((char*)&size, sizeof (size));
    ifs.read((char*)&nb_colors, sizeof (nb_colors));

    matrix = new size_t*[size];

	for (size_t i = 0; i < size; ++i)
	{
        matrix[i] = new size_t[size];

		for (size_t j = 0; j < size; ++j)
		{
            ifs.read((char*)&matrix[i][j], sizeof (**matrix));
        }

    }

    ifs.close();

    FloodIt game (size, nb_colors, matrix);
    cout << game.getSize() << " - " << game.getNbColors() << endl;

    for (size_t i = 0; i < size; ++i)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    callbacks_size = vector_callback.size();

    for (size_t i = 0; i < callbacks_size; ++i)
    {
        callback = vector_callback[i];
        callback(game, i);
    }
}

void retrieve_objects_in_dir(const char* dir, const vector<void(*)(FloodIt&, const size_t&)>& vector_callback)
{
	vector<string> files;
	size_t size;
	string filename;

	read_directory(dir, files);
	size = files.size();

	for (size_t i = 0; i < size; ++i)
	{
        cout << "file " << i << "/" << size << " - ";
		filename = dir + string("/") + files[i];
        retrieve_object(filename.data(), vector_callback);
	}
}

void generate_files(const size_t& nb_elements, const size_t& size, const size_t& begin_color, const size_t& end_color)
{
	string filename;

	for (size_t i = 0; i < nb_elements; ++i)
	{
		for (size_t j = begin_color; j <= end_color; ++j)
		{
			FloodIt game(size, j);
			filename = "data/flood_it/files/flood_it_" + to_string(i) + "_" + to_string(size) + "_" + to_string(j);
			store_object(filename.data(), game);
		}
	}
}

void test_storage()
{
	generate_files(10, 5, 3, 10);
	generate_files(10, 6, 3, 10);
	generate_files(10, 7, 3, 10);
	generate_files(10, 8, 3, 10);
	generate_files(10, 9, 3, 10);
	generate_files(10, 10, 3, 10);
	generate_files(10, 15, 3, 10);
	generate_files(10, 20, 3, 10);
	generate_files(10, 50, 5, 20);
	generate_files(5, 100, 5, 30);
	generate_files(5, 200, 5, 30);
	generate_files(1, 500, 5, 15);
	generate_files(1, 1000, 5, 15);
}
