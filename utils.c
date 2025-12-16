#include "game.h"

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return (0);

    while (n > 1)
    {
        if (n % 2 != 0)
            return (0);
        
        n = n / 2;
    }
    return (1);
}

// Function to initialize the empty grid
void initGrid(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int y = 0; y < GRID_SIZE; y++)
        for (int x = 0; x < GRID_SIZE; x++)
            grid[y][x] = 0;
}

// Function to check if there is any free space in the grid
bool freeSpace(int grid[GRID_SIZE][GRID_SIZE])
{
	for (int y = 0; y < GRID_SIZE; y++)
	{
		for (int x = 0; x < GRID_SIZE; x++)
		{
			if (grid[y][x] == 0)
				return true;
		}
	}
	return false;
}

// Function to add a random number (2 or 4) in an empty cell
void addNewNumber(int grid[GRID_SIZE][GRID_SIZE])
{
	if (!freeSpace(grid))
		return;

	int newNumber = 2;
	if (rand() % 10 == 0)
		newNumber = 4;

	int posX = rand() % GRID_SIZE;
	int posY = rand() % GRID_SIZE;
	while (grid[posX][posY] != 0)
	{
		posX = rand() % GRID_SIZE;
		posY = rand() % GRID_SIZE;
	}

	grid[posX][posY] = newNumber;
}

bool canMove(int grid[GRID_SIZE][GRID_SIZE])
{
	// Check horizontal moves
	for (int y = 0; y < GRID_SIZE; y++)
	{
		for (int x = 0; x < GRID_SIZE - 1; x++)
		{
			if (grid[y][x] == grid[y][x + 1])
				return true;
		}
	}
	
	// Check vertical moves
	for (int x = 0; x < GRID_SIZE; x++)
	{
		for (int y = 0; y < GRID_SIZE - 1; y++)
		{
			if (grid[y][x] == grid[y + 1][x])
				return true;
		}
	}
	
	return false;
}

bool hasWon(int grid[GRID_SIZE][GRID_SIZE])
{
	for (int y = 0; y < GRID_SIZE; y++)
	{
		for (int x = 0; x < GRID_SIZE; x++)
		{
			if (grid[y][x] == WIN_VALUE)
				return true;
		}
	}
	return false;
}

void closeGame(int score)
{
	endwin();
	ft_printf("Thank you for playing! Final score: %d\n", score);
}