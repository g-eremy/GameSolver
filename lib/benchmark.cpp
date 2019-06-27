#include "benchmark.h"
#include <ctime>

using namespace std;
using namespace std::chrono;

void Benchmark::start()
{
	start_time = system_clock::now();
}

void Benchmark::end(const string& title)
{
	time_point<system_clock> end_time = system_clock::now();
	size_t calc = duration_cast<microseconds>(end_time - start_time).count();
	times.emplace_back(calc);
	titles.emplace_back(title);
}

void Benchmark::out(ostream& out)
{
	size_t i;
	size_t count = titles.size();

	for (i = 0; i < count; ++i)
	{
		out << titles[i] << " : " << times[i] << "\n";
	}
}
