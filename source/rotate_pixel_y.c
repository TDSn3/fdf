/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pixel_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:03:49 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/16 15:01:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	rotate_pixel_y(int Ox, int Oy, int Mx, int My, t_data_util *d, int i, int j)
{
	float	xM;
	float	yM;
	float	x;
	float	angle;

	angle = -d->rotation * M_PI / 180;
	xM = Mx - Ox; 
	yM = My - Oy;
	x = xM * cosf(angle) + yM * sinf(angle) + Ox;
	if (Mx < Ox)
		x = x + ((Ox - x) * d->projection);
	else
		x = x - ((x - Ox) * d->projection);
	return (x -= d->tab_hw[i][j] * d->h_point);
}
