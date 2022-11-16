/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/16 15:15:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	rotate_all(t_data_util *d)
{
	int i = 0;
	int j = 0;
	float w = d->tab_widht;
	float h = d->tab_height;
	int	win_h_div = ((float)(d->win_height) / 2) + 0.5;
	int	win_w_div = ((float)(d->win_widht) / 2) + 0.5;
	int	x_o;
	int	y_o;
	int	x_next;
	int	y_next;
	i = 0;
	j = 0;
	while (i < h)
	{
		while (j < w)
		{
			x_o = win_h_div - (((h / 2) + 0.5) * d->square_size) + (i * d->square_size);
			y_o = win_w_div - (((w / 2) + 0.5) * d->square_size) + (j * d->square_size);
			x_next = win_h_div - (((h / 2) + 0.5) * d->square_size) + ((i + 1) * d->square_size);
			y_next = win_w_div - (((w / 2) + 0.5) * d->square_size) + ((j + 1) * d->square_size);
			
			d->pos_x[i][j] = rotate_pixel_x(win_h_div,	win_w_div,	x_o, 	y_o, d, i, j),
			d->pos_y[i][j] = rotate_pixel_y(win_h_div,	win_w_div,	x_o, 	y_o, d, i, j),
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	j = 0;
	while (i < h)
	{
		while (j < w)
		{
			if (i + 1 < h)
				line_put(d->pos_x[i][j] + d->square_size,
						 d->pos_y[i][j],
						 d->pos_x[i + 1][j] + d->square_size,
						 d->pos_y[i + 1][j],
						 d, i, j, i + 1, j);
			if (j + 1 < w)
				line_put(d->pos_x[i][j] + d->square_size,
						 d->pos_y[i][j],
						 d->pos_x[i][j + 1] + d->square_size,
						 d->pos_y[i][j + 1],
						 d, i, j, i, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
	
}
