/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octant_eight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:59:19 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 06:41:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	change_dif_and_color(t_line_put_vars *vl);

void	octant_eight(t_data_util *d, t_line_put_vars *vl)
{
	int	x;
	int	y;

	vl->e = vl->dx;
	vl->dx = vl->e * 2;
	vl->dy = vl->dy * 2;
	vl->color = (vl->c_one_r << 16) + (vl->c_one_v << 8) + (vl->c_one_b);
	while (vl->x_one < vl->x_two)
	{
		x = vl->x_one + d->x_shift;
		y = vl->y_one + d->y_shift;
		if (vl->x_one + d->x_shift > 0
			&& vl->y_one + d->y_shift > 0
			&& vl->x_one + d->x_shift < d->win_widht
			&& vl->y_one + d->y_shift < d->win_height)
			my_mlx_pixel_put(d->img, x, y, vl->color);
		vl->x_one++;
		vl->e = vl->e - vl->dy;
		if (vl->e < 0)
		{
			vl->y_one++;
			vl->e = vl->e + vl->dx;
		}
		change_dif_and_color(vl);
	}
}

static void	change_dif_and_color(t_line_put_vars *vl)
{
	int	r_x;
	int	v_x;
	int	b_x;

	vl->dif_xi_r = vl->dif_xi_r + vl->dif_x_r;
	vl->dif_xi_v = vl->dif_xi_v + vl->dif_x_v;
	vl->dif_xi_b = vl->dif_xi_b + vl->dif_x_b;
	r_x = (vl->c_one_r + (int)(vl->dif_xi_r + 0.5)) << 16;
	v_x = (vl->c_one_v + (int)(vl->dif_xi_v + 0.5)) << 8;
	b_x = vl->c_one_b + (int)(vl->dif_xi_b + 0.5);
	vl->color = r_x + v_x + b_x;
}
