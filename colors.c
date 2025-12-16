/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:37:20 by cacorrea          #+#    #+#             */
/*   Updated: 2025/12/16 13:47:22 by cacorrea         ###   ########.fr       */
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
