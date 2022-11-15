/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:16 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/15 16:02:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	free_all(t_data_util *d)
{
	int	i;

	i = 0;
	if (d->tab_hw)
	{
		while (i < d->tab_height)
			free(d->tab_hw[i++]);
		free(d->tab_hw);
	}
	i = 0;
	if (d->tab_color)
	{
		while (i < d->tab_height)
			free(d->tab_color[i++]);
		free(d->tab_color);
	}
	i = 0;
	if (d->pos_x)
	{
		while (i < d->tab_height)
			free(d->pos_x[i++]);
		free(d->pos_x);
	}
		i = 0;
	if (d->pos_y)
	{
		while (i < d->tab_height)
			free(d->pos_y[i++]);
		free(d->pos_y);
	}
	if (d->li_color)
	{
		printf("li_color clear\n");
		li_clear(&d->li_color);
	}
}
