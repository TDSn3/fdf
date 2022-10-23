/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:27:35 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/23 22:33:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdio.h"
#include "unistd.h"

#define L 1480
#define H 920
#define SQUARE_X 30

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
	mlx_win = mlx_new_window(mlx, L, H, "test");
	img.img = mlx_new_image(mlx, L, H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int		tab[3][3] = {{0, 0, 0},
						 {0, 0, 0},
						 {0, 0, 0}};

	float tabX = 6;
	float tabY = 6;
	int i = 0;
	int j = 0;
	float x_after ;
	float y_after;
	float x;
	float y;
	float x2_after ;
	float y2_after;
	float x2;
	float y2;
	while (i < tabX)
	{
		while (j < tabY)
		{
			if (i + 1 < tabX)
				line_put(rotate_pixel_x(L / 2,	H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		(H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X))) + (SQUARE_X / 2),
						 rotate_pixel_y(L / 2,	H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		(H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X))),
						 rotate_pixel_x(L / 2,	H / 2, 	L /2 - ((tabX / 2) * SQUARE_X) + ((i + 1) * SQUARE_X), 	H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X)) + (SQUARE_X / 2),
						 rotate_pixel_y(L / 2,	H / 2, 	L /2 - ((tabX / 2) * SQUARE_X) + ((i + 1) * SQUARE_X), 	H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X)),
						 mlx, mlx_win, &img);
			if (j + 1 < tabY)
				line_put(rotate_pixel_x(L / 2, H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		(H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X))) + (SQUARE_X / 2),
						 rotate_pixel_y(L / 2, H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		(H /2 - ((tabY / 2) * SQUARE_X) + (j * SQUARE_X))),
						 rotate_pixel_x(L / 2, H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		H /2 - ((tabY / 2) * SQUARE_X) + ((j + 1) * SQUARE_X)) + (SQUARE_X / 2),
						 rotate_pixel_y(L / 2, H / 2, 	(L /2 - ((tabX / 2) * SQUARE_X) + (i * SQUARE_X)), 		H /2 - ((tabY / 2) * SQUARE_X) + ((j + 1) * SQUARE_X)),
						 mlx, mlx_win, &img);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
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
					y1++;
				}
			}
			else // dy < 0 && dx == 0
			{
				while (y1 > y2)
				{
					my_mlx_pixel_put(img, x1, y1, 0x000000FF);
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
	if (My < Oy)
		y = y + ((Oy - y) * 0.42);
	else
		y = y - ((y - Oy) * 0.42);
	return (y);
}
