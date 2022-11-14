/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:08:34 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/14 13:28:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

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
			if (y * y < ((d->win_widht - x) * ((d->win_widht - y) - x)))
				my_mlx_pixel_put(d->img, x, y, 0x001d1e20 / ((y + 90) * (x + 90)) + 20);
			else
				my_mlx_pixel_put(d->img, x, y, (0x001d1e20 / ((d->win_height - y + 90) * ( d->win_widht - x + 90))) + 20);
			y++;
		}
		y = 0;
		x++;
	}
}
