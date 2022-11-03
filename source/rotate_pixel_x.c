/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pixel_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:04:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/03 10:27:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

float	rotate_pixel_x(int Ox, int Oy, int Mx, int My, t_data_util *d, int i, int j)
{
	float	xM, yM, x, y, angle;

	angle = 45 * M_PI / 180;
	xM = Mx - Ox; 
	yM = My - Oy;
	y = - xM * sinf(angle) + yM * cosf(angle) + Oy;
//	if (My < Oy)
//		y = y + ((Oy - y) * 0.42);
//	else
//		y = y - ((y - Oy) * 0.42);
//	return (y -= d->tab_hw[i][j] * 2);
	return (y);
}
