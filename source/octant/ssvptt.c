/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssvptt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 07:51:23 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 08:30:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

//			Setup Struct Vars Part Two - Two
void	ssvptt(t_line_put_vars *vl)
{
	float	stock_color;
	float	stock_xy;

	stock_color = vl->c_two_r - vl->c_one_r;
	if (vl->y_two > vl->y_one)
	{
		stock_xy = vl->y_two - vl->y_one;
		vl->dif_y_r = stock_color / stock_xy;
		stock_color = vl->c_two_v - vl->c_one_v;
		vl->dif_y_v = stock_color / stock_xy;
		stock_color = vl->c_two_b - vl->c_one_b;
		vl->dif_y_b = stock_color / stock_xy;
	}
	else
	{
		stock_xy = vl->y_one - vl->y_two;
		vl->dif_y_r = stock_color / stock_xy;
		stock_color = vl->c_two_v - vl->c_one_v;
		vl->dif_y_v = stock_color / stock_xy;
		stock_color = vl->c_two_b - vl->c_one_b;
		vl->dif_y_b = stock_color / stock_xy;
	}
	vl->dif_yi_r = vl->dif_y_r;
	vl->dif_yi_v = vl->dif_y_v;
	vl->dif_yi_b = vl->dif_y_b;
}
