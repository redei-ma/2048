#include "game.h"

/* 
 *	PHASE 1: COMPRESS
 *	PHASE 2: MERGE
 *	PHASE 3: COMPRESS AGAIN
*/

// Compress a column upwards
static void compressColumnUp(int grid[GRID_SIZE][GRID_SIZE], int x)
{
    int writePos = 0;
    for (int y = 0; y < GRID_SIZE; y++)
    {
        if (grid[y][x] != 0)
        {
            grid[writePos][x] = grid[y][x];
            if (writePos != y)
                grid[y][x] = 0;
            writePos++;
        }
    }
}

// Move upwards
void moveUp(int grid[GRID_SIZE][GRID_SIZE], int *score)
{
    for (int x = 0; x < GRID_SIZE; x++)
        compressColumnUp(grid, x);
    
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
            }
        }
    }
    
    for (int x = 0; x < GRID_SIZE; x++)
        compressColumnUp(grid, x);
}

// Compress a column downwards
static void compressColumnDown(int grid[GRID_SIZE][GRID_SIZE], int x)
{
    int writePos = GRID_SIZE - 1;
    for (int y = GRID_SIZE - 1; y >= 0; y--)
    {
        if (grid[y][x] != 0)
        {
            grid[writePos][x] = grid[y][x];
            if (writePos != y)
                grid[y][x] = 0;
            writePos--;
        }
    }
}

// Move downwards
void moveDown(int grid[GRID_SIZE][GRID_SIZE], int *score)
{
    for (int x = 0; x < GRID_SIZE; x++)
        compressColumnDown(grid, x);
    
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
            }
        }
    }
    
    for (int x = 0; x < GRID_SIZE; x++)
        compressColumnDown(grid, x);
}

// Compress a row to the left
static void compressRowLeft(int grid[GRID_SIZE][GRID_SIZE], int y)
{
    int writePos = 0;
    for (int x = 0; x < GRID_SIZE; x++)
    {
        if (grid[y][x] != 0)
        {
            grid[y][writePos] = grid[y][x];
            if (writePos != x)
                grid[y][x] = 0;
            writePos++;
        }
    }
}

// Move left
void moveLeft(int grid[GRID_SIZE][GRID_SIZE], int *score)
{
    for (int y = 0; y < GRID_SIZE; y++)
        compressRowLeft(grid, y);
    
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
            }
        }
    }
    
    for (int y = 0; y < GRID_SIZE; y++)
        compressRowLeft(grid, y);
}

// Compress a row to the right
static void compressRowRight(int grid[GRID_SIZE][GRID_SIZE], int y)
{
    int writePos = GRID_SIZE - 1;
    for (int x = GRID_SIZE - 1; x >= 0; x--)
    {
        if (grid[y][x] != 0)
        {
            grid[y][writePos] = grid[y][x];
            if (writePos != x)
                grid[y][x] = 0;
            writePos--;
        }
    }
}

// Move right
void moveRight(int grid[GRID_SIZE][GRID_SIZE], int *score)
{
    for (int y = 0; y < GRID_SIZE; y++)
        compressRowRight(grid, y);
    
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
            }
        }
    }
    
    for (int y = 0; y < GRID_SIZE; y++)
        compressRowRight(grid, y);
}
