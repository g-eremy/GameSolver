#include "flood_it_serialization.h"

#include <cstring>

const char* FloodItSerialization::couleurs[NB_UI_COLORS] = {
	"#be2828", // 0 red
	"#4a992b", // 1 green
	"#296ca7", // 2 blue
	"#e4e22e", // 3 yellow
	"#8f5aa8", // 4 purple
	"#da8132", // 5 orange
	"#72d6cf", // 6 cyan
	"#fc64ea", // 7 magenta
	"#6b4011", // 8 brown
	"#212121"  // 9 black
};

const size_t FloodItSerialization::indexes[NB_UI_INDEXES] = {
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	14,
	18,
	22,
	26,
	30,
	50,
	100,
	150,
	200,
	300,
	400,
	500,
	750,
	1000
};

size_t FloodItSerialization::colorToInt(const char* color)
{
	size_t i = 0;
	bool found = false;

	while (i < NB_UI_COLORS && !found)
	{
        if(!strcmp(couleurs[i], color))
		{
			found = true;
		}
		else
		{
			++i;
		}
    }

	return i;
}


char* FloodItSerialization::intToColor(const size_t& color)
{
    return const_cast<char*>(couleurs[color]);
}

int FloodItSerialization::indexToSize(const int& i)
{
	return indexes[i];
}
