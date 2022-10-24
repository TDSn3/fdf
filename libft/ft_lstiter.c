/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 11:52:44 by tda-silv          #+#    #+#             */
/*   Updated: 2022/03/21 10:42:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>

void	f(void *lst)
{
	printf("\n%d\n", lst);	
}

int	main()
{
	t_list	*a;

	a = ft_lstnew((int *)5);
	ft_lstiter(a, f);
	printf("\n%d\n", a->content);
	return (0);
}
*/
