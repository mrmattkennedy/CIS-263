#include <iostream>
#include <string>

int get_size(std::string pyramid);
std::string find_next_pyramid(int num_blocks, int curr_size);

bool solve_pyramids(int num_blocks, int curr_size)
{
	if (num_blocks == curr_size)
		return true;

	std::string next_pyramid = find_next_pyramid(num_blocks, curr_size);
	
	if (next_pyramid != "0")
	{
		std::cout << find_next_pyramid(num_blocks, curr_size) << std::endl;
		curr_size += get_size(find_next_pyramid(num_blocks, curr_size));
		printf("%d\n", curr_size);
	}	
}

std::string find_next_pyramid(int num_blocks, int curr_size)
{
	int total = num_blocks - curr_size;
	int largestH = 4;
	int largestL = 4;
	int curr_count = 2;
	std::cout << num_blocks << ", " << curr_size << std::endl;
	while ( largestH <= total )
	{
		largestH += curr_count * curr_count;
		curr_count++;
	}

	if (largestH > total)
	{
		curr_count--;
		largestH-= (curr_count * curr_count);
	}
	std::string largestHstr = std::to_string(curr_count) + "H";

	curr_count = 2;
	while ( largestL <= total )
	{
		largestL += curr_count * curr_count;
		curr_count+=2;
	}

	if (largestL > total)
		largestL-= ((curr_count - 1) * (curr_count - 1));

	std::string largestLstr = std::to_string(curr_count) + "L";

	if (largestH > largestL)
		return largestHstr;
	return largestLstr;

}

int get_size(std::string pyramid)
{
	int total = 0;
	if (pyramid.find('L') != std::string::npos)
		for (int i = std::stoi(pyramid.substr(0, pyramid.find('L'))); i > 0; i--)
			total += (i*i);
	else if (pyramid.find('H') != std::string::npos)
		for (int i = std::stoi(pyramid.substr(0, pyramid.find('H'))); i > 0; i--)
			total += (i*i);

	return total;
}
