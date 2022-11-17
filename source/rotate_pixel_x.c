/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pixel_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:04:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/17 09:55:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	rotate_pixel_x(t_data_util *d, t_rotate_all_vars *v)
{
	float	x_m;
	float	y_m;
	float	y;
	float	angle;

	angle = -d->rotation * M_PI / 180;
	x_m = v->x_o - v->win_h_div;
	y_m =  v->y_o - v->win_w_div;
	y = - x_m * sinf(angle) + y_m * cosf(angle) + v->win_w_div;
	return (y);
}
