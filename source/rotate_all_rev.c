/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_all_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:17:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 11:41:58 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	b(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl);
static void	use_tab_for_line_put(t_data_util *d);
static void	setup_vars(t_data_util *d, t_rotate_all_vars *v);

void	rotate_all_rev(t_data_util *d)
{
	t_rotate_all_vars	v;
	int					h;
	int					w;

	setup_vars(d, &v);
	while (v.i < v.h)
	{
		while (v.j < v.w)
		{
			h = v.win_h_div - (((v.h / 2) + 0.5) * d->square_size);
			w = v.win_w_div - (((v.w / 2) + 0.5) * d->square_size);
			v.x_o = h + (v.i * d->square_size);
			v.y_o = w + (v.j * d->square_size);
			v.x_next = h + ((v.i + 1) * d->square_size);
			v.y_next = w + ((v.j + 1) * d->square_size);
			d->pos_x[v.i][v.j] = rotate_pixel_x(d, &v);
			d->pos_y[v.i][v.j] = rotate_pixel_y(d, &v);
			v.j++;
		}
		v.j = 0;
		v.i++;
	}
	v.i = 0;
	v.j = 0;
	use_tab_for_line_put(d);
}

static void	use_tab_for_line_put(t_data_util *d)
{
	t_rotate_all_vars	v;
	t_line_put_vars		vl;

	setup_vars(d, &v);
	v.i = v.h -1;
	v.j = v.w - 1;
	while (v.i > -1)
	{
		while (v.j > -1)
		{
			b(d, &v, &vl);
			v.j--;
		}
		v.j = v.w - 1;
		v.i--;
	}
}

static void	b(t_data_util *d, t_rotate_all_vars *v, t_line_put_vars *vl)
{
	if (v->i - 1 > -1)
	{
		first_setup_line_put_vars_xy(vl,
			d->pos_x[v->i - 1][v->j] + d->square_size,
			d->pos_y[v->i - 1][v->j]);
		first_setup_line_put_vars_ij(vl, v->i - 1, v->j);
		line_put(d, v, vl);
	}
	if (v->j - 1 > -1)
	{
		first_setup_line_put_vars_xy(vl,
			d->pos_x[v->i][v->j - 1] + d->square_size,
			d->pos_y[v->i][v->j - 1]);
		first_setup_line_put_vars_ij(vl, v->i, v->j - 1);
		line_put(d, v, vl);
	}
}

static void	setup_vars(t_data_util *d, t_rotate_all_vars *v)
{
	v->i = 0;
	v->j = 0;
	v->w = d->tab_widht;
	v->h = d->tab_height;
	v->win_h_div = ((float)(d->win_height) / 2) + 0.5;
	v->win_w_div = ((float)(d->win_widht) / 2) + 0.5;
	v->x_o = 0;
	v->y_o = 0;
	v->x_next = 0;
	v->y_next = 0;
}
