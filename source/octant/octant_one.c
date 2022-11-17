/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octant_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:59:25 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/17 09:23:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	change_dif_and_color(t_line_put_vars *v);

void	octant_one(t_data_util *d, t_line_put_vars *v)
{
	int	x;
	int	y;

	v->e = v->dx;
	v->dx = v->e * 2;
	v->dy = v->dy * 2;
	v->color = (v->c_one_r << 16) + (v->c_one_v << 8) + (v->c_one_b);
	while (v->x_one < v->x_two)
	{
		x = v->x_one + d->x_shift;
		y = v->y_one + d->y_shift;
		if (v->x_one + d->x_shift > 0
			&& v->y_one + d->y_shift > 0
			&& v->x_one + d->x_shift < d->win_widht
			&& v->y_one + d->y_shift < d->win_height)
			my_mlx_pixel_put(d->img, x, y, v->color);
		v->x_one++;
		v->e = v->e + v->dy;
		if (v->e < 0)
		{
			v->y_one--;
			v->e = v->e + v->dx;
		}
		change_dif_and_color(v);
	}
}

void	change_dif_and_color(t_line_put_vars *v)
{
	int	r_x;
	int	v_x;
	int	b_x;

	v->dif_xi_r = v->dif_xi_r + v->dif_x_r;
	v->dif_xi_v = v->dif_xi_v + v->dif_x_v;
	v->dif_xi_b = v->dif_xi_b + v->dif_x_b;
	r_x = (v->c_one_r + (int)(v->dif_xi_r + 0.5)) << 16;
	v_x = (v->c_one_v + (int)(v->dif_xi_v + 0.5)) << 8;
	b_x = v->c_one_b + (int)(v->dif_xi_b + 0.5);
	v->color = r_x + v_x + b_x;
}
