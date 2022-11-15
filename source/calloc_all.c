/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:14:29 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/15 15:24:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	calloc_pos_xy(t_data_util *d);
static int	calloc_tab_color(t_data_util *d);

int	calloc_all(t_data_util *d)
{
	int	i;

	i = 0;
	d->tab_hw = calloc(d->tab_height, sizeof(int *));
	if (!d->tab_hw)
		return (1);
	while (i < d->tab_height)
	{
		d->tab_hw[i] = calloc(d->tab_widht, sizeof(int));
		if (!d->tab_hw[i])
			return (1);
		i++;
	}
	if (calloc_tab_color(d) || calloc_pos_xy(d))
		return (1);
	return (0);
}

static int	calloc_pos_xy(t_data_util *d)
{
	int	i;

	i = 0;
	d->pos_x = calloc(d->tab_height, sizeof(int *));
	if (!d->pos_x)
		return (1);
	while (i < d->tab_height)
	{
		d->pos_x[i] = calloc(d->tab_widht, sizeof(int));
		if (!d->pos_x[i])
			return (1);
		i++;
	}
	i = 0;
	d->pos_y = calloc(d->tab_height, sizeof(int *));
	if (!d->pos_y)
		return (1);
	while (i < d->tab_height)
	{
		d->pos_y[i] = calloc(d->tab_widht, sizeof(int));
		if (!d->pos_y[i])
			return (1);
		i++;
	}
	return (0);
}

static int	calloc_tab_color(t_data_util *d)
{
	int	i;

	i = 0;
	d->tab_color = calloc(d->tab_height, sizeof(int *));
	if (!d->tab_color)
		return (1);
	while (i < d->tab_height)
	{
		d->tab_color[i] = calloc(d->tab_widht, sizeof(int));
		if (!d->tab_color[i])
			return (1);
		i++;
	}
	return (0);
}
