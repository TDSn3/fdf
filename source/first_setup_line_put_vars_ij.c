/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_setup_line_put_vars_ij.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:02:06 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/17 10:09:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

void	first_setup_line_put_vars_ij(t_line_put_vars *v, int i_two, int j_two)
{
	v->i_two = i_two;
	v->j_two = j_two;
}
