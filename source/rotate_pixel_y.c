/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pixel_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:03:49 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/10 22:56:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	rotate_pixel_y(int Ox, int Oy, int Mx, int My, t_data_util *d, int i, int j)
{
	float	xM, yM, x, y, angle;

	angle = -45 * M_PI / 180;
	xM = Mx - Ox; 
	yM = My - Oy;
	x = xM * cosf(angle) + yM * sinf(angle) + Ox;
	if (Mx < Ox)
		x = x + ((Ox - x) * 0.42);
	else
		x = x - ((x - Ox) * 0.42);
	return (x -= d->tab_hw[i][j] * 3);
}
