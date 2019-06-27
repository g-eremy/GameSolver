#include "lib.h"

using namespace std;

void read_directory(const string& dirname, vector<string>& result)
{
    DIR* dir = opendir(dirname.c_str());
	struct dirent* dp;
    string filename;

    while ((dp = readdir(dir)) != nullptr)
	{
        filename = dp->d_name;

        if (filename.compare(".") == 0 || filename.compare("..") == 0)
        {
            continue;
        }

        result.push_back(filename);
	}

	closedir(dir);
}
