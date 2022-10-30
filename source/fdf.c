/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/30 15:13:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_data_mlximg	img;
	t_data_util		d;

	setup_struct(&d);
	d.win_widht = 1480;
	d.win_height = 920;
	d.square_size = 30;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, d.win_widht, d.win_height, "test");
	img.img = mlx_new_image(mlx, d.win_widht, d.win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

////

	int			fd;
	char		*str;
	int			**tab_hw;
	int			**tab_color;
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
	int widht = width_tab(str);
	printf("width = %d\n", widht);
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

	tab_hw = malloc(height * sizeof(int*));
	if (!tab_hw)
		return (1);
	while (i < height)
	{
		tab_hw[i] = malloc(widht * sizeof(int));
		if (!tab_hw[i])
			return (1);	
		i++;
	}
	
	i = 0;
	tab_color = malloc(height * sizeof(int*));
	if (!tab_color)
		return (1);
	while (i < height)
	{
		tab_color[i] = malloc(widht * sizeof(int));
		if (!tab_color[i])
			return (1);	
		i++;
	}

	int x_tab = 0;
	int y_tab = 0;

	int x_str = 0;
	int	j = 0;

	fd = open(pathname, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (1);
	}
	str = get_next_line(fd);
	while (str && y_tab < height)
	{
		printf("%s", str);
		while (x_tab < widht && str[x_str])
		{
			printf("[%d] [%d] = %c\n",y_tab, x_str, str[x_str]);
			if (str[x_str] && ((str[x_str] >= '0' && str[x_str] <= '9') || str[x_str] == '-'))
			{
				printf("str + %d = %d\n", x_str, ft_atoi(str + x_str));	
				tab_hw[y_tab][x_tab] = ft_atoi(str + x_str);
				tab_color[y_tab][x_tab] = 0x00FFFFFF;
				printf("\ttab[%d][%d] = %d\n", y_tab, x_tab, tab_hw[y_tab][x_tab]);
				while (str[x_str] && ((str[x_str] >= '0' && str[x_str] <= '9') || str[x_str] == '-' || str[x_str] == ','))
				{
					if (str[x_str] == ',')
					{
						tab_color[y_tab][x_tab] = my_atoi_hex(str + x_str + 1);
						x_str++;
						while (j < 8 && str[x_str])
						{
							if ((str[x_str] >= '0' && str[x_str] <= '9') || str[x_str] <= 'x')
								j++;
							else if (str[x_str] >= 'A' && str[x_str] <= 'F')
								j++;
							else if (str[x_str] >= 'a' && str[x_str] <= 'f')
								j++;
							else
								break;
							x_str++;
						}
						continue;
					}
					x_str++;
				}
				x_tab++;
				continue;
			}
			x_str++;
		}
		printf("\n");

		for(int yy = 0; yy < height; yy++)
		{
			for (int xx = 0; xx < widht; xx++)
			{
				printf("%d ", tab_hw[yy][xx]);
			}
			printf("\n");
		}
		for(int yy = 0; yy < height; yy++)
		{
			for (int xx = 0; xx < widht; xx++)
			{
				printf("%d ", tab_color[yy][xx]);
			}
			printf("\n");
		}
		
		x_str = 0;
		x_tab = 0;
		y_tab++;
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	printf("\n");
	close(fd);

////

	rotate_all(d.win_widht, d.win_height, d.square_size, mlx, mlx_win, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);

	i = 0;
	while (i < height)
		free(tab_hw[i++]);
	free(tab_hw);
	i = 0;
	while (i < height)
		free(tab_color[i++]);
	free(tab_color);

	return (0);
}
