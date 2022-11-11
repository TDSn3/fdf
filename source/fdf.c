/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/11 18:34:12 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	show_double_tab(t_data_util *d);

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
	d.square_size = 10;
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

	if (setup_tab(&d, "mlx_util/maps/test_maps/42.fdf"))
		return (1);


////Square size
	printf("widht = %d  height = %d ", d.tab_widht, d.tab_height);
	if (d.win_widht > d.tab_height)
		d.square_size = d.win_widht / (d.tab_widht * 2);
	else
		d.square_size = d.win_height / (d.tab_height * 2);
	printf("square = %d\n", d.square_size);
////


	show_double_tab(&d);
	rotate_all(&d, mlx, mlx_win, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
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

void	show_double_tab(t_data_util *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < d->tab_height)
	{
		while (j < d->tab_widht)
		{
//			printf("%d ", d->tab_hw[i][j]);
			j++;
		}
//		printf("\n");
		j = 0;
		i++;
//		exit (1);
	}
}
