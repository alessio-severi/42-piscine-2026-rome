/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 07:33:13 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/13 08:20:12 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list, t_list *end_address)
{
	if (!begin_list)
		return (0);
	while (begin_list->next != end_address)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_swap(void **a, void **b)
{
	void	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*end_address;

	if (!begin_list || !(begin_list->next))
		return ;
	end_address = 0;
	while (begin_list != end_address)
	{
		end_address = ft_list_last(begin_list, end_address);
		ft_swap(&(end_address->data), &(begin_list->data));
		begin_list = begin_list->next;
		if (begin_list->next == end_address)
			break ;
	}
}
