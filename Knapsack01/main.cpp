#include "knapsack.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	std::vector<int> values = {60, 100, 120};
	std::vector<int> weights = {10, 20, 30};
	printf("%d", greedy_knapsack(weights, values, 50));
	return 1;
}
