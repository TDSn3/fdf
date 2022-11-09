/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_nb_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:39:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/09 18:13:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

t_li *nb_nb_point(t_data_util *d)
{
	int		i;
	int		j;
	int		one_zero;
	t_li	*li;

	i = 0;
	j = 0;
	one_zero = 0;
	li = NULL;
	li_add_back(&li, li_new(d->tab_hw[i][j]));
//	printf("\n%d add\n", d->tab_hw[i][j]);
	if (d->tab_hw[i][j] == 0)
		one_zero++;
	while (i < d->tab_height)
	{
		while (j < d->tab_widht)
		{
			if (li_find_content(li, d->tab_hw[i][j]) == 0 && d->tab_hw[i][j] != 0)
			{
				li_add_back(&li, li_new(d->tab_hw[i][j]));
//				printf("\n%d add\n", d->tab_hw[i][j]);
			}
			if (li_find_content(li, d->tab_hw[i][j]) == 0 && d->tab_hw[i][j] == 0 && one_zero == 0)
			{
				li_add_back(&li, li_new(d->tab_hw[i][j]));
//				printf("\n%d add\n", d->tab_hw[i][j]);
				one_zero++;				
			}
//			printf("%d ", d->tab_hw[i][j]);
			j++;
		}
//		printf("\n");
		j = 0;
		i++;
	}

	int	li_size;

	li_size = li_size(li);
	printf("size li = %d\n", li_size);


	return (li);
}
