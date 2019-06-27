#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#define NB_UI_COLORS 10
#define NB_UI_INDEXES 22

#include <cstddef>

class FloodItSerialization
{
    private:
        static const char* couleurs[NB_UI_COLORS];
		static const size_t indexes[NB_UI_INDEXES];

    public:
		static size_t colorToInt(const char*);
		static char* intToColor(const size_t&);
		static int indexToSize(const int&);
};

#endif // SERIALIZATION_H
