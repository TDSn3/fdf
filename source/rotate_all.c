/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/03 10:26:48 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	rotate_all(t_data_util *d, void *mlx, void *mlx_win, t_data_mlximg *img)
{
	int i = 0;
	int j = 0;
	float w = d->tab_widht;
	float h = d->tab_height;
	printf("tab_height = %d, tab_widht = %d\n", d->tab_height,d->tab_widht);

	while (i < h)
	{
		while (j < w)
		{
			printf("[%d][%d] %d\n", i, j, d->tab_hw[i][j]);
			if (i + 1 < h)
				line_put(rotate_pixel_x(d->win_height / 2,	d->win_widht / 2, 	(d->win_height /2 - ((h / 2) * d->square_size) + (i * d->square_size)), 		   (d->win_widht /2 - ((w / 2) * d->square_size) + (j * d->square_size)), d, i, j),
						 rotate_pixel_y(d->win_height / 2,	d->win_widht / 2, 	(d->win_height /2 - ((h / 2) * d->square_size) + (i * d->square_size)), 		   (d->win_widht /2 - ((w / 2) * d->square_size) + (j * d->square_size)), d, i, j) + (d->square_size / 2),
						 rotate_pixel_x(d->win_height / 2,	d->win_widht / 2, 	 d->win_height /2 - ((h / 2) * d->square_size) + ((i + 1) * d->square_size),    	d->win_widht /2 - ((w / 2) * d->square_size) + (j * d->square_size),d , i + 1, j),
						 rotate_pixel_y(d->win_height / 2,	d->win_widht / 2, 	 d->win_height /2 - ((h / 2) * d->square_size) + ((i + 1) * d->square_size), 	    d->win_widht /2 - ((w / 2) * d->square_size) + (j * d->square_size),d , i + 1, j) + (d->square_size / 2),
						 mlx, mlx_win, img, d, i, j, i + 1, j);
			if (j + 1 < w)
				line_put(rotate_pixel_x(d->win_height / 2, d->win_widht / 2, 	(d->win_height /2 - ((h / 2) * d->square_size) + (i * d->square_size)), 		   (d->win_widht /2 - ((w / 2) * d->square_size) + (j * d->square_size)),d, i, j),
						 rotate_pixel_y(d->win_height / 2, d->win_widht / 2, 	(d->win_height /2 - ((h / 2) * d->square_size) + (i * d->square_size)), 		   (d->win_widht /2 - ((w / 2) * d->square_size) + (j * d->square_size)),d, i, j) + (d->square_size / 2),
						 rotate_pixel_x(d->win_height / 2, d->win_widht / 2, 	(d->win_height /2 - ((h / 2) * d->square_size) + (i * d->square_size)), 		    d->win_widht /2 - ((w / 2) * d->square_size) + ((j + 1) * d->square_size),d, i, j + 1),
						 rotate_pixel_y(d->win_height / 2, d->win_widht / 2, 	(d->win_height /2 - ((h / 2) * d->square_size) + (i * d->square_size)), 		    d->win_widht /2 - ((w / 2) * d->square_size) + ((j + 1) * d->square_size),d, i, j + 1) + (d->square_size / 2),
						 mlx, mlx_win, img, d, i, j, i, j + 1);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}
/*
	while (i < w)
	{
		while (j < h)
		{
			printf("%d %d\n", i, j);
			if (i + 1 < w)
				line_put(i * 10,
						 j* 10,
						 (i + 1) * 10,
						 j * 10,
						 mlx, mlx_win, img, d, i, j, i + 1, j);
			if (j + 1 < h)
				line_put(i* 10,
						 j* 10,
						 i * 10,
						 (j + 1) * 10,
						 mlx, mlx_win, img, d, i, j, i, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
*/
