#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu() {
	printf("********************\n");
	printf("*****  1:Play  *****\n");
	printf("*****  0:Exit  *****\n");
	printf("********************\n");
}


void game() {
	// Use mine to store mine's information
	char mine[ROWS][COLS] = { 0 };

	// Use show to 
	char show[ROWS][COLS] = { 0 };

	// Initialize board
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');

	// Set up mines 
	set_mines(mine, ROW, COL);

	// Print board
	print_board(show, ROW, COL);
	print_board(mine, ROW, COL);

	// Find mines
	find_mines(mine, show, ROW, COL);
}


void test() {
	srand((unsigned int) time(NULL));

	// Player's choice
	int input;
	
	do
	{
		menu();
		printf("Please select: ");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("Exit game, thx for playing!");
			break;
		default:
			printf("Invalid input, please select again.\n");
			break;
		}
	} while (input);
}

int main() {
	test();
	return 0;
}