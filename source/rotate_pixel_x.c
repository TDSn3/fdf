/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_pixel_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:03:49 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/26 13:04:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

float	rotate_pixel_x(int Ox, int Oy, int Mx, int My)
{
	float	xM, yM, x, y, angle;
	angle = 45 * M_PI / 180;
	xM = Mx - Ox; 
	yM = My - Oy;
	x = xM * cosf(angle) + yM * sinf(angle) + Ox;
	return (x);
}
