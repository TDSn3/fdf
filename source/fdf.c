/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/26 14:35:19 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

#define L 1480
#define H 920
#define SQUARE_X 30

int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_data_mlximg	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, L, H, "test");
	img.img = mlx_new_image(mlx, L, H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int			fd;
	char		*str;
	const char	*pathname = "mlx_util/maps/test_maps/plat.fdf";

	fd = open(pathname, O_RDWR);
	str = get_next_line(fd);
	ft_printf("|%s", str);
	free(str);
	close(fd);

	rotate_all(1480, 920, 30, mlx, mlx_win, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);

	return (0);
}
