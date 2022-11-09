/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:31:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/09 16:08:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	line_put(int x1, int y1, int x2, int y2, void *mlx, void *mlx_win, t_data_mlximg *img, t_data_util *d, int i, int j, int i2, int j2)
{
	int	dx;
	int	dy;
	int	e;
	int color1;
	int color2;
	float	dif;

	dx = x2 - x1;
	dy = y2 - y1;
	color1 = d->tab_color[i][j];
	color2 = d->tab_color[i2][j2];
	if (color1 < color2)
		color1 = color1 - (color1 * 2);
	printf("%x  %x  |  %d  %d  |  x1 = %d  x2 = %d\n", color1, color2, color1, color2, x1, x2);
	my_mlx_pixel_put(img, x1, y1, color1);
	my_mlx_pixel_put(img, x2, y2, color2);
	dif = (float)(color2 - color1) / (float)(x2 - x1);
	float	dif_i = dif;
	printf("dif = %f\n", dif);
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
							my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
							printf("dif_i = %d\n", (int)(dif_i + 0.5));
							my_mlx_pixel_put(img, x1, y1, color1 + (int)(dif_i + 0.5));
							y1++;
							e = e - dx;
							if (e < 0)
							{
								x1++;
								e = e + dy;
								dif_i = dif_i + dif;
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
							my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
							my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
					my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
//							color1 = d->tab_color[i][j];
							my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
//							color1 = d->tab_color[i][j];
							my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
//							color1 = d->tab_color[i][j];
							my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
//							color1 = d->tab_color[i][j];
							my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
//					color1 = d->tab_color[i][j];
					my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
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
//					color1 = d->tab_color[i][j];
					my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
					y1++;
				}
			}
			else // dy < 0 && dx == 0
			{
				while (y1 > y2)
				{
//					color1 = d->tab_color[i][j];
					my_mlx_pixel_put(img, x1, y1, 0x00aa00aa);
					y1--;
				}
			}
		}
	}
}
