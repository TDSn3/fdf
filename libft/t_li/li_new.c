/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/10/24 20:38:30 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_li	*li_new(int content)
{
	t_li	*ln;

	ln = malloc(sizeof(t_li));
	if (!ln)
		return (NULL);
	ln->content = content;
	ln->next = NULL;
	ln->prev = NULL;
	return (ln);
}
