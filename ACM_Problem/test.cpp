#include <string>
#include <iostream>
int main()
{
	std::string test = "hello";
	std::cout << test.substr(0, test.find('L')) << std::endl;
	return 1;
}
