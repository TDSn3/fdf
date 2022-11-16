/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:15:01 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/16 14:31:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	jump_color_specified(t_data_util *d, char *str, int *x_str);

int	setup_tab(t_data_util *d, const char *pathname)
{
	t_setup_tab_vars	v;
	v.fd = 0;
	v.comma = 0;
	v.x_tab = 0;
	v.y_tab = 0;
	v.x_str = 0;
	v.str = NULL;
	setup_hw_tab(d, pathname);
	if (calloc_all(d))
		return (1);
	v.fd = open(pathname, O_RDWR);
	if (v.fd == -1)
	{
		write(1, "\nOpen error\n", 12);
		return (1);
	}
	v.str = get_next_line(v.fd);
	while (v.str && v.x_tab < d->tab_height)
	{
		while (v.y_tab < d->tab_widht && v.str[v.x_str])
		{
			if (v.str[v.x_str] && ((v.str[v.x_str] >= '0' && v.str[v.x_str] <= '9') || v.str[v.x_str] == '-'))
			{
				d->tab_hw[v.x_tab][v.y_tab] = ft_atoi(v.str + v.x_str);
				d->tab_color[v.x_tab][v.y_tab] = 0x000000ff;
				while (v.str[v.x_str] && ((v.str[v.x_str] >= '0' && v.str[v.x_str] <= '9') || v.str[v.x_str] == '-' || v.str[v.x_str] == ','))
				{
					if (v.str[v.x_str] == ',')
					{
						v.comma = 1;
						d->tab_color[v.x_tab][v.y_tab] = my_atoi_hex(v.str + (++v.x_str));
						jump_color_specified(d, v.str, &v.x_str);
						continue ;
					}
					v.x_str++;
				}
				v.y_tab++;
				continue ;
			}
			v.x_str++;
		}
		v.x_str = 0;
		v.y_tab = 0;
		v.x_tab++;
		if (v.str)
		{
			free(v.str);
			v.str = NULL;
		}
		v.str = get_next_line(v.fd);
	}
	close(v.fd);
	if (v.str)
	{
		free(v.str);
		v.str = NULL;
	}
	if (v.comma == 0)
		d->li_color = nb_nb_point(d);
	square_size(d);
	return (0);
}
void	jump_color_specified(t_data_util *d, char *str, int *x_str)
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
