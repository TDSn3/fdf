/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:02:12 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/30 14:24:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	setup_struct(t_data_util *d)
{
	d->win_widht = 0;
	d->win_height = 0;
	d->square_size = 0;
	d->tab_widht = 0;
	d->tab_height = 0;
	d->tab_hw = NULL;
	d->tab_color = NULL;
}
