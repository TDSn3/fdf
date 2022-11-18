/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssv.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 07:49:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 08:29:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	ssvpto(t_line_put_vars *vl);

//			Setup Struct Vars
void	ssv(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl)
{
	vl->i_one = v->i;
	vl->j_one = v->j;
	vl->x_one = d->pos_x[v->i][v->j] + d->square_size;
	vl->y_one = d->pos_y[v->i][v->j];
	vl->dx = vl->x_two - vl->x_one;
	vl->dy = vl->y_two - vl->y_one;
	vl->e = 0;
	vl->c_one_r = (d->tab_color[v->i][v->j] >> 16) % 256;
	vl->c_one_v = (d->tab_color[v->i][v->j] >> 8) % 256;
	vl->c_one_b = (d->tab_color[v->i][v->j]) % 256;
	vl->c_two_r = (d->tab_color[vl->i_two][vl->j_two] >> 16) % 256;
	vl->c_two_v = (d->tab_color[vl->i_two][vl->j_two] >> 8) % 256;
	vl->c_two_b = (d->tab_color[vl->i_two][vl->j_two]) % 256;
	vl->color = 0;
	ssvpto(vl);
}

//			Setup Struct Vars Part Two - One
static void	ssvpto(t_line_put_vars *vl)
{
	float	stock_color;
	float	stock_xy;

	stock_color = vl->c_two_r - vl->c_one_r;
	if (vl->x_two > vl->x_one)
	{
		stock_xy = vl->x_two - vl->x_one;
		vl->dif_x_r = stock_color / stock_xy;
		stock_color = vl->c_two_v - vl->c_one_v;
		vl->dif_x_v = stock_color / stock_xy;
		stock_color = vl->c_two_b - vl->c_one_b;
		vl->dif_x_b = stock_color / stock_xy;
	}
	else
	{
		stock_xy = vl->x_one - vl->x_two;
		vl->dif_x_r = stock_color / stock_xy;
		stock_color = vl->c_two_v - vl->c_one_v;
		vl->dif_x_v = stock_color / stock_xy;
		stock_color = vl->c_two_b - vl->c_one_b;
		vl->dif_x_b = stock_color / stock_xy;
	}
	vl->dif_xi_r = vl->dif_x_r;
	vl->dif_xi_v = vl->dif_x_v;
	vl->dif_xi_b = vl->dif_x_b;
}
