/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:28:47 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/16 10:29:09 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	square_size(t_data_util *d)
{
	if (d->win_widht > d->tab_height)
		d->square_size = d->win_widht / (d->tab_widht * 2);
	else
		d->square_size = d->win_height / (d->tab_height * 2);
}
