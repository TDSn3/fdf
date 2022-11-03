/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:15:01 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/02 20:39:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	color_specified(t_data_util *d, char *str, int *x_str);

int	setup_tab(t_data_util *d, const char *pathname)
{
	int			fd;
	char		*str;
	int			i;

	i = 0;
	setup_hw_tab(d, pathname);
	d->tab_hw = malloc(d->tab_height * sizeof(int*));
	if (!d->tab_hw)
		return (1);
	while (i < d->tab_height)
	{
		d->tab_hw[i] = malloc(d->tab_widht * sizeof(int));
		if (!d->tab_hw[i])
			return (1);	
		i++;
	}
	i = 0;
	d->tab_color = malloc(d->tab_height * sizeof(int*));
	if (!d->tab_color)
		return (1);
	while (i < d->tab_height)
	{
		d->tab_color[i] = malloc(d->tab_widht * sizeof(int));
		if (!d->tab_color[i])
			return (1);	
		i++;
	}

	int x_tab = 0;
	int y_tab = 0;
	int x_str = 0;

	fd = open(pathname, O_RDWR);
	if (fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (1);
	}
	str = get_next_line(fd);
	while (str && x_tab < d->tab_height)
	{
		while (y_tab < d->tab_widht && str[x_str])
		{
			if (str[x_str] && ((str[x_str] >= '0' && str[x_str] <= '9') || str[x_str] == '-'))
			{
//				printf("%d ", ft_atoi(str + x_str));
				d->tab_hw[x_tab][y_tab] = ft_atoi(str + x_str);
				d->tab_color[x_tab][y_tab] = 0x00FFFFFF - d->tab_hw[x_tab][y_tab];
				while (str[x_str] && ((str[x_str] >= '0' && str[x_str] <= '9') || str[x_str] == '-' || str[x_str] == ','))
				{
					if (str[x_str] == ',')
					{
						d->tab_color[x_tab][y_tab] = my_atoi_hex(str + (++x_str));
						color_specified(d, str, &x_str);
						continue ;
					}
					x_str++;
				}
				y_tab++;
				continue ;
			}
			x_str++;
		}
//		printf("\n");
		x_str = 0;
		y_tab = 0;
		x_tab++;
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}

void	color_specified(t_data_util *d, char *str, int *x_str)
{
	int j;

	j = 0;
	while (j < 8 && str[*x_str])
	{
		if ((str[*x_str] >= '0' && str[*x_str] <= '9') || str[*x_str] <= 'x')
			j++;
		else if (str[*x_str] >= 'A' && str[*x_str] <= 'F')
			j++;
		else if (str[*x_str] >= 'a' && str[*x_str] <= 'f')
			j++;
		else
			break;
		*x_str += 1;
	}
}
