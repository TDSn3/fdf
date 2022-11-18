/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:31:58 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 08:30:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	dx_sz(t_data_util *d, t_line_put_vars *vl);
static void	dx_iz(t_data_util *d, t_line_put_vars *vl);

static void	start_lp(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl)
{
	int	x;
	int	y;

	ssv(d, v, vl);
	ssvptt(vl);
	x = vl->x_one + d->x_shift;
	y = vl->y_one + d->y_shift;
	vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
	if (vl->x_one + d->x_shift > 0
		&& vl->y_one + d->y_shift > 0
		&& vl->x_one + d->x_shift < d->win_widht
		&& vl->y_one + d->y_shift < d->win_height)
		my_mlx_pixel_put(d->img, x, y, vl->color);
	x = vl->x_two + d->x_shift;
	y = vl->y_two + d->y_shift;
	vl->color = (vl->c_two_r << 16) + (vl->c_two_v << 8) + (vl->c_two_b);
	if (vl->x_two + d->x_shift > 0
		&& vl->y_two + d->y_shift > 0
		&& vl->x_two + d->x_shift < d->win_widht
		&& vl->y_two + d->y_shift < d->win_height)
		my_mlx_pixel_put(d->img, x, y, vl->color);
}

void	line_put(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl)
{	
	start_lp(d, v, vl);
	if (vl->dx != 0)
	{
		if (vl->dx > 0)
			dx_sz(d, vl);
		else
			dx_iz(d, vl);
	}
	else
	{
		if (vl->dy != 0)
		{
			if (vl->dy > 0)
				dy_sup_dx_zero(d, vl);
			else
				dy_inf_dx_zero(d, vl);
		}
	}
}

//			dx_sup_zero
static void	dx_sz(t_data_util *d, t_line_put_vars *vl)
{
	if (vl->dy != 0)
	{
		if (vl->dy > 0)
		{
			if (vl->dx >= vl->dy)
				octant_eight(d, vl);
			else
				octant_seven(d, vl);
		}
		else
		{
			if (vl->dx >= -(vl->dy))
				octant_one(d, vl);
			else
				octant_two(d, vl);
		}
	}
	else
		dy_zero_dx_sup(d, vl);
}

//			dx_inf_zero
static void	dx_iz(t_data_util *d, t_line_put_vars *vl)
{
	if (vl->dy != 0)
	{
		if (vl->dy > 0)
		{
			if (-(vl->dx) >= vl->dy)
				octant_five(d, vl);
			else
				octant_six(d, vl);
		}
		else
		{
			if (vl->dx <= vl->dy)
				octant_four(d, vl);
			else
				octant_three(d, vl);
		}
	}
	else
		dy_zero_dx_inf(d, vl);
}
