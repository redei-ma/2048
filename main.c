#include "game.h"

int isPowerOfTwo(int n)
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
// funzionante
// static void printNumber(int nb, int y, int x)
// {
//     mvprintw(y, x, "+------+");
//     mvprintw(y + 1, x, "|");
// 	if (nb == 0)
// 		mvprintw(y + 1, x + 1, "      |");
// 	else
// 		mvprintw(y + 1, x + 1, " %4d |", nb);
//     mvprintw(y + 2, x, "+------+");
// }

static short	getPair(int nb)
{
	if (nb == 2)
		return (PAIR_2);
	else if (nb == 4)
		return (PAIR_4);
	else if (nb == 8)
		return (PAIR_8);
	else if (nb == 16)
		return (PAIR_16);
	else if (nb == 32)
		return (PAIR_32);
	else if (nb == 64)
		return (PAIR_64);
	else if (nb == 128)
		return (PAIR_128);
	else if (nb == 256)
		return (PAIR_256);
	else if (nb == 512)
		return (PAIR_512);
	else if (nb == 1024)
		return (PAIR_1024);
	else if (nb == 2048)
		return (PAIR_2048);
	else
		return (PAIR_DEF);
}

static void printNumber(int nb, int y, int x)
{
	short pair = getPair(nb);
    mvprintw(y, x, "+------+");
    mvprintw(y + 1, x, "|");
	mvprintw(y + 1, x + 1, "      |");

	if (nb != 0)
	{
		attron(COLOR_PAIR(pair));
		mvprintw(y + 1, x + 1, " %4d ", nb);
		attroff(COLOR_PAIR(pair));
	}
    mvprintw(y + 2, x, "+------+");
}

// Function to print the grid with ncurses
void printGrid(int grid[GRID_SIZE][GRID_SIZE], int score)
{
    clear();

    mvprintw(0, 0, "============== 2048 ==============");
    mvprintw(1, 0, "Score: %d", score);
    mvprintw(2, 0, "");
    
    int startY = 3;
    int startX = 2;
    
    /* for (int y = 0; y < GRID_SIZE; y++)
    {
        mvprintw(startY + y * 2, startX, "+------+------+------+------+");
        mvprintw(startY + y * 2 + 1, startX, "|");
        
        for (int x = 0; x < GRID_SIZE; x++)
        {
            if (grid[y][x] == 0)
                mvprintw(startY + y * 2 + 1, startX + 1 + x * 7, "      |");
            else
                mvprintw(startY + y * 2 + 1, startX + 1 + x * 7, " %4d |", grid[y][x]);
        }
    }
    mvprintw(startY + GRID_SIZE * 2, startX, "+------+------+------+------+"); */
	
	for (int y = 0; y < GRID_SIZE; y++)
	{        
        for (int x = 0; x < GRID_SIZE; x++)
			printNumber(grid[y][x], startY + y * 2, startX + 1 + x * 7);
    }

    mvprintw(startY + GRID_SIZE * 2 + 2, 0, "Use arrow keys to move, ESC to exit.");
    
    refresh();
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

int main()
{
	if (!isPowerOfTwo(WIN_VALUE))
	{
		ft_printf("Error: WIN_VALUE (%d) is not a power of two.\n", WIN_VALUE);
		return 1;
	}

    int grid[GRID_SIZE][GRID_SIZE];
    int score = 0;
    int ch;
    
    srand(time(NULL));
    
    // Initialize ncurses
	initscr();				//Avvia la modalità ncurses
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);  // Hide the cursor
    start_color();
	init_colors();

    // Initialize the grid
    initGrid(grid);
    
    // Add two initial numbers
    addNewNumber(grid);
	addNewNumber(grid);
    
    // Game loop
    while (1)
    {
        printGrid(grid, score);
		if (!freeSpace(grid) && !canMove(grid))
		{
			mvprintw(GRID_SIZE * 2 + 5, 0, "Game over! Final score: %d", score);
			mvprintw(GRID_SIZE * 2 + 6, 0, "Press any key to exit.");
			getch();
			break;
		}
		
        ch = getch();

		bool moved = false;

        switch (ch)
        {
            case KEY_UP:
                if (moveUp(grid, &score))
					moved = true;
                break;
            case KEY_DOWN:
                if (moveDown(grid, &score))
					moved = true;
                break;
            case KEY_LEFT:
                if (moveLeft(grid, &score))
					moved = true;
                break;
            case KEY_RIGHT:
                if (moveRight(grid, &score))
					moved = true;
                break;
            case 27:  // ESC
                endwin();
                ft_printf("\nThank you for playing! Final score: %d\n", score);
                return 0;
            default:
                continue;
        }
	
		if (!moved) continue;

		// Check for win condition
		if (moved && hasWon(grid))
		{
			printGrid(grid, score);
			mvprintw(GRID_SIZE * 2 + 5, 0, "You won! Score: %d.                  ", score);
			mvprintw(GRID_SIZE * 2 + 6, 0, "Press any key to continue or ESC to exit.");
			ch = getch();
			if (ch == 27)
				break;
		}
	
        // After each valid move, add a new number
		addNewNumber(grid);
        refresh();
    }
    
    endwin();
    return 0;
}

/* 
 *	TODO:
 * 	FAre in modo che venga stampata una solo volta YOU WIN quando si raggiunge WIN_VALUE
 *  
*/