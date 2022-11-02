/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/02 17:42:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	rotate_all(t_data_util *d, void *mlx, void *mlx_win, t_data_mlximg *img)
{
	int i = 0;
	int j = 0;
	float tabX = d->tab_height;
	float tabY = d->tab_widht;
	printf("tab_height = %d, tab_widht = %d\n", d->tab_height,d->tab_widht);

	while (i < tabX)
	{
		while (j < tabY)
		{
			if (i + 1 < tabX)
				line_put(rotate_pixel_x(d->win_widht / 2,	d->win_height / 2, 	(d->win_widht /2 - ((tabX / 2) * d->square_size) + (i * d->square_size)), 		(d->win_height /2 - ((tabY / 2) * d->square_size) + (j * d->square_size))) + (d->square_size / 2),
						 rotate_pixel_y(d->win_widht / 2,	d->win_height / 2, 	(d->win_widht /2 - ((tabX / 2) * d->square_size) + (i * d->square_size)), 		(d->win_height /2 - ((tabY / 2) * d->square_size) + (j * d->square_size)), d, i, j),
						 rotate_pixel_x(d->win_widht / 2,	d->win_height / 2, 	d->win_widht /2 - ((tabX / 2) * d->square_size) + ((i + 1) * d->square_size), 	d->win_height /2 - ((tabY / 2) * d->square_size) + (j * d->square_size)) + (d->square_size / 2),
						 rotate_pixel_y(d->win_widht / 2,	d->win_height / 2, 	d->win_widht /2 - ((tabX / 2) * d->square_size) + ((i + 1) * d->square_size), 	d->win_height /2 - ((tabY / 2) * d->square_size) + (j * d->square_size),d , i + 1, j),
						 mlx, mlx_win, img, d, i, j, i + 1, j);
			if (j + 1 < tabY)
				line_put(rotate_pixel_x(d->win_widht / 2, d->win_height / 2, 	(d->win_widht /2 - ((tabX / 2) * d->square_size) + (i * d->square_size)), 		(d->win_height /2 - ((tabY / 2) * d->square_size) + (j * d->square_size))) + (d->square_size / 2),
						 rotate_pixel_y(d->win_widht / 2, d->win_height / 2, 	(d->win_widht /2 - ((tabX / 2) * d->square_size) + (i * d->square_size)), 		(d->win_height /2 - ((tabY / 2) * d->square_size) + (j * d->square_size)),d, i, j),
						 rotate_pixel_x(d->win_widht / 2, d->win_height / 2, 	(d->win_widht /2 - ((tabX / 2) * d->square_size) + (i * d->square_size)), 		d->win_height /2 - ((tabY / 2) * d->square_size) + ((j + 1) * d->square_size)) + (d->square_size / 2),
						 rotate_pixel_y(d->win_widht / 2, d->win_height / 2, 	(d->win_widht /2 - ((tabX / 2) * d->square_size) + (i * d->square_size)), 		d->win_height /2 - ((tabY / 2) * d->square_size) + ((j + 1) * d->square_size),d, i, j + 1),
						 mlx, mlx_win, img, d, i, j, i, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
}
