/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pixel_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:04:42 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/26 13:05:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

float	rotate_pixel_y(int Ox, int Oy, int Mx, int My)
{
	float	xM, yM, x, y, angle;
	angle = 45 * M_PI / 180;
	xM = Mx - Ox; 
	yM = My - Oy;
	y = - xM * sinf(angle) + yM * cosf(angle) + Oy;
	if (My < Oy)
		y = y + ((Oy - y) * 0.42);
	else
		y = y - ((y - Oy) * 0.42);
	return (y);
}
