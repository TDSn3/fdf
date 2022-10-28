/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/28 10:01:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

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

////

	int			fd;
	char		*str;
	char		**tab_hw;
	char		**tab_color;
	int			height = 0;
	int			i = 0;
	const char	*pathname = "mlx_util/maps/test_maps/plat.fdf";

	fd = open(pathname, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (1);
	}
	str = get_next_line(fd);
	printf("width = %d\n", width_tab(str));
	while (str)
	{
		height++;
		printf("%s", str);
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	printf("\nheight = %d\n", height);
	close(fd);

	tab_hw = malloc(height * sizeof(int));
	tab_color = malloc(height * sizeof(int));
	if (!tab_hw || !tab_color)
		return (1);
	while (i < height)
	{
		tab_hw[i] = malloc(height * sizeof(int));
		tab_color[i] = malloc(height * sizeof(int));	
		if (!tab_hw[i] || !tab_color[i])
			return (1);	
		i++;
	}

	--> remplire les tableaux

////

	rotate_all(1480, 920, 30, mlx, mlx_win, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);

	return (0);
}
