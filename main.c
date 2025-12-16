#include "game.h"

int main()
{
	if (!isPowerOfTwo(WIN_VALUE) && WIN_VALUE < INT_MAX)
	{
		ft_printf("Error: WIN_VALUE (%d) is not a power of two.\n", WIN_VALUE);
		return 1;
	}

    int grid[GRID_SIZE][GRID_SIZE];
    int score = 0;
    int ch;
	bool alreadyWon = false;
    
    srand(time(NULL));
    
    // Initialize ncurses
	initscr();				//Avvia la modalità ncurses
	mousemask(ALL_MOUSE_EVENTS, NULL);
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
			clrtoeol();
			mvprintw(GRID_SIZE * 2 + 6, 0, "Press any key to exit.");
			clrtoeol();
			getch();
			closeGame(score);
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
			case KEY_MOUSE:
				continue;
            case 27:  // ESC
                closeGame(score);
                return 0;
            default:
                continue;
        }

		if (!moved) continue;

		// Check for win condition
		if (hasWon(grid) && !alreadyWon)
		{
			alreadyWon = true;
			printGrid(grid, score);
			mvprintw(GRID_SIZE * 2 + 5, 0, "You won! Score: %d.", score);
			clrtoeol();
			mvprintw(GRID_SIZE * 2 + 6, 0, "Press any key to continue or ESC to exit.");
			clrtoeol();
			ch = getch();
			if (ch == 27)
			{
				closeGame(score);
				break;
			}
		}
        // After each valid move, add a new number
		addNewNumber(grid);
        refresh();
    }
    
    endwin();
    return 0;
}
