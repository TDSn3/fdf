/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_nb_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:39:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 19:56:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	part_two(t_data_util *d, int one_zero, t_li *li);
static void	part_three(t_li *li);
static t_li	*part_four(t_li *li);
static void	part_five(t_data_util *d, t_li *part_five, t_li *li);

t_li	*nb_nb_point(t_data_util *d)
{
	t_li	*li;

	li = NULL;
	li_add_back(&li, li_new(d->tab_hw[0][0], -1));
	part_two(d, (d->tab_hw[0][0] == 0), li);
	part_three(li);
	part_five(d, part_four(li), li);
	return (li);
}

static void	part_two(t_data_util *d, int one_zero, t_li *li)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < d->tab_height)
	{
		while (j < d->tab_widht)
		{
			if (li_find_content(li, d->tab_hw[i][j]) == 0
					&& d->tab_hw[i][j] != 0)
			{
				li_add_back(&li, li_new(d->tab_hw[i][j], -1));
			}
			if (li_find_content(li, d->tab_hw[i][j]) == 0
				&& d->tab_hw[i][j] == 0 && one_zero == 0)
			{
				li_add_back(&li, li_new(d->tab_hw[i][j], -1));
				one_zero++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static void	part_three(t_li *li)
{
	int		i;
	int		pos;
	t_li	*cpy_one;
	t_li	*cpy_two;

	i = 0;
	pos = 0;
	cpy_one = li;
	while (cpy_one)
	{
		pos = cpy_one->content_one;
		cpy_two = li;
		while (cpy_two)
		{
			if (cpy_two->content_one < pos)
				i++;
			cpy_two = cpy_two->next;
		}
		cpy_one->content_two = i;
		i = 0;
		cpy_one = cpy_one->next;
	}
}

static t_li	*part_four(t_li *li)
{
	int		list_size;
	t_li	*cpy_four;

	cpy_four = li;
	list_size = li_size(li);
	while (cpy_four)
	{
		if (list_size > 1)
		{
			cpy_four->content_three = ((0x00000000 / (list_size - 1))
					* (cpy_four->content_two + 0)) << 16;
			cpy_four->content_four = ((0x00000000 / (list_size - 1))
					* (cpy_four->content_two + 0)) << 8;
			cpy_four->content_five = (0x000000ff / (list_size - 1))
				* (cpy_four->content_two + 0);
		}
		else if (list_size == 1)
		{
			cpy_four->content_three = 0x00000000 << 16;
			cpy_four->content_four = 0x00000000 << 8;
			cpy_four->content_five = 0x000000ff;
		}
		else
			exit (1);
		if (cpy_four->content_three == 0
			&& cpy_four->content_four == 0
			&& cpy_four->content_five == 0)
		{
			cpy_four->content_three = 0x00aa0000;
			cpy_four->content_four = 0x0000ff00;
			cpy_four->content_five = 0x000000ff;
		}
		cpy_four = cpy_four->next;
	}
	return (cpy_four);
}

static void	part_five(t_data_util *d, t_li *cpy_four, t_li *li)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < d->tab_height)
	{
		while (j < d->tab_widht)
		{
			cpy_four = li;
			while (cpy_four->content_one != d->tab_hw[i][j])
				cpy_four = cpy_four->next;
			d->tab_color[i][j] = cpy_four->content_three
				+ cpy_four->content_four + cpy_four->content_five;
			j++;
		}
		j = 0;
		i++;
	}
}
