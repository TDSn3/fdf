/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dy_inf_dx_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:01:40 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 08:04:56 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	change_dif_and_color(t_line_put_vars *vl);

void	dy_inf_dx_zero(t_data_util *d, t_line_put_vars *vl)
{
	int	x;
	int	y;

	vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
	while (vl->y_one > vl->y_two)
	{
		x = vl->x_one + d->x_shift;
		y = vl->y_one + d->y_shift;
		if (vl->x_one + d->x_shift > 0
			&& vl->y_one + d->y_shift > 0
			&& vl->x_one + d->x_shift < d->win_widht
			&& vl->y_one + d->y_shift < d->win_height)
			my_mlx_pixel_put(d->img, x, y, vl->color);
		vl->y_one--;
		change_dif_and_color(vl);
	}
}

static void	change_dif_and_color(t_line_put_vars *vl)
{
	int	r_x;
	int	v_x;
	int	b_x;

	vl->dif_yi_r = vl->dif_yi_r + vl->dif_y_r;
	vl->dif_yi_v = vl->dif_yi_v + vl->dif_y_v;
	vl->dif_yi_b = vl->dif_yi_b + vl->dif_y_b;
	r_x = (vl->c_one_r + (int)(vl->dif_yi_r + 0.5)) << 16;
	v_x = (vl->c_one_v + (int)(vl->dif_yi_v + 0.5)) << 8;
	b_x = vl->c_one_b + (int)(vl->dif_yi_b + 0.5);
	vl->color = r_x + v_x + b_x;
}
