/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:59:24 by tda-silv          #+#    #+#             */
/*   Updated: 2022/11/10 10:54:16 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_li	*li_new(int content_one, int content_two, int content_three)
{
	t_li	*li;

	li = malloc(sizeof(t_li));
	if (!li)
		return (NULL);
	li->content_one = content_one;
	li->content_two = content_two;
	li->content_three = content_three;
	li->next = NULL;
	li->prev = NULL;
	return (li);
}
