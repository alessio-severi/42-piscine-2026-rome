/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 06:30:30 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/13 06:44:35 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	if (!begin_list)
		return (0);
	while (begin_list->next)
		begin_list = begin_list->next;
	return (begin_list);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*last_address;

	if (!begin_list1)
		return ;
	last_address = ft_list_last(*begin_list1);
	if (!last_address)
		*begin_list1 = begin_list2;
	else
		last_address->next = begin_list2;
}
