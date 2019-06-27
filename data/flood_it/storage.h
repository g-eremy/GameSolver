#include <string>
#include <vector>
#include <memory>
#include "game/flood_it/flood_it.h"

void store_object(const char*, const FloodIt&);
void retrieve_object(const char* filename, const std::vector<void(*)(FloodIt&, const size_t&)>&);
void retrieve_objects_in_dir(const char*, const std::vector<void(*)(FloodIt&, const size_t&)>&);
void generate_files(const size_t&, const size_t&, const size_t&, const size_t&);
void test_storage();
