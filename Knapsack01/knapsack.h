#include <vector>
#include <iostream>

//there is a good source of illustration / code for this problem here that I used: https://www.geeksforgeeks.org/knapsack-problem/

int greedy_knapsack(std::vector<int> weights, std::vector<int> values, int total_weight)
{
	int size = weights.size();
	int knap_table[size+1][total_weight+1];

	//we want to check every possible combination, so we need a table with one dimension the size of the max weight.
	for (int item = 0; item <= size; item++) 
		for (int weight = 0; weight <= total_weight; weight++) {
			
			//if the item or weight is 0, just put a 0 in.
			if (item == 0 || weight == 0)
				knap_table[item][weight] = 0;
			
			//if the weight of the item is less than or equal to the current weight we are looking at, check it.
			else if (weights[item-1] <= weight)
			{
				//if the value of the item plus the current value we have is greater than the value we currently have on the table, add it.
				if ((values[item-1] + knap_table[item-1][weight - weights[item-1]]) > knap_table[item-1][weight])
					knap_table[item][weight] = values[item-1] + knap_table[item-1][weight - weights[item-1]];
			}
			//don't add anything, just do nothing.
			else
				knap_table[item][weight] = knap_table[item-1][weight];
		}
			
	//return the value at the size and weight; this is our best result.
	return knap_table[size][total_weight];
}
