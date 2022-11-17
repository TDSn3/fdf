/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:15:01 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/17 00:28:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

static void	jump_color_specified(
				t_data_util *d,
				char *str,
				int *x_str,
				t_setup_tab_vars *v);
static void	part_two(t_data_util *d, t_setup_tab_vars *v);
static void	body(t_data_util *d, t_setup_tab_vars *v);

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
	body(d, &v);
	return (0);
}

static void	jump_color_specified(
t_data_util *d,
char *str,
int *x_str,
t_setup_tab_vars *v)
{
	int	j;

	j = 0;
	v->comma = 1;
	d->tab_color[v->x_tab][v->y_tab] = my_atoi_hex(v->str + ++v->x_str);
	while (str[*x_str] && j < 8)
	{
		if ((str[*x_str] >= '0' && str[*x_str] <= '9') || str[*x_str] == 'x')
			j++;
		else if (str[*x_str] >= 'A' && str[*x_str] <= 'F')
			j++;
		else if (str[*x_str] >= 'a' && str[*x_str] <= 'f')
			j++;
		else
			break ;
		*x_str += 1;
	}
}

static void	part_two(t_data_util *d, t_setup_tab_vars *v)
{
	while (v->y_tab < d->tab_widht && v->str[v->x_str])
	{
		if (v->str[v->x_str] && ((v->str[v->x_str] >= '0'
					&& v->str[v->x_str] <= '9') || v->str[v->x_str] == '-'))
		{
			d->tab_hw[v->x_tab][v->y_tab] = ft_atoi(v->str + v->x_str);
			d->tab_color[v->x_tab][v->y_tab] = 0x000000ff;
			while (v->str[v->x_str] && ((v->str[v->x_str] >= '0'
						&& v->str[v->x_str] <= '9') || v->str[v->x_str] == '-'
					|| v->str[v->x_str] == ','))
			{
				if (v->str[v->x_str] == ',')
				{
					jump_color_specified(d, v->str, &v->x_str, v);
					continue ;
				}
				v->x_str += 1;
			}
			v->y_tab += 1;
			continue ;
		}
		v->x_str++;
	}
}

static void	body(t_data_util *d, t_setup_tab_vars *v)
{
	while (v->str && v->x_tab < d->tab_height)
	{
		part_two(d, v);
		v->x_str = 0;
		v->y_tab = 0;
		v->x_tab++;
		if (v->str)
		{
			free(v->str);
			v->str = NULL;
		}
		v->str = get_next_line(v->fd);
	}
	close(v->fd);
	if (v->str)
	{
		free(v->str);
		v->str = NULL;
	}
	if (v->comma == 0)
		d->li_color = nb_nb_point(d);
	square_size(d);
}
