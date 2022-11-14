/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/14 17:12:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	show_double_tab(t_data_util *d);
int	key_hook(int keycode, t_data_util *d);
int	test(t_data_util *d);
int	test_2(t_data_util *d);
void	free_all(t_data_util *d);

int	main(void)
{
	int				i;
	t_data_mlximg	img;
	t_data_util		d;

//	setup_struct(&d);
	d.win_widht = 1480;
	d.win_height = 920;
	d.square_size = 42;
	img.img = NULL;
	d.img = &img;
	d.mlx = mlx_init();
	d.win = mlx_new_window(d.mlx, d.win_widht, d.win_height, "fdf");
	d.img->img = mlx_new_image(d.mlx, d.win_widht, d.win_height);
	d.img->addr = mlx_get_data_addr(d.img->img, &d.img->bits_per_pixel, &d.img->line_length, &d.img->endian);

	if (setup_tab(&d, "mlx_util/maps/test_maps/42.fdf"))
		return (1);

//Square size
//	printf("widht = %d  height = %d ", d.tab_widht, d.tab_height);
//	if (d.win_widht > d.tab_height)
//		d.square_size = d.win_widht / (d.tab_widht * 2);
//	else
//		d.square_size = d.win_height / (d.tab_height * 2);
//	printf("square = %d\n", d.square_size);
//

////////
////

	mlx_key_hook(d.win, key_hook, &d);
	mlx_hook(d.win, 17, 0L, test, &d);
//	mlx_loop_hook(d.mlx, test_2, &d);

////
////////

	mlx_loop(d.mlx);

	printf("final all_free\n");
	free_all(&d);

	return (0);
}

static void	show_double_tab(t_data_util *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < d->tab_height)
	{
		while (j < d->tab_widht)
		{
			printf("%d ", d->tab_color[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

int	key_hook(int keycode, t_data_util *d)
{
	printf("%d\n", keycode);
	if (keycode == 53 || keycode == 65307)
	{
		printf("Close fdf - esc\n");
		mlx_destroy_image(d->mlx, d->img->img);
		mlx_destroy_window(d->mlx, d->win);
		mlx_destroy_display(d->mlx);
		free(d->mlx);
		free_all(d);
		exit (0);	
	}
	return (0);
}

int	test(t_data_util *d)
{
	printf("Close fdf - red button\n");
	mlx_destroy_image(d->mlx, d->img->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	free_all(d);
	exit (0);
	return (0);
}

int	test_2(t_data_util *d)
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
	usleep(1000000);
	return (0);
}

void	free_all(t_data_util *d)
{
	int i;

	i = 0;
//	if (d->tab_hw)
//	{
//		while (i < d->tab_height)
//			free(d->tab_hw[i++]);
//		free(d->tab_hw);
//	}
//	i = 0;
//	if (d->tab_color)
//	{
//		while (i < d->tab_height)
//			free(d->tab_color[i++]);
//		free(d->tab_color);
//	}
//	i = 0;
//	if (d->pos_x)
//	{
//		while (i < d->tab_height)
//			free(d->pos_x[i++]);
//		free(d->pos_x);
//	}
//		i = 0;
//	if (d->pos_y)
//	{
//		while (i < d->tab_height)
//			free(d->pos_y[i++]);
//		free(d->pos_y);
//	}
//	if (d->li_color)
//	{
//		printf("li_color clear\n");
//		li_clear(&d->li_color);
//	}
}