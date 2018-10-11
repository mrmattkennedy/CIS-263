/**********************************************************************
 * Homework 1 for CIS 263. Gets user input for the radius, verifies
 * it's a positive number, then displays the perimiter and the area.
 *
 * For the while loop: found how to verify positive input online from
 * stack overflow, user jrok, at 
 * https://stackoverflow.com/questions/10553597/cin-and-getline-skipping-input
 *
 * @author Matt Kennedy
 *********************************************************************/
#include <iostream>


/**********************************************************************
 * main function. This is where the program begins. Get's user input
 * for radius, then displays perimeter and area.
 *********************************************************************/
int main() {
	/** Initialize radius variable, then get user input from user. */
	float radius;
	std::cout << "Please enter a positive number to check the area: ";
	std::cin >> radius;

	/** Use a while loop to continually get input from user until input is a number. */
	while (!std::cin || radius < 0)
	{
		std::cout << "\nPlease enter a number greater than 0: ";
		std::cin.ignore();
		std::cin >> radius;
	}

	/** Calculate perimeter and area, then display the results. */
	float perimiter = 2 * radius * 3.1415926535897; //did not see a way to get the value of pi online.
	float area = radius * radius * 3.1415926535897;

	std::cout << "\nPerimiter of a circle with radius of " << radius << " is " << perimiter << ".";
	std::cout << "\nArea of a circle with radius of " << radius << " is " << area << ".\n";
}
