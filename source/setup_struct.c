/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:02:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/16 14:40:47 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	setup_struct(t_data_util *d)
{
	d->mlx = NULL;
	d->win = NULL;
	d->img = NULL;
	d->win_widht = 0;
	d->win_height = 0;
	d->square_size = 0;
	d->tab_widht = 0;
	d->tab_height = 0;
	d->tab_hw = NULL;
	d->pos_x = NULL;
	d->pos_y = NULL;
	d->tab_color = NULL;
	d->h_point = 2;
	d->x_shift = 0;
	d->y_shift = 0;
	d->rotation = 45;
	d->projection = 0.42;
}
