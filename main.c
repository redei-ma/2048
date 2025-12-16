#include "game.h"
// #include "libft/include/libft.h"
// #include <ncurses.h>
// #include <stdlib.h>
// #include <time.h>

// Function to initialize the empty grid
void initGrid(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int y = 0; y < GRID_SIZE; y++)
        for (int x = 0; x < GRID_SIZE; x++)
            grid[y][x] = 0;
}

// Function to add a random number (2 or 4) in an empty cell
void addRandomTile(int grid[GRID_SIZE][GRID_SIZE])
{
    int emptyCells[GRID_SIZE * GRID_SIZE][2];
    int count = 0;
    
    // Find all empty cells
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            if (grid[y][x] == 0)
            {
                emptyCells[count][0] = y;
                emptyCells[count][1] = x;
                count++;
            }
        }
    }
    
    // If there are empty cells, add a number
    if (count > 0)
    {
        int index = rand() % count;
        int value = (rand() % 10 < 9) ? 2 : 4;  // 90% probability of 2, 10% of 4
        grid[emptyCells[index][0]][emptyCells[index][1]] = value;
    }
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

/* static void	colorSample(void)
{
	int row = 15;
	short	pair = 0;
	for (int i = 2; i <= 2048; i *= 2)
	{
		pair = getPair(i);
		attron(COLOR_PAIR(pair));
		mvprintw(15 + i, 40, " %d ", i);
		attroff(COLOR_PAIR(pair));
	}
} */

int main()
{
    int grid[GRID_SIZE][GRID_SIZE];
    int score = 0;
    int ch;
    
    srand(time(NULL));
    
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);  // Hide the cursor
    start_color();
	init_colors();


    // Initialize the grid
    initGrid(grid);
    
    // Add two initial numbers
    addRandomTile(grid);
    addRandomTile(grid);
    
    // Game loop
    while (1)
    {
        printGrid(grid, score);
        ch = getch();
        
        switch (ch)
        {
            case KEY_UP:
                moveUp(grid, &score);
                break;
            case KEY_DOWN:
                moveDown(grid, &score);
                break;
            case KEY_LEFT:
                moveLeft(grid, &score);
                break;
            case KEY_RIGHT:
                moveRight(grid, &score);
                break;
            case 27:  // ESC
                endwin();
                ft_printf("\nThank you for playing! Final score: %d\n", score);
                return 0;
            default:
                continue;
        }
	
        // After each valid move, add a new number
        addRandomTile(grid);
        refresh();
    }
    
    endwin();
    return 0;
}

/* 
 *	TODO:
 *	Se non c'e nessun si muove niente non devo aggiungere un nuovo numero
 * 	Implementare la condizione di vittoria (2048)
 *  Implementare la condizione di sconfitta (nessuna mossa possibile)
 *  
 *	Mettere vecchia creazione nuemri random
 * 
*/