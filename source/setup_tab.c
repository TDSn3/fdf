/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:15:01 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/11 16:40:37 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	color_specified(t_data_util *d, char *str, int *x_str);

int	setup_tab(t_data_util *d, const char *pathname)
{
	int			fd;
	char		*str;
	int			i;
	int			comma;

	i = 0;
	comma = 0;
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
//		printf("%s\n", str);
		while (y_tab < d->tab_widht && str[x_str])
		{
			if (str[x_str] && ((str[x_str] >= '0' && str[x_str] <= '9') || str[x_str] == '-'))
			{
//				printf("%c", str[x_str]);
				d->tab_hw[x_tab][y_tab] = ft_atoi(str + x_str);
				d->tab_color[x_tab][y_tab] = -1;

				while (str[x_str] && ((str[x_str] >= '0' && str[x_str] <= '9') || str[x_str] == '-' || str[x_str] == ','))
				{
//					printf("\033[36m%c\033[00m", str[x_str]);
					if (str[x_str] == ',')
					{
						comma = 1;
						d->tab_color[x_tab][y_tab] = my_atoi_hex(str + (++x_str));
//						printf("%d ", d->tab_color[x_tab][y_tab]);
						color_specified(d, str, &x_str);
						continue ;
					}
					x_str++;
				}
				y_tab++;
				continue ;
			}
	//		printf("\033[36m%c\033[00m", str[x_str]);
			x_str++;
		}
//		printf("\n");
//		exit (1);
		x_str = 0;
		y_tab = 0;
		x_tab++;
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	close(fd);
	if (comma == 0)
		d->li_color = nb_nb_point(d);
	return (0);
}

void	color_specified(t_data_util *d, char *str, int *x_str)
{
	int j;

	j = 0;
	while (str[*x_str] && j < 8)
	{
		if ((str[*x_str] >= '0' && str[*x_str] <= '9') || str[*x_str] == 'x')
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
