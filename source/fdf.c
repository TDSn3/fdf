/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 19:56:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	red_button(t_data_util *d);
int	gen_new_img(t_data_util *d);

int	main(int argc, char **argv)
{
	t_data_mlximg	img;
	t_data_util		d;

	if (check_error(argc, argv))
		return (1);
	setup_struct(&d);
	img.img = NULL;
	d.img = &img;
	if (setup_tab(&d, argv[1]))
	{
		free_all(&d);
		return (1);
	}
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.win_widht, d.win_height, "fdf");
	mlx_key_hook(d.win, key_hook, &d);
	mlx_hook(d.win, 17, 0L, red_button, &d);
	mlx_loop_hook(d.mlx, gen_new_img, &d);
	mlx_loop(d.mlx);
	free_all(&d);
	return (0);
}

int	red_button(t_data_util *d)
{
	if (d->img->img)
		mlx_destroy_image(d->mlx, d->img->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	free_all(d);
	exit (0);
	return (0);
}

int	gen_new_img(t_data_util *d)
{
	d->img->img = mlx_new_image(d->mlx, d->win_widht, d->win_height);
	d->img->addr = mlx_get_data_addr(d->img->img,
			&d->img->bits_per_pixel,
			&d->img->line_length,
			&d->img->endian);
	put_background(d);
	if (d->rotation < 90 && d->rotation > -91)
		rotate_all(d);
	else
		rotate_all_rev(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img->img);
	d->img->img = NULL;
	return (0);
}
