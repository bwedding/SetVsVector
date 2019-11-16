#pragma once
#include <random>

class RandomRange
{
private:
	std::uniform_int_distribution<> distr; // define the range
	std::mt19937 eng{ std::random_device{}() };

public:
	RandomRange() = delete;

	
	RandomRange(int Low, int High) : distr(Low, High)
	{
		std::random_device rd; 
	}
	
	int Get()
	{
		return distr(eng);
	}

};