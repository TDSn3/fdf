/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:36:15 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 12:21:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	part_two(int keycode, t_data_util *d);
static void	part_three(int keycode, t_data_util *d);

int	key_hook(int keycode, t_data_util *d)
{
	if (keycode == 112 || keycode == 35)
		d->square_size += 1;
	if ((keycode == 109 || keycode == 46) && d->square_size > 1)
		d->square_size -= 1;
	if (keycode == 111 || keycode == 31)
		d->h_point += 1;
	if (keycode == 110 || keycode == 45)
		d->h_point -= 1;
	if (keycode == 65363 || keycode == 124)
		d->x_shift -= 20;
	if (keycode == 65361 || keycode == 123)
		d->x_shift += 20;
	part_two(keycode, d);
	part_three(keycode, d);
	return (0);
}

static void	part_two(int keycode, t_data_util *d)
{
	if (keycode == 115 || keycode == 13)
		d->projection += 0.01;
	if (keycode == 113 || keycode == 12)
		d->projection = 0;
	if (keycode == 122 || keycode == 6)
		d->projection = 1;
	if (keycode == 114 || keycode == 15)
	{
		d->rotation = 45;
		d->x_shift = 0;
		d->y_shift = 0;
		d->h_point = 2;
		d->projection = 0.42;
		square_size(d);
	}
	if (keycode == 53 || keycode == 65307)
	{
		if (d->img->img)
			mlx_destroy_image(d->mlx, d->img->img);
		mlx_destroy_window(d->mlx, d->win);
//		mlx_destroy_display(d->mlx);
		free(d->mlx);
		free_all(d);
		exit (0);
	}
}

static void	part_three(int keycode, t_data_util *d)
{
	if (keycode == 65364 || keycode == 125)
		d->y_shift -= 20;
	if (keycode == 65362 || keycode == 126)
		d->y_shift += 20;
	if ((keycode == 97 || keycode == 0) && d->rotation <= -180)
		d->rotation = 180;
	else if (keycode == 97 || keycode == 0)
		d->rotation -= 5;
	if ((keycode == 100 || keycode == 2) && d->rotation >= 180)
		d->rotation = -180;
	else if (keycode == 100 || keycode == 2)
		d->rotation += 5;
	if (keycode == 119 || keycode == 1)
		d->projection -= 0.01;
}
