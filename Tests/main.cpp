#include <vector>
#include <string>
#include <iostream>
#include "sorts.h"

int main(int argc, char**argv)
{
	std::vector<int> vec;
	for (int i = 0; i < 100000; i++)
		vec.push_back(rand() % 10);
		//vec.push_back(1);

	selection_sort(vec);
	return 1;
}
