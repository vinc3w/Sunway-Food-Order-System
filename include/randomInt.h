#ifndef RANDOMINT_H
#define RANDOMINT_H

#include <chrono>
#include <random>
#include <cmath>

class RandomInt
{
private:
	std::random_device rd{};
	std::seed_seq ss{
		static_cast<std::mt19937::result_type>(
			std::chrono::steady_clock::now().time_since_epoch().count()
		),
		rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()
	};
	std::mt19937 mt{ ss };
public:
	int get(int length)
	{
		std::uniform_int_distribution dist{
			static_cast<int>(std::pow(10, length - 1)),
			static_cast<int>(std::pow(10, length))
		};
		return dist(mt);
	}
};

#endif
