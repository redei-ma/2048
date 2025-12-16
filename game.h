#ifndef GAME_H
# define GAME_H

#include <stdbool.h>

enum e_const
{
	WIN_VALUE = 128,
	GRID_SIZE = 4
};

bool moveUp(int grid[GRID_SIZE][GRID_SIZE], int *score);
bool moveDown(int grid[GRID_SIZE][GRID_SIZE], int *score);
bool moveLeft(int grid[GRID_SIZE][GRID_SIZE], int *score);
bool moveRight(int grid[GRID_SIZE][GRID_SIZE], int *score);

#endif
