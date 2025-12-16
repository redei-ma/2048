#include "game.h"

/* 
 *	PHASE 1: COMPRESS
 *	PHASE 2: MERGE
 *	PHASE 3: COMPRESS AGAIN
*/

// Compress a column upwards
static bool compressColumnUp(int grid[GRID_SIZE][GRID_SIZE], int x)
{
	bool moved = false;
    int writePos = 0;
    for (int y = 0; y < GRID_SIZE; y++)
    {
        if (grid[y][x] != 0)
        {
            grid[writePos][x] = grid[y][x];
            if (writePos != y)
			{
                grid[y][x] = 0;
				moved = true;
			}
            writePos++;
        }
    }
	return moved;
}

// Move upwards
bool moveUp(int grid[GRID_SIZE][GRID_SIZE], int *score)
{
	bool moved = false;

    for (int x = 0; x < GRID_SIZE; x++)
	{
		if (compressColumnUp(grid, x))
			moved = true;
	}
    
    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int y = 0; y < GRID_SIZE - 1; y++)
        {
            if (grid[y][x] != 0 && grid[y][x] == grid[y+1][x])
            {
                grid[y][x] *= 2;
                *score += grid[y][x];
                grid[y+1][x] = 0;
                y++;
				moved = true;
            }
        }
    }
    
    for (int x = 0; x < GRID_SIZE; x++)
	{
		if (compressColumnUp(grid, x))
			moved = true;
	}

	return moved;
}

// Compress a column downwards
static bool compressColumnDown(int grid[GRID_SIZE][GRID_SIZE], int x)
{
	bool moved = false;
    int writePos = GRID_SIZE - 1;
    for (int y = GRID_SIZE - 1; y >= 0; y--)
    {
        if (grid[y][x] != 0)
        {
            grid[writePos][x] = grid[y][x];
            if (writePos != y)
			{
                grid[y][x] = 0;
				moved = true;
			}
            writePos--;
        }
    }
	return moved;
}

// Move downwards
bool moveDown(int grid[GRID_SIZE][GRID_SIZE], int *score)
{
	bool moved = false;

    for (int x = 0; x < GRID_SIZE; x++)
	{
		if (compressColumnDown(grid, x))
			moved = true;
	}
    
    for (int x = 0; x < GRID_SIZE; x++)
    {
        for (int y = GRID_SIZE - 1; y > 0; y--)
        {
            if (grid[y][x] != 0 && grid[y][x] == grid[y-1][x])
            {
                grid[y][x] *= 2;
                *score += grid[y][x];
                grid[y-1][x] = 0;
                y--;
				moved = true;
            }
        }
    }
    
    for (int x = 0; x < GRID_SIZE; x++)
	{
		if (compressColumnDown(grid, x))
			moved = true;
	}
	
	return moved;
}

// Compress a row to the left
static bool compressRowLeft(int grid[GRID_SIZE][GRID_SIZE], int y)
{
	bool moved = false;
    int writePos = 0;
    for (int x = 0; x < GRID_SIZE; x++)
    {
        if (grid[y][x] != 0)
        {
            grid[y][writePos] = grid[y][x];
            if (writePos != x)
			{
                grid[y][x] = 0;
				moved = true;
			}
            writePos++;
        }
    }
	return moved;
}

// Move left
bool moveLeft(int grid[GRID_SIZE][GRID_SIZE], int *score)
{
	bool moved = false;

    for (int y = 0; y < GRID_SIZE; y++)
	{
		if (compressRowLeft(grid, y))
			moved = true;
	}
    
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE - 1; x++)
        {
            if (grid[y][x] != 0 && grid[y][x] == grid[y][x+1])
            {
                grid[y][x] *= 2;
                *score += grid[y][x];
                grid[y][x+1] = 0;
                x++;
				moved = true;
            }
        }
    }
    
    for (int y = 0; y < GRID_SIZE; y++)
	{
		if (compressRowLeft(grid, y))
			moved = true;
	}
	
	return moved;
}

// Compress a row to the right
static bool compressRowRight(int grid[GRID_SIZE][GRID_SIZE], int y)
{
	bool moved = false;
    int writePos = GRID_SIZE - 1;

    for (int x = GRID_SIZE - 1; x >= 0; x--)
    {
        if (grid[y][x] != 0)
        {
            grid[y][writePos] = grid[y][x];
            if (writePos != x)
			{
				grid[y][x] = 0;
				moved = true;
            }
            writePos--;
        }
    }
	return moved;
}

// Move right
bool moveRight(int grid[GRID_SIZE][GRID_SIZE], int *score)
{
	bool moved = false;

    for (int y = 0; y < GRID_SIZE; y++)
	{
        if (compressRowRight(grid, y))
			moved = true;
	}
    
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = GRID_SIZE - 1; x > 0; x--)
        {
            if (grid[y][x] != 0 && grid[y][x] == grid[y][x-1])
            {
                grid[y][x] *= 2;
                *score += grid[y][x];
                grid[y][x-1] = 0;
                x--;
				moved = true;
            }
        }
    }
    
    for (int y = 0; y < GRID_SIZE; y++)
	{
	if (compressRowRight(grid, y))
		moved = true;
	}
	
	return moved;
}
