#ifndef GAME_H
# define GAME_H

enum e_const
{
	WIN_VALUE = 2048,
	GRID_SIZE = 4
};

void moveUp(int grid[GRID_SIZE][GRID_SIZE], int *score);
void moveDown(int grid[GRID_SIZE][GRID_SIZE], int *score);
void moveLeft(int grid[GRID_SIZE][GRID_SIZE], int *score);
void moveRight(int grid[GRID_SIZE][GRID_SIZE], int *score);

#endif
