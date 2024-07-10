#pragma once

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define NUM_MINES 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initialize the board
void init_board(char board[ROWS][COLS], int row, int col, char set);

// Print the board
void print_board(char board[ROWS][COLS], int row, int col);

// Set up mines 
void set_mines(char board[ROWS][COLS], int row, int col);

// Find mines
void find_mines(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);