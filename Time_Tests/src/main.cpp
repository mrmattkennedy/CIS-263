#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include "Celebrity.h"
#include "sorts.h"
#define NAME_LEN 8


int main(int argc, char** argv)
{
	if (argc != 3)
		return 1;

	std::vector<Celebrity> list;
	std::string name;
	int meet_rating;
	bool met;

	for (int i = 0; i < atoi(argv[1]); i++)
	{
		for (int i = 0; i < NAME_LEN; i++)
			name += (rand() % 26 + 97);

		meet_rating = rand() % 11;
		met = rand() % 2;

		list.push_back(Celebrity(name, meet_rating, met));
		name.clear();
	}

	int sort = atoi(argv[2]);
	const clock_t begin_time = clock();
	switch (sort) {
		case 0: bubble_sort(list); 	break;
		case 1: selection_sort(list); 	break;
		case 2: insertion_sort(list);	break;
		case 3: mergeSort(list);	break;
		case 4: quicksort(list);	break;
	}
	std::cout << float( clock () - begin_time ) /  CLOCKS_PER_SEC << std::endl;
	return 1;
}
