/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/23 01:56:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdio.h"
#include "unistd.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
float	my_abs(float nb);
void	line_put(int x1, int y1, int x2, int y2, void *mlx, void *mlx_win, t_data *img);
float	rotate_pixel_x(int Ox, int Oy, int Mx, int My);
float	rotate_pixel_y(int Ox, int Oy, int Mx, int My);

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "test");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int		tab[3][3] = {{0, 0, 0},
						 {0, 0, 0},
						 {0, 0, 0}};

	int i = 0;
	int j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			if (i + 1 < 3)
				line_put(rotate_pixel_x(3 * 50 + 200, 3 * 50 + 200, (i * 50 + 200), (j * 50 + 200)),
						 rotate_pixel_y(3 * 50 + 200, 3 * 50 + 200, (i * 50 + 200), (j * 50 + 200)),
						 rotate_pixel_x(3 * 50 + 200, 3 * 50 + 200, (i + 1) * 50 + 200, j * 50 + 200),
						 rotate_pixel_y(3 * 50 + 200, 3 * 50 + 200, (i + 1) * 50 + 200, j * 50 + 200),
						 mlx, mlx_win, &img);
			if (j + 1 < 3)
				line_put(rotate_pixel_x(3 * 50 + 200, 3 * 50 + 200, (i * 50 + 200), (j * 50 + 200)),
						 rotate_pixel_y(3 * 50 + 200, 3 * 50 + 200, (i * 50 + 200), (j * 50 + 200)),
						 rotate_pixel_x(3 * 50 + 200, 3 * 50 + 200, (i * 50 + 200), ((j + 1) * 50 + 200)),
						 rotate_pixel_y(3 * 50 + 200, 3 * 50 + 200, (i * 50 + 200), ((j + 1) * 50 + 200)),
						 mlx, mlx_win, &img);
			j++;
		}
		j = 0;
		i++;
	}

	mlx_loop(mlx);
	mlx_destroy_image(mlx, img.img);
	
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float	my_abs(float nb)
{
	if (nb < 0)
		return (nb * -1);
	else
		return (nb);
}

void	line_put(int x1, int y1, int x2, int y2, void *mlx, void *mlx_win, t_data *img)
{
	int	dx;
	int	dy;
	int	e;

	dx = x2 - x1;
	dy = y2 - y1;
	my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
	my_mlx_pixel_put(img, x2, y2, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	if (dx != 0)
	{
		if (dx > 0)
		{
			if (dy != 0)
			{
				if (dy > 0) // && dx > 0 // cadran 4
				{
					if (dx >= dy) // octant 8
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (x1 < x2)
						{
							my_mlx_pixel_put(img, x1, y1, 0x000000FF);
							mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
							x1++;
							e = e - dy;
							if (e < 0)
							{
								y1++;
								e = e + dx;
							}
						}
					}
					else // dx < dy // octant 7
					{
						e = dy;
						dx = dx * 2;
						dy = e * 2;
						while (x1 < x2)
						{
							my_mlx_pixel_put(img, x1, y1, 0x000000FF);
							mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
							y1++;
							e = e - dx;
							if (e < 0)
							{
								x1++;
								e = e + dy;
							}
						}
					}
				}
				else // dy < 0 && dx > 0 // cadran 1
				{
					if (dx >= -dy) // octant 1
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (x1 < x2)
						{
							my_mlx_pixel_put(img, x1, y1, 0x000000FF);
							mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
							x1++;
							e = e + dy;
							if (e < 0)
							{
								y1--;
								e = e + dx;
							}
						}
					}
					else // dx < -dy // octant 2
					{
						e = dy;
						dx = dx * 2;
						dy = e * 2;
						while (x1 < x2)
						{
							my_mlx_pixel_put(img, x1, y1, 0x000000FF);
							mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
							y1--;
							e = e + dx;
							if (e > 0)
							{
								x1++;
								e = e + dy;
							}
						}
					}
				}
			}
			else // dy == 0 && dx > 0
			{
				while (x1 < x2)
				{
					my_mlx_pixel_put(img, x1, y1, 0x000000FF);
					mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
					x1++;
				}
			}
		}
		else // dx < 0
		{
			if (dy != 0)
			{
				if (dy > 0) // && dx < 0 // cadran 3
				{
					if (-dx >= dy) // octant 5
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (x1 > x2)
						{
							my_mlx_pixel_put(img, x1, y1, 0x000000FF);
							mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
							x1--;
							e = e + dy;
							if (e >= 0)
							{
								y1++;
								e = e + dx;
							}
						}
					}
					else // -dx < dy // octant 6
					{
						e = dy;
						dx = dx * 2;
						dy = e * 2;
						while (x1 > x2)
						{
							my_mlx_pixel_put(img, x1, y1, 0x000000FF);
							mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
							y1++;
							e = e + dx;
							if (e <= 0)
							{
								x1--;
								e = e + dy;
							}
						}
					}
				}
				else // dy < 0 && dx < 0 // cadran 2
				{
					if (dx <= dy) // octant 4
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (x1 > x2)
						{
							my_mlx_pixel_put(img, x1, y1, 0x000000FF);
							mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
							x1--;
							e = e - dy;
							if (e >= 0)
							{
								y1--;
								e = e + dx;
							}
						}
					}
					else // dx > dy // octant 3
					{
						e = dy;
						dx = dx * 2;
						dy = e * 2;
						while (x1 > x2)
						{
							my_mlx_pixel_put(img, x1, y1, 0x000000FF);
							mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
							y1--;
							e = e - dx;
							if (e >= 0)
							{
								x1--;
								e = e + dy;
							}
						}
					}
				}
			}
			else // dy == 0 && dx < 0
			{
				while (x1 > x2)
				{
					my_mlx_pixel_put(img, x1, y1, 0x000000FF);
					mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
					x1--;
				}
			}
		}
	}
	else // dx == 0
	{
		if (dy != 0)
		{
			if (dy > 0)
			{
				while (y1 < y2)
				{
					my_mlx_pixel_put(img, x1, y1, 0x000000FF);
					mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
					y1++;
				}
			}
			else // dy < 0 && dx == 0
			{
				while (y1 > y2)
				{
					my_mlx_pixel_put(img, x1, y1, 0x000000FF);
					mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
					y1--;
				}
			}
		}
	}
}

float	rotate_pixel_x(int Ox, int Oy, int Mx, int My)
{
	float	xM, yM, x, y, angle;
	angle = 45 * M_PI / 180;
	xM = Mx - Ox; 
	yM = My - Oy;
	x = xM * cosf(angle) + yM * sinf(angle) + Ox;
	y = - xM * sinf(angle) + yM * cosf(angle) + Oy;
	return (x);
}

float	rotate_pixel_y(int Ox, int Oy, int Mx, int My)
{
	float	xM, yM, x, y, angle;
	angle = 45 * M_PI / 180;
	xM = Mx - Ox; 
	yM = My - Oy;
	x = xM * cosf(angle) + yM * sinf(angle) + Ox;
	y = - xM * sinf(angle) + yM * cosf(angle) + Oy;
	return (y);
}
