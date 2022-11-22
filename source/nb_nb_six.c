/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_nb_six.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:39:07 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/18 19:56:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	nb_nb_six(int list_size, t_li *cpy_four)
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
}
