#include <iostream>
#define BOARD_SIZE 9
#define EMPTY 0

bool found_empty_cell(int board[9][9], int &row, int &col);
void printBoard(int board[9][9]);
bool num_available(int row, int col, int num, int board[9][9]);
bool check_squares(int row, int col, int num, int board[9][9]);
bool check_individual_square(int min_row, int max_row, int min_col, int max_col, int num, int board[9][9]);

/**********************************************************************
 * This is the main method. Recursively looks for a solution. This uses
 * a helper function to see if there are any empty cells. If there are,
 * set them to the first available number, then recursively call itself.
 * If there are no numbers available, then it will return false and
 * back up.
 *
 * There is a different solution here as well, which uses loops and
 * backs up within the loop. However, this has issues.
 *********************************************************************/
bool solve(int board[9][9])
{
	/*
	//Original solution: This used simple loops, and "backtracked" from the loop itself. However,
	//if a board is unsolvable, it would never know. 
	//Took a different approach with help from online to use a backtracking solution.
	bool found_num;
	for (int row = 0; row < BOARD_SIZE; row++)
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			found_num = false;
			for (int num = board[row][col]; num <= BOARD_SIZE; num++)
			{
				if (num == EMPTY)
					continue;
				if (num_available(row, col, num, board)) {
					board[row][col] = num;
					found_num = true;
					break;
				}

			}
			if (solve(board))
				return true;

			if (!found_num) {
				board[row][col] = EMPTY;
				if (col != 0)
					col-=2;
				else {
					row--;
					col = 7;
				}
			}
		}
	*/

	int row, col;
	if (!found_empty_cell(board, row, col))
		return true;
	
	for (int num = 1; num <= BOARD_SIZE; num++)
		if (num_available(row, col, num, board))
		{
			board[row][col] = num;
			if (solve(board))
				return true;
			board[row][col] = EMPTY;
		}
	return false;
}

/**********************************************************************
 * Looks for an empty cell. If there are none, returns false. If there
 * is, returns true. Automatically sets row and col by passing by ref.
 *
 * @param board The sudoku board
 * @param &row The rows to look through.
 * @param &col The cols to look through.
 *********************************************************************/
bool found_empty_cell(int board[9][9], int &row, int &col)
{
	for (row = 0; row < BOARD_SIZE; row++)
		for (col = 0; col < BOARD_SIZE; col++)
			if (board[row][col] == EMPTY)
				return true;
	return false;
}

/**********************************************************************
 * Checks to see if a number is available at a given spot.
 *
 * @param row The row to check
 * @param col The col to check
 * @param num The num to check
 * @param board The sudoku board
 * @return True if the spot is available, false if it isn't.
 *********************************************************************/
bool num_available(int row, int col, int num, int board[9][9])
{
	for (int check_row = 0; check_row < BOARD_SIZE; check_row++)
		if (board[check_row][col] == num)
			return false;

	for (int check_col = 0; check_col < BOARD_SIZE; check_col++)
		if (board[row][check_col] == num)
			return false;
	
	return check_squares(row, col, num, board);
}

/**********************************************************************
 * Figures out what block the spot is in, and checks that block.
 *
 * @param row The row to check
 * @param col The col to check
 * @param num The num to check
 * @param board The sudoku board
 * @return True if the spot is available, false if it isn't.
 *********************************************************************/
bool check_squares(int row, int col, int num, int board[9][9])
{
	//top left
	if (row <= 2 && col <= 2)
		return check_individual_square(0, 2, 0, 2, num, board);
	//top middle
	else if (row <= 2 && col > 2 && col <= 5)
		return check_individual_square(0, 2, 3, 5, num, board);
	//top right
	else if (row <= 2 && col > 5 && col <= 8)
		return check_individual_square(0, 2, 6, 8, num, board);
	//middle left
	else if (row > 2 && row <= 5 && col <= 2)
		return check_individual_square(3, 5, 0, 2, num, board);
	//middle middle
	else if (row > 2 && row <= 5 && col > 2 && col <= 5)
		return check_individual_square(3, 5, 3, 5, num, board);
	//middle right
	else if (row > 2 && row <= 5 && col > 6 && col <= 8)
		return check_individual_square(3, 5, 6, 8, num, board);
	//bottom left
	else if (row > 5 && row <= 8 && col <= 2)
		return check_individual_square(6, 8, 0, 2, num, board);
	//bottom middle
	else if (row > 5 && row <= 8 && col > 2 && col <= 5)
		return check_individual_square(6, 8, 3, 5, num, board);
	//bottom right
	else if (row > 5 && row <= 8 && col > 5 && col <= 8)
		return check_individual_square(6, 8, 6, 8, num, board);
	
	return true;
}

/**********************************************************************
 * Loops through a given range of blocks to see if the number is already
 * there.
 *
 * @param min_row The starting row spot.
 * @param max_row The ending row spot.
 * @param min_col The starting col spot.
 * @param max_col The ending col spot.
 * @param num The number to check.
 * @param board The sudoku board.
 * @return True if the spot is available, false if not.
 *********************************************************************/
bool check_individual_square(int min_row, int max_row, int min_col, int max_col, int num, int board[9][9])
{
	for (int row = min_row; row <= max_row; row++)
		for (int col = min_col; col <= max_col; col++)
			if (board[row][col] == num)
				return false;
	return true;
}

/**********************************************************************
 * Prints the board.
 *
 * @param board The sudoku board.
 *********************************************************************/
void printBoard(int board[9][9])
{
	for(int row = 0; row < 9; row++){
		for(int col = 0; col < 9; col++){
			printf("%2d", board[row][col]);
		}
		printf("\n");
	}
}
