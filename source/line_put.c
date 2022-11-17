/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:31:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/17 12:39:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	ssv(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl);
static void	ssvpt(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl);

void	line_put(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl)
{	
	ssv(d, v, vl);
	vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
	if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
		my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);

	vl->color = (vl->c_two_r << 16) + (vl->c_two_v << 8) + (vl->c_two_b);
	if (vl->x_two + d->x_shift > 0 && vl->y_two + d->y_shift > 0 && vl->x_two + d->x_shift < d->win_widht && vl->y_two + d->y_shift < d->win_height)
		my_mlx_pixel_put(d->img, vl->x_two + d->x_shift, vl->y_two + d->y_shift, vl->color);

	if (vl->dx != 0)
	{
		if (vl->dx > 0)
		{
			if (vl->dy != 0)
			{
				if (vl->dy > 0) // && dx > 0 // cadran 4
				{
					if (vl->dx >= vl->dy) // octant 8
					{
						vl->e = vl->dx;
						vl->dx = vl->e * 2;
						vl->dy = vl->dy * 2;
						vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
						while (vl->x_one < vl->x_two)
						{
							if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
								my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
							vl->x_one++;
							vl->e = vl->e - vl->dy;
							if (vl->e < 0)
							{
								vl->y_one++;
								vl->e = vl->e + vl->dx;
							}
							vl->dif_xi_r = vl->dif_xi_r + vl->dif_x_r;
							vl->dif_xi_v = vl->dif_xi_v + vl->dif_x_v;
							vl->dif_xi_b = vl->dif_xi_b + vl->dif_x_b;
							vl->color = ((vl->c_one_r + (int)(vl->dif_xi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_xi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_xi_b + 0.5));
						}
					}
					else // dx < dy // octant 7
					{
						vl->e = vl->dy;
						vl->dx = vl->dx * 2;
						vl->dy = vl->e * 2;
						vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
						while (vl->x_one <= vl->x_two && vl->y_one <= vl->y_two)
						{
							if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
								my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
							vl->y_one++;
							vl->e = vl->e - vl->dx;
							if (vl->e < 0)
							{
								vl->x_one++;
								vl->e = vl->e + vl->dy;
							}
							vl->dif_yi_r = vl->dif_yi_r + vl->dif_y_r;
							vl->dif_yi_v = vl->dif_yi_v + vl->dif_y_v;
							vl->dif_yi_b = vl->dif_yi_b + vl->dif_y_b;
							vl->color = ((vl->c_one_r + (int)(vl->dif_yi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_yi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_yi_b + 0.5));
						}
					}
				}
				else // dy < 0 && dx > 0 // cadran 1
				{
					if (vl->dx >= -vl->dy) // octant 1
					{
						vl->e = vl->dx;
						vl->dx = vl->e * 2;
						vl->dy = vl->dy * 2;
						vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
						while (vl->x_one < vl->x_two)
						{
							if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
								my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
							vl->x_one++;
							vl->e = vl->e + vl->dy;
							if (vl->e < 0)
							{
								vl->y_one--;
								vl->e = vl->e + vl->dx;
							}
							vl->dif_xi_r = vl->dif_xi_r + vl->dif_x_r;
							vl->dif_xi_v = vl->dif_xi_v + vl->dif_x_v;
							vl->dif_xi_b = vl->dif_xi_b + vl->dif_x_b;
							vl->color = ((vl->c_one_r + (int)(vl->dif_xi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_xi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_xi_b + 0.5));
							}
					}
					else // dx < -dy // octant 2
					{
						vl->e = vl->dy;
						vl->dx = vl->dx * 2;
						vl->dy = vl->e * 2;
						vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
						while (vl->x_one <= vl->x_two && vl->y_one >= vl->y_two)
						{
							if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
								my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
							vl->y_one--;
							vl->e = vl->e + vl->dx;
							if (vl->e > 0)
							{
								vl->x_one++;
								vl->e = vl->e + vl->dy;
							}
							vl->dif_yi_r = vl->dif_yi_r + vl->dif_y_r;
							vl->dif_yi_v = vl->dif_yi_v + vl->dif_y_v;
							vl->dif_yi_b = vl->dif_yi_b + vl->dif_y_b;
							vl->color = ((vl->c_one_r + (int)(vl->dif_yi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_yi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_yi_b + 0.5));
							}
					}
				}
			}
			else // dy == 0 && dx > 0
			{
				vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
				while (vl->x_one < vl->x_two)
				{
					if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
						my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
					vl->x_one++;
					vl->dif_xi_r = vl->dif_xi_r + vl->dif_x_r;
					vl->dif_xi_v = vl->dif_xi_v + vl->dif_x_v;
					vl->dif_xi_b = vl->dif_xi_b + vl->dif_x_b;
					vl->color = ((vl->c_one_r + (int)(vl->dif_xi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_xi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_xi_b + 0.5));
				}
			}
		}
		else // dx < 0
		{
			if (vl->dy != 0)
			{
				if (vl->dy > 0) // && dx < 0 // cadran 3
				{
					if (-(vl->dx) >= vl->dy) // octant 5
					{
						vl->e = vl->dx;
						vl->dx = vl->e * 2;
						vl->dy = vl->dy * 2;
						vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
						while (vl->x_one > vl->x_two)
						{
							if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
								my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
							vl->x_one--;
							vl->e = vl->e + vl->dy;
							if (vl->e >= 0)
							{
								vl->y_one++;
								vl->e = vl->e + vl->dx;
							}
							vl->dif_xi_r = vl->dif_xi_r + vl->dif_x_r;
							vl->dif_xi_v = vl->dif_xi_v + vl->dif_x_v;
							vl->dif_xi_b = vl->dif_xi_b + vl->dif_x_b;
							vl->color = ((vl->c_one_r + (int)(vl->dif_xi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_xi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_xi_b + 0.5));						}
					}
					else // -dx < dy // octant 6
					{
						vl->e = vl->dy;
						vl->dx = vl->dx * 2;
						vl->dy = vl->e * 2;
						vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
						while (vl->x_one >= vl->x_two && vl->y_one <= vl->y_two)
						{
							if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
								my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
							vl->y_one++;
							vl->e = vl->e + vl->dx;
							if (vl->e <= 0)
							{
								vl->x_one--;
								vl->e = vl->e + vl->dy;
							}
							vl->dif_yi_r = vl->dif_yi_r + vl->dif_y_r;
							vl->dif_yi_v = vl->dif_yi_v + vl->dif_y_v;
							vl->dif_yi_b = vl->dif_yi_b + vl->dif_y_b;
							vl->color = ((vl->c_one_r + (int)(vl->dif_yi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_yi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_yi_b + 0.5));						}
					}
				}
				else // dy < 0 && dx < 0 // cadran 2
				{
					if (vl->dx <= vl->dy) // octant 4
					{
						vl->e = vl->dx;
						vl->dx = vl->e * 2;
						vl->dy = vl->dy * 2;
						vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
						while (vl->x_one > vl->x_two)
						{
							if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
								my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
							vl->x_one--;
							vl->e = vl->e - vl->dy;
							if (vl->e >= 0)
							{
								vl->y_one--;
								vl->e = vl->e + vl->dx;
							}
							vl->dif_xi_r = vl->dif_xi_r + vl->dif_x_r;
							vl->dif_xi_v = vl->dif_xi_v + vl->dif_x_v;
							vl->dif_xi_b = vl->dif_xi_b + vl->dif_x_b;
							vl->color = ((vl->c_one_r + (int)(vl->dif_xi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_xi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_xi_b + 0.5));						}
					}
					else // dx > dy // octant 3
					{
						vl->e = vl->dy;
						vl->dx = vl->dx * 2;
						vl->dy = vl->e * 2;
						vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
						while (vl->x_one >= vl->x_two && vl->y_one >= vl->y_two)
						{
							if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
								my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
							vl->y_one--;
							vl->e = vl->e - vl->dx;
							if (vl->e >= 0)
							{
								vl->x_one--;
								vl->e = vl->e + vl->dy;
							}
							vl->dif_yi_r = vl->dif_yi_r + vl->dif_y_r;
							vl->dif_yi_v = vl->dif_yi_v + vl->dif_y_v;
							vl->dif_yi_b = vl->dif_yi_b + vl->dif_y_b;
							vl->color = ((vl->c_one_r + (int)(vl->dif_yi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_yi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_yi_b + 0.5));						}
					}
				}
			}
			else // dy == 0 && dx < 0
			{
				vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
				while (vl->x_one > vl->x_two)
				{
					if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
						my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
					vl->x_one--;
					vl->dif_xi_r = vl->dif_xi_r + vl->dif_x_r;
					vl->dif_xi_v = vl->dif_xi_v + vl->dif_x_v;
					vl->dif_xi_b = vl->dif_xi_b + vl->dif_x_b;
					vl->color = ((vl->c_one_r + (int)(vl->dif_xi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_xi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_xi_b + 0.5));				}
			}
		}
	}
	else // dx == 0
	{
		if (vl->dy != 0)
		{
			if (vl->dy > 0) // dy > 0 && dx == 0
			{
				vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
				while (vl->y_one < vl->y_two)
				{
					if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
						my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
					vl->y_one++;
					vl->dif_yi_r = vl->dif_yi_r + vl->dif_y_r;
					vl->dif_yi_v = vl->dif_yi_v + vl->dif_y_v;
					vl->dif_yi_b = vl->dif_yi_b + vl->dif_y_b;
					vl->color = ((vl->c_one_r + (int)(vl->dif_yi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_yi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_yi_b + 0.5));				}
			}
			else // dy < 0 && dx == 0
			{
				vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
				while (vl->y_one > vl->y_two)
				{
					if (vl->x_one + d->x_shift > 0 && vl->y_one + d->y_shift > 0 && vl->x_one + d->x_shift < d->win_widht && vl->y_one + d->y_shift < d->win_height)
						my_mlx_pixel_put(d->img, vl->x_one + d->x_shift, vl->y_one + d->y_shift, vl->color);
					vl->y_one--;
					vl->dif_yi_r = vl->dif_yi_r + vl->dif_y_r;
					vl->dif_yi_v = vl->dif_yi_v + vl->dif_y_v;
					vl->dif_yi_b = vl->dif_yi_b + vl->dif_y_b;
					vl->color = ((vl->c_one_r + (int)(vl->dif_yi_r + 0.5)) << 16) + ((vl->c_one_v  + (int)(vl->dif_yi_v + 0.5)) << 8) + (vl->c_one_b + (int)(vl->dif_yi_b + 0.5));				}
			}
		}
	}
}

//			Setup Struct Vars
static void	ssv(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl)
{
	vl->i_one = v->i;
	vl->j_one = v->j;
	vl->x_one = d->pos_x[v->i][v->j] + d->square_size;
	vl->y_one = d->pos_y[v->i][v->j];
	vl->dx = vl->x_two - vl->x_one;
	vl->dy = vl->y_two - vl->y_one;
	vl->e = 0;
	vl->c_one_r = (d->tab_color[v->i][v->j] >> 16) % 256;
	vl->c_one_v = (d->tab_color[v->i][v->j] >> 8) % 256;
	vl->c_one_b = (d->tab_color[v->i][v->j]) % 256;
	vl->c_two_r = (d->tab_color[vl->i_two][vl->j_two] >> 16) % 256;
	vl->c_two_v = (d->tab_color[vl->i_two][vl->j_two] >> 8) % 256;
	vl->c_two_b = (d->tab_color[vl->i_two][vl->j_two]) % 256;
	vl->color = 0;
	ssvpt(d, v, vl);
}

//			Setup Struct Vars Part Two
static void	ssvpt(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl)
{
	if (vl->x_two > vl->x_one)
	{
			vl->dif_x_r = (float)(vl->c_two_r - vl->c_one_r) / (float)(vl->x_two - vl->x_one);
			vl->dif_x_v = (float)(vl->c_two_v - vl->c_one_v) / (float)(vl->x_two - vl->x_one);
			vl->dif_x_b = (float)(vl->c_two_b - vl->c_one_b) / (float)(vl->x_two - vl->x_one);
	}
	else
	{
			vl->dif_x_r = (float)(vl->c_two_r - vl->c_one_r) / (float)(vl->x_one - vl->x_two);
			vl->dif_x_v = (float)(vl->c_two_v - vl->c_one_v) / (float)(vl->x_one - vl->x_two);
			vl->dif_x_b = (float)(vl->c_two_b - vl->c_one_b) / (float)(vl->x_one - vl->x_two);
	}
	if (vl->y_two > vl->y_one)
	{
			vl->dif_y_r = (float)(vl->c_two_r - vl->c_one_r) / (float)(vl->y_two - vl->y_one);
			vl->dif_y_v = (float)(vl->c_two_v - vl->c_one_v) / (float)(vl->y_two - vl->y_one);
			vl->dif_y_b = (float)(vl->c_two_b - vl->c_one_b) / (float)(vl->y_two - vl->y_one);
	}
	else
	{
			vl->dif_y_r = (float)(vl->c_two_r - vl->c_one_r) / (float)(vl->y_one - vl->y_two);
			vl->dif_y_v = (float)(vl->c_two_v - vl->c_one_v) / (float)(vl->y_one - vl->y_two);
			vl->dif_y_b = (float)(vl->c_two_b - vl->c_one_b) / (float)(vl->y_one - vl->y_two);
	}
	vl->dif_xi_r = vl->dif_x_r;
	vl->dif_xi_v = vl->dif_x_v;
	vl->dif_xi_b = vl->dif_x_b;
	vl->dif_yi_r = vl->dif_y_r;
	vl->dif_yi_v = vl->dif_y_v;
	vl->dif_yi_b = vl->dif_y_b;
}

