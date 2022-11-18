/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 08:23:27 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 16:51:38 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int	check_error(int argc, char **argv)
{
	int	i;

	if (argc != 2 || !argv[1] || !argv[1][0])
	{
		i = write(2, "\033[31;01mError - Not a good number of parameters", 47);
		i = write(2, ", need two\033[00m\n", 16);
		return (1);
	}
	(void) i;
	return (0);
}
