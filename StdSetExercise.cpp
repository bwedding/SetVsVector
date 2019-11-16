#include <set>
#include <vector>
#include "RandomRange.h"
#include "ExecutionTimer.h"

const int TEST_RUNS = 100000000;

void UseSet(RandomRange random)
{
	std::set <int, std::greater <>> input;
	for (int i = 0; i < TEST_RUNS; i++)
	{
		input.insert(random.Get());
		if (input.size() > 3) 
		{
			input.erase(*input.rbegin());
		}
	}
}

void UseVector(RandomRange& random)
{
	std::vector<int> input;
	for (int i = 0; i < TEST_RUNS; i++)
	{
		input.push_back(random.Get());
	}
	std::sort(input.begin(), input.end());
	input.erase(unique(input.begin(), input.end()), input.end());
}

int main()
{
	RandomRange random(1, 1000000);
	{
		ExecutionTimer execution;
		UseSet(random);
	}
	{
		ExecutionTimer execution;
		UseVector(random);
	}
	
	return 0;
}
