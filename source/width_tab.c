/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 06:00:53 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/28 09:24:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int width_tab(char *str)
{
	int	i;
	int	width;
	
	i = 0;
	width = 0;
	while (str[i])
	{
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == '-' ||  str[i] == 'x' || str[i] == ',')
		{
			if (str[i + 1] && str[i + 1] == '\n')
			{
				width++;
				break ;
			}
		}
		else if (str[i] == ' ')
		{
			while (str[i] == ' ')
				i++;
			width++;
			continue ;
		}
		else
			return (-1);
		i++;
	}
	return (width);
}
