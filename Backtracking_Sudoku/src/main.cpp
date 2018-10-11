#include <iostream>
#include "backtrack.h"

int main(int argc, char** argv)
{
	int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 }, 
			{ 0, 9, 0, 0, 0, 0, 0, 8, 5 }, 
			{ 5, 0, 0, 0, 8, 0, 4, 0, 0 }, 
			{ 4, 0, 7, 2, 0, 6, 8, 9, 0 }, 
			{ 0, 1, 0, 8, 0, 9, 0, 4, 0 }, 
			{ 0, 8, 9, 5, 0, 1, 3, 0, 2 }, 
			{ 0, 0, 3, 0, 1, 0, 0, 0, 9 }, 
			{ 9, 4, 0, 0, 0, 0, 0, 1, 0 }, 
			{ 0, 7, 0, 0, 0, 0, 0, 3, 0 }};


	int board2[9][9]= {{2,0,0,0,9,0,0,3,1},
			{0,0,3,5,0,6,0,2,0},
			{0,0,8,1,3,0,5,4,0},
			{7,2,0,0,0,9,0,0,4},
			{4,0,0,0,0,0,0,0,8},
			{3,0,0,6,0,0,0,9,5}, 
			{0,7,6,0,4,5,1,0,0},
			{0,1,0,9,0,7,4,0,0},
			{5,3,0,0,8,0,0,0,6}};
	printf("Original:\n");
	printBoard(board);
	printf("\nSolved:\n");
	solve(board);
	printBoard(board);
	printf("\n\n");
	printf("Original:\n");
	printBoard(board2);
	printf("\nSolved:\n");
	solve(board2);
	printBoard(board2);
	return 1;

}

