/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:31:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/16 13:50:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	line_put(int x1, int y1, int x2, int y2, void *mlx, void *mlx_win, t_data_mlximg *img, t_data_util *d, int i, int j, int i2, int j2)
{
	int	dx;
	int	dy;
	int	e;
	int color1_R;
	int color1_V;
	int color1_B;

	int color2_R;
	int color2_V;
	int color2_B;

	int color;

	float	dif_R;
	float	dif_V;
	float	dif_B;

	dx = x2 - x1;
	dy = y2 - y1;

	color1_R = (d->tab_color[i][j] >> 16) % 256;
	color1_V = (d->tab_color[i][j] >> 8) % 256;
	color1_B = (d->tab_color[i][j]) % 256;

	color2_R = (d->tab_color[i2][j2] >> 16) % 256;
	color2_V = (d->tab_color[i2][j2] >> 8) % 256;
	color2_B = (d->tab_color[i2][j2]) % 256;

	color = (color1_R << 16) + (color1_V << 8) + (color1_B);
	if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
		my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
	color = (color2_R << 16) + (color2_V << 8) + (color2_B);
	if (x2 + d->x_shift > 0 && y2 + d->y_shift > 0 && x2 + d->x_shift < d->win_widht && y2 + d->y_shift< d->win_height)
		my_mlx_pixel_put(img, x2 + d->x_shift, y2 + d->y_shift, color);

	if (x2 > x1)
	{
			dif_R = (float)(color2_R - color1_R) / (float)(x2 - x1);
			dif_V = (float)(color2_V - color1_V) / (float)(x2 - x1);
			dif_B = (float)(color2_B - color1_B) / (float)(x2 - x1);
	}
	else
	{
			dif_R = (float)(color2_R - color1_R) / (float)(x1 - x2);
			dif_V = (float)(color2_V - color1_V) / (float)(x1 - x2);
			dif_B = (float)(color2_B - color1_B) / (float)(x1 - x2);
	}

	float dif_y_R;
	float dif_y_V;
	float dif_y_B;

	if (y2 > y1)
	{
			dif_y_R = (float)(color2_R - color1_R) / (float)(y2 - y1);
			dif_y_V = (float)(color2_V - color1_V) / (float)(y2 - y1);
			dif_y_B = (float)(color2_B - color1_B) / (float)(y2 - y1);
	}
	else
	{
			dif_y_R = (float)(color2_R - color1_R) / (float)(y1 - y2);
			dif_y_V = (float)(color2_V - color1_V) / (float)(y1 - y2);
			dif_y_B = (float)(color2_B - color1_B) / (float)(y1 - y2);
	}
	
	float	dif_iR = dif_R;
	float	dif_iV = dif_V;
	float	dif_iB = dif_B;

	float	dif_y_iR = dif_y_R;
	float	dif_y_iV = dif_y_V;
	float	dif_y_iB = dif_y_B;

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
						color = (color1_R << 16) + (color1_V << 8) + (color1_B);
						while (x1 < x2)
						{
							if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
								my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
							x1++;
							e = e - dy;
							if (e < 0)
							{
								y1++;
								e = e + dx;
							}
							dif_iR = dif_iR + dif_R;
							dif_iV = dif_iV + dif_V;
							dif_iB = dif_iB + dif_B;
							color = ((color1_R + (int)(dif_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_iV + 0.5)) << 8) + (color1_B + (int)(dif_iB + 0.5));
						}
					}
					else // dx < dy // octant 7
					{
						e = dy;
						dx = dx * 2;
						dy = e * 2;
						color = (color1_R << 16) + (color1_V << 8) + (color1_B);
						while (x1 <= x2 && y1 <= y2)
						{
							if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
								my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
							y1++;
							e = e - dx;
							if (e < 0)
							{
								x1++;
								e = e + dy;
							}
							dif_y_iR = dif_y_iR + dif_y_R;
							dif_y_iV = dif_y_iV + dif_y_V;
							dif_y_iB = dif_y_iB + dif_y_B;
							color = ((color1_R + (int)(dif_y_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_y_iV + 0.5)) << 8) + (color1_B + (int)(dif_y_iB + 0.5));
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
						color = (color1_R << 16) + (color1_V << 8) + (color1_B);
						while (x1 < x2)
						{
							if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
								my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
							x1++;
							e = e + dy;
							if (e < 0)
							{
								y1--;
								e = e + dx;
							}
							dif_iR = dif_iR + dif_R;
							dif_iV = dif_iV + dif_V;
							dif_iB = dif_iB + dif_B;
							color = ((color1_R + (int)(dif_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_iV + 0.5)) << 8) + (color1_B + (int)(dif_iB + 0.5));
						}
					}
					else // dx < -dy // octant 2
					{
						e = dy;
						dx = dx * 2;
						dy = e * 2;
						color = (color1_R << 16) + (color1_V << 8) + (color1_B);
						while (x1 <= x2 && y1 >= y2)
						{
							if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
								my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
							y1--;
							e = e + dx;
							if (e > 0)
							{
								x1++;
								e = e + dy;
							}
							dif_y_iR = dif_y_iR + dif_y_R;
							dif_y_iV = dif_y_iV + dif_y_V;
							dif_y_iB = dif_y_iB + dif_y_B;
							color = ((color1_R + (int)(dif_y_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_y_iV + 0.5)) << 8) + (color1_B + (int)(dif_y_iB + 0.5));
						}
					}
				}
			}
			else // dy == 0 && dx > 0
			{
				color = (color1_R << 16) + (color1_V << 8) + (color1_B);
				while (x1 < x2)
				{
					if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
						my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
					x1++;
					dif_iR = dif_iR + dif_R;
					dif_iV = dif_iV + dif_V;
					dif_iB = dif_iB + dif_B;
					color = ((color1_R + (int)(dif_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_iV + 0.5)) << 8) + (color1_B + (int)(dif_iB + 0.5));
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
						color = (color1_R << 16) + (color1_V << 8) + (color1_B);
						while (x1 > x2)
						{
							if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
								my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
							x1--;
							e = e + dy;
							if (e >= 0)
							{
								y1++;
								e = e + dx;
							}
							dif_iR = dif_iR + dif_R;
							dif_iV = dif_iV + dif_V;
							dif_iB = dif_iB + dif_B;
							color = ((color1_R + (int)(dif_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_iV + 0.5)) << 8) + (color1_B + (int)(dif_iB + 0.5));
						}
					}
					else // -dx < dy // octant 6
					{
						e = dy;
						dx = dx * 2;
						dy = e * 2;
						color = (color1_R << 16) + (color1_V << 8) + (color1_B);
						while (x1 >= x2 && y1 <= y2)
						{
							if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
								my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
							y1++;
							e = e + dx;
							if (e <= 0)
							{
								x1--;
								e = e + dy;
							}
							dif_y_iR = dif_y_iR + dif_y_R;
							dif_y_iV = dif_y_iV + dif_y_V;
							dif_y_iB = dif_y_iB + dif_y_B;
							color = ((color1_R + (int)(dif_y_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_y_iV + 0.5)) << 8) + (color1_B + (int)(dif_y_iB + 0.5));
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
						color = (color1_R << 16) + (color1_V << 8) + (color1_B);
						while (x1 > x2)
						{
							if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
								my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
							x1--;
							e = e - dy;
							if (e >= 0)
							{
								y1--;
								e = e + dx;
							}
							dif_iR = dif_iR + dif_R;
							dif_iV = dif_iV + dif_V;
							dif_iB = dif_iB + dif_B;
							color = ((color1_R + (int)(dif_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_iV + 0.5)) << 8) + (color1_B + (int)(dif_iB + 0.5));
						}
					}
					else // dx > dy // octant 3
					{
						e = dy;
						dx = dx * 2;
						dy = e * 2;
						color = (color1_R << 16) + (color1_V << 8) + (color1_B);
						while (x1 >= x2 && y1 >= y2)
						{
							if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
								my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
							y1--;
							e = e - dx;
							if (e >= 0)
							{
								x1--;
								e = e + dy;
							}
							dif_y_iR = dif_y_iR + dif_y_R;
							dif_y_iV = dif_y_iV + dif_y_V;
							dif_y_iB = dif_y_iB + dif_y_B;
							color = ((color1_R + (int)(dif_y_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_y_iV + 0.5)) << 8) + (color1_B + (int)(dif_y_iB + 0.5));
						}
					}
				}
			}
			else // dy == 0 && dx < 0
			{
				color = (color1_R << 16) + (color1_V << 8) + (color1_B);
				while (x1 > x2)
				{
					if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
						my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
					x1--;
					dif_iR = dif_iR + dif_R;
					dif_iV = dif_iV + dif_V;
					dif_iB = dif_iB + dif_B;
					color = ((color1_R + (int)(dif_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_iV + 0.5)) << 8) + (color1_B + (int)(dif_iB + 0.5));
				}
			}
		}
	}
	else // dx == 0
	{
		if (dy != 0)
		{
			if (dy > 0) // dy > 0 && dx == 0
			{
				color = (color1_R << 16) + (color1_V << 8) + (color1_B);
				while (y1 < y2)
				{
					if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
						my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
					y1++;
					dif_y_iR = dif_y_iR + dif_y_R;
					dif_y_iV = dif_y_iV + dif_y_V;
					dif_y_iB = dif_y_iB + dif_y_B;
					color = ((color1_R + (int)(dif_y_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_y_iV + 0.5)) << 8) + (color1_B + (int)(dif_y_iB + 0.5));
				}
			}
			else // dy < 0 && dx == 0
			{
				color = (color1_R << 16) + (color1_V << 8) + (color1_B);
				while (y1 > y2)
				{
					if (x1 + d->x_shift > 0 && y1 + d->y_shift > 0 && x1 + d->x_shift < d->win_widht && y1 + d->y_shift < d->win_height)
						my_mlx_pixel_put(img, x1 + d->x_shift, y1 + d->y_shift, color);
					y1--;
					dif_y_iR = dif_y_iR + dif_y_R;
					dif_y_iV = dif_y_iV + dif_y_V;
					dif_y_iB = dif_y_iB + dif_y_B;
					color = ((color1_R + (int)(dif_y_iR + 0.5)) << 16) + ((color1_V  + (int)(dif_y_iV + 0.5)) << 8) + (color1_B + (int)(dif_y_iB + 0.5));
				}
			}
		}
	}
}
