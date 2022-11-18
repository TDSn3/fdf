/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:00:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 19:17:13 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static int	part_two(char *str, int *i, int *width);
static void	part_three(char *str, int *i, int *width);

int	width_tab(char *str)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	if (str && str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i])
		{
			if (part_two(str, &i, &width))
				break ;
			part_three(str, &i, &width);
		}
	}
	return (width);
}

static int	part_two(char *str, int *i, int *width)
{
	if ((str[*i] <= '9' && str[*i] >= '0')
		|| str[*i] == '-'
		|| str[*i] == 'x'
		|| str[*i] == ',')
	{
		if (str[*i + 1] && str[*i + 1] == '\n')
		{
			*width += 1;
			return (1);
		}
	}
	return (0);
}

static void	part_three(char *str, int *i, int *width)
{
	if (str[*i] == ' ')
	{
		while (str[*i] == ' ')
			*i += 1;
		*width += 1;
		return ;
	}
	*i += 1;
}
