/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_hw_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:40:10 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 16:52:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	setup_hw_tab(t_data_util *d, const char *pathname)
{
	int		fd;
	char	*str;

	fd = open(pathname, O_RDWR);
	if (fd == -1)
		return (1);
	str = get_next_line(fd);
	d->tab_widht = width_tab(str);
	while (str)
	{
		d->tab_height += 1;
		if (str)
			free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
