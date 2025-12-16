#ifndef GAME_H
# define GAME_H

# include "libft/include/libft.h"
# include <ncurses.h>
# include <stdlib.h>
# include <time.h>
# include <stdbool.h>

enum e_const
{
	WIN_VALUE = 32,
	GRID_SIZE = 4
};

enum
{
	C2 = 10,
	C4,
	C8,
	C16,
	C32,
	C64,
	C128,
	C256,
	C512,
	C1024,
	C2048
};

enum
{
	PAIR_2 = 1,
	PAIR_4,
	PAIR_8,
	PAIR_16,
	PAIR_32,
	PAIR_64,
	PAIR_128,
	PAIR_256,
	PAIR_512,
	PAIR_1024,
	PAIR_2048,
	PAIR_DEF
};

bool	moveUp(int grid[GRID_SIZE][GRID_SIZE], int *score);
bool	moveDown(int grid[GRID_SIZE][GRID_SIZE], int *score);
bool	moveLeft(int grid[GRID_SIZE][GRID_SIZE], int *score);
bool	moveRight(int grid[GRID_SIZE][GRID_SIZE], int *score);

void	init_colors(void);
void	printGrid(int grid[GRID_SIZE][GRID_SIZE], int score);

bool	isPowerOfTwo(int n);
bool	freeSpace(int grid[GRID_SIZE][GRID_SIZE]);
void	addNewNumber(int grid[GRID_SIZE][GRID_SIZE]);
bool	canMove(int grid[GRID_SIZE][GRID_SIZE]);
bool	hasWon(int grid[GRID_SIZE][GRID_SIZE]);
void	initGrid(int grid[GRID_SIZE][GRID_SIZE]);
void	closeGame(int score);

#endif
