/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/15 18:52:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	show_double_tab(t_data_util *d);
int	key_hook(int keycode, t_data_util *d);
int	test(t_data_util *d);
int	gen_new_img(t_data_util *d);

int	main(void)
{
	int				i;
	t_data_mlximg	img;
	t_data_util		d;

	setup_struct(&d);
	d.win_widht = 1480;
	d.win_height = 920;
	d.square_size = 42;
	img.img = NULL;
	d.img = &img;
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.win_widht, d.win_height, "fdf");
	if (setup_tab(&d, "mlx_util/maps/test_maps/julia.fdf"))
		return (1);

//Square size
	ft_printf("widht = %d  height = %d ", d.tab_widht, d.tab_height);
	if (d.win_widht > d.tab_height)
		d.square_size = d.win_widht / (d.tab_widht * 2);
	else
		d.square_size = d.win_height / (d.tab_height * 2);
	printf("square = %d\n", d.square_size);
//

////////
////

	mlx_key_hook(d.win, key_hook, &d);
	mlx_hook(d.win, 17, 0L, test, &d);
	mlx_loop_hook(d.mlx, gen_new_img, &d);

////
////////
	mlx_loop(d.mlx);

	printf("final all_free\n");
	free_all(&d);

	return (0);
}

int	key_hook(int keycode, t_data_util *d)
{
	printf("%d\n", keycode);
	if (keycode == 53 || keycode == 65307)
	{
		printf("Close fdf - esc\n");
		if (d->img->img)
			mlx_destroy_image(d->mlx, d->img->img);
		mlx_destroy_window(d->mlx, d->win);
		mlx_destroy_display(d->mlx);
		free(d->mlx);
		free_all(d);
		exit (0);	
	}
	if (keycode == 112)
	{
		printf("P - plus, square size +1\n");
		d->square_size += 1;
	}
	if (keycode == 109)
	{
		printf("M - minus, square size -1\n");
		if (d->square_size > 1)
			d->square_size -= 1;
		else
			printf("STOP - Smallest size reached\n");
	}
	if (keycode == 111)
	{
		printf("O - plus2, point size +1\n");
		d->h_point += 1;
	}
	if (keycode == 110)
	{
		printf("N - minus2, point height -1\n");
		if (d->h_point > 0)
			d->h_point -= 1;
		else
			printf("STOP - Smallest size reached\n");
	}
	if (keycode == 65361)
	{
		printf("left\n");
		d->x_shift -= 20;
	}
	if (keycode == 65362)
	{
		printf("up\n");
		d->y_shift -= 20;
	}
	if (keycode == 65363)
	{
		printf("right\n");
		d->x_shift += 20;
	}
	if (keycode == 65364)
	{
		printf("down\n");
		d->y_shift += 20;
	}
	if (keycode == 97)
	{
		printf("A - rotation -1\n");
		d->rotation -= 1;
	}
	if (keycode == 100)
	{
		printf("D - rotation +1\n");
		d->rotation += 1;
	}
	if (keycode == 114)
	{
		printf("R - reset\n");
		d->rotation = 45;
		d->x_shift = 0;
		d->y_shift = 0;
		d->h_point = 2;
//Square size
		ft_printf("widht = %d  height = %d ", d->tab_widht, d->tab_height);
		if (d->win_widht > d->tab_height)
			d->square_size = d->win_widht / (d->tab_widht * 2);
		else
			d->square_size = d->win_height / (d->tab_height * 2);
		printf("square = %d\n", d->square_size);
//
	}
	return (0);
}

int	test(t_data_util *d)
{
	printf("Close fdf - red button\n");
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
	if (d->img->img == NULL)
		printf("new image\n");
	d->img->img = mlx_new_image(d->mlx, d->win_widht, d->win_height);
	d->img->addr = mlx_get_data_addr(d->img->img, &d->img->bits_per_pixel, &d->img->line_length, &d->img->endian);
	put_background(d);
	rotate_all(d, d->mlx, d->win, d->img);
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	mlx_destroy_image(d->mlx, d->img->img);
	d->img->img = NULL;
	return (0);
}
