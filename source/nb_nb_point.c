/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_nb_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:39:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/10 11:16:25 by tda-silv         ###   ########.fr       */
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
	li_add_back(&li, li_new(d->tab_hw[i][j], -1, -1));
//	printf("\n%d add\n", d->tab_hw[i][j]);
	if (d->tab_hw[i][j] == 0)
		one_zero++;
	while (i < d->tab_height)
	{
		while (j < d->tab_widht)
		{
			if (li_find_content(li, d->tab_hw[i][j]) == 0 && d->tab_hw[i][j] != 0)
			{
				li_add_back(&li, li_new(d->tab_hw[i][j], -1, -1));
//				printf("\n%d add\n", d->tab_hw[i][j]);
			}
			if (li_find_content(li, d->tab_hw[i][j]) == 0 && d->tab_hw[i][j] == 0 && one_zero == 0)
			{
				li_add_back(&li, li_new(d->tab_hw[i][j], -1, -1));
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

//	int	i;
	int pos;
	int	list_size;
	t_li	*cpy_one;
	t_li	*cpy_two;

	i = 0;
	pos = 0;
	list_size = li_size(li);
	cpy_one = li;
	printf("size li = %d\n", list_size);

	while (cpy_one)
	{
		pos = cpy_one->content_one;
		cpy_two = li;
		while (cpy_two)
		{
			if (cpy_two->content_one > pos)
				i++;
			cpy_two = cpy_two->next;
		}
		cpy_one->content_two = i;
		i = 0;
		cpy_one = cpy_one->next;
	}

	for (t_li *cpy_three = li; cpy_three; cpy_three = cpy_three->next)
	{
		printf("%d %d\n", cpy_three->content_one, cpy_three->content_two);
	}



	t_li	*cpy_four;

	cpy_four = li;
	while (cpy_four)
	{
		cpy_four->content_three = (list_size / 255) * cpy_four->content_two;
		cpy_four = cpy_four->next;
	}

	for (t_li *cpy_three = li; cpy_three; cpy_three = cpy_three->next)
	{
		printf("%d\t%d\t%d\n", cpy_three->content_one, cpy_three->content_two, cpy_three->content_three);
	}

	return (li);
}
