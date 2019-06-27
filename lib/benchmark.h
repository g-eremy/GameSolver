#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <ostream>
#include <vector>
#include <cstring>
#include <chrono>
#include <ctime>

class Benchmark
{
	protected:
		std::chrono::time_point<std::chrono::system_clock> start_time;
		std::vector<size_t> times;
		std::vector<std::string> titles;

	public:
		virtual ~Benchmark() = default;
		virtual void start();
		virtual void end(const std::string&);
		virtual void out(std::ostream&);
};

#endif // BENCHMARK_H
