#ifndef GAME_H
# define GAME_H

# include "libft/include/libft.h"
# include <ncurses.h>
# include <stdlib.h>
# include <time.h>

enum e_const
{
	WIN_VALUE = 2048,
	GRID_SIZE = 4
};

enum
{
	C2 = 10,
	C4 = 11,
	C8 = 12,
	C16 = 13,
	C32= 14,
	C64 = 15,
	C128 = 16,
	C256 = 17,
	C512 = 18,
	C1024 = 19,
	C2048 = 20
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

void	moveUp(int grid[GRID_SIZE][GRID_SIZE], int *score);
void	moveDown(int grid[GRID_SIZE][GRID_SIZE], int *score);
void	moveLeft(int grid[GRID_SIZE][GRID_SIZE], int *score);
void	moveRight(int grid[GRID_SIZE][GRID_SIZE], int *score);
void	init_colors(void);

#endif
