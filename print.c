/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: redei-ma <redei-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:37:20 by cacorrea          #+#    #+#             */
/*   Updated: 2025/12/16 14:31:26 by redei-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_colors(void)
{
	if (has_colors() == FALSE)
	{
		ft_printf("The terminal does not support colors\n");
		return;
	}
	
	init_color(C2, 1000, 1000, 800);
	init_color(C4, 1000, 800, 600);
	init_color(C8, 1000, 600, 600);
	init_color(C16, 1000, 600, 200);
	init_color(C32, 1000, 400, 400);
	init_color(C64, 1000, 1000, 200);
	init_color(C128, 1000, 200, 200);
	init_color(C256, 1000, 1000, 0);
	init_color(C512, 1000, 400, 0);
	init_color(C1024, 1000, 0, 0);
	init_color(C2048, 0, 1000, 0);


	init_pair(PAIR_2, C2, COLOR_BLACK);
	init_pair(PAIR_4, C4, COLOR_BLACK);
	init_pair(PAIR_8, C8, COLOR_BLACK);
	init_pair(PAIR_16, C16, COLOR_BLACK);
	init_pair(PAIR_32, C32, COLOR_BLACK);
	init_pair(PAIR_64, C64, COLOR_BLACK);
	init_pair(PAIR_128, C128, COLOR_BLACK);
	init_pair(PAIR_256, C256, COLOR_BLACK);
	init_pair(PAIR_512, C512, COLOR_BLACK);
	init_pair(PAIR_1024, C1024, COLOR_BLACK);
	init_pair(PAIR_2048, C2048, COLOR_BLACK);
	init_pair(PAIR_DEF, COLOR_WHITE, COLOR_BLACK);
}

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
    
	for (int y = 0; y < GRID_SIZE; y++)
	{        
        for (int x = 0; x < GRID_SIZE; x++)
			printNumber(grid[y][x], startY + y * 2, startX + 1 + x * 7);
    }

    mvprintw(startY + GRID_SIZE * 2 + 2, 0, "Use arrow keys to move, ESC to exit.");
    
    refresh();
}
