/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/12 23:20:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	show_double_tab(t_data_util *d);
int	key_hook(int keycode, t_vars *vars);
int	test(t_vars *vars);
int	test_2(t_vars *vars);

int	main(void)
{
	int				i;
	void			*mlx;
	void			*mlx_win;
	t_data_mlximg	img;
	t_data_util		d;

	setup_struct(&d);
	d.win_widht = 1480;
	d.win_height = 920;
	d.square_size = 1;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, d.win_widht, d.win_height, "fdf");
	img.img = mlx_new_image(mlx, d.win_widht, d.win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

////Background
	for (int x = 0; x < d.win_widht; x++)
	{
		for (int y = 0; y < d.win_height; y++)
		{
			if (y * y < ((d.win_widht - x) * ((d.win_widht - y) - x)))
				my_mlx_pixel_put(&img, x, y, 0x001d1e20 / ((y + 90) * (x + 90)) + 20);
			else
				my_mlx_pixel_put(&img, x, y, (0x001d1e20 / ((d.win_height - y + 90) * ( d.win_widht - x + 90))) + 20);
		}
	}
////

	if (setup_tab(&d, "mlx_util/maps/test_maps/julia.fdf"))
		return (1);


////Square size
//	printf("widht = %d  height = %d ", d.tab_widht, d.tab_height);
//	if (d.win_widht > d.tab_height)
//		d.square_size = d.win_widht / (d.tab_widht * 2);
//	else
//		d.square_size = d.win_height / (d.tab_height * 2);
//	printf("square = %d\n", d.square_size);
////


//	show_double_tab(&d);
	rotate_all(&d, mlx, mlx_win, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

////////
////
	t_vars	vars;

	vars.mlx = mlx;
	vars.win = mlx_win;
	vars.img = img.img;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0L, test, &vars);
	mlx_loop_hook(mlx, test_2, &vars);
////
////////

	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);

	i = 0;
	while (i < d.win_height)
		free(d.tab_hw[i++]);
	free(d.tab_hw);
	i = 0;
	while (i < d.win_height)
		free(d.tab_color[i++]);
	free(d.tab_color);

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
			printf("%d ", d->tab_hw[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	if (keycode == 53)
	{
		printf("Close fdf\n");
		mlx_destroy_image(vars->mlx, vars->img);
		exit (0);	
	}
	return (0);
}

int	test(t_vars *vars)
{
	printf("Close fdf\n");
	mlx_destroy_image(vars->mlx, vars->img);
	exit (0);
	return (0);
}

int	test_2(t_vars *vars)
{
//	printf("new image\n");
	return (0);
}
