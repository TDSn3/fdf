/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:08:34 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/16 17:53:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	content_while(t_data_util *d, int x, int y);

void	put_background(t_data_util *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < d->win_widht)
	{
		while (y < d->win_height)
		{
			content_while(d, x, y);
			y++;
		}
		y = 0;
		x++;
	}
}

static void	content_while(t_data_util *d, int x, int y)
{
	int	stock;
	int	stock_two;

	stock = 0;
	stock_two = 0;
	if (y * y < ((d->win_widht - x) * ((d->win_widht - y) - x)))
	{
		stock = 0x001d1e20 / ((y + 90) * (x + 90)) + 20;
		my_mlx_pixel_put(d->img, x, y, stock);
	}
	else
	{
		stock = ((d->win_height - y + 90) * (d->win_widht - x + 90));
		stock_two = (0x001d1e20 / stock) + 20;
		my_mlx_pixel_put(d->img, x, y, stock_two);
	}
}
