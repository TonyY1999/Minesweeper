#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

// Initialize the board
void init_board(char board[ROWS][COLS], int row, int col, char set) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

// Print the board
void print_board(char board[ROWS][COLS], int row, int col) {
	int i, j;

	printf("\n");
	printf("--- Minesweeper ---\n");

	// Print column number
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	// Print the row number
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);

		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}

		printf("\n");
	}

	printf("--- Minesweeper ---\n");
	printf("\n");
}

// Set up mines 
void set_mines(char mine[ROWS][COLS], int row, int col) {
	for (int i = 0; i < NUM_MINES; i++)
	{
		int x, y;
		x = rand() % row + 1;
		y = rand() % col + 1;

		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
		}
		else
		{
			i--;
		}
	}
}


// Get mines count
int get_mines_count(char mine[ROWS][ROWS], int row, int col) {
	return (mine[row - 1][col - 1] + mine[row - 1][col] + mine[row - 1][col + 1] 
		+ mine[row][col - 1] + mine[row][col + 1]
		+ mine[row + 1][col - 1] + mine[row + 1][col] + mine[row + 1][col + 1] - 8 * '0');
}

// Find mines
void find_mines(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	// Coordinate that player enter
	int x, y;

	// The safe location
	int win = 0;

	// loop if the safe location is less than (row * col) - NUM_MINES
	while (win < (row * col) - NUM_MINES)
	{
		printf("Please enter the coordinates to be checked: ");
		scanf("%d %d", &x, &y);

		// Check if the coordinate valid or not
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{	
			// If the coordinate was checked already
			if (show[x][y] != '*')
			{
				printf("This coordinate was checked.\n");
				continue;
			}

			// If the coordinate is a mine
			if (mine[x][y] == '1')
			{
				printf("Boom! Game over!\n");
				print_board(mine, ROW, COL);
				break;
			}
			else
			{
				int n = get_mines_count(mine, x, y);
				show[x][y] = n + '0';
				print_board(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("Invalid coordinates, please enter again.\n");
		}
	}

	// If win is exactly equals to (row * col) - NUM_MINES after loop, then player wins
	if (win == (row * col) - NUM_MINES)
	{
		printf("Player wins!\n");
		print_board(mine, ROW, COL);
	}
}