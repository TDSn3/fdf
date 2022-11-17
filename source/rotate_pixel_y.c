/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pixel_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:03:49 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/17 09:55:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	rotate_pixel_y(t_data_util *d, t_rotate_all_vars *v)
{
	float	x_m;
	float	y_m;
	float	x;
	float	angle;

	angle = -d->rotation * M_PI / 180;
	x_m = v->x_o - v->win_h_div;
	y_m = v->y_o - v->win_w_div;
	x = x_m * cosf(angle) + y_m * sinf(angle) + v->win_h_div;
	if (v->x_o < v->win_h_div)
		x = x + ((v->win_h_div - x) * d->projection);
	else
		x = x - ((x - v->win_h_div) * d->projection);
	return (x -= d->tab_hw[v->i][v->j] * d->h_point);
}
