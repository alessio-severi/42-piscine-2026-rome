/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 06:08:08 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/12 23:18:28 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*element;

	element = (t_list *) malloc(sizeof(t_list));
	if (!element)
		return (0);
	element->data = data;
	element->next = 0;
	return (element);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*start_address;

	if (!begin_list)
		return ;
	if (!(*begin_list))
	{
		start_address = ft_create_elem(data);
		if (!start_address)
			return ;
		start_address->next = *begin_list;
		*begin_list = start_address;
	}
	else
	{
		start_address = *begin_list;
		while (start_address->next)
			start_address = start_address->next;
		start_address->next = ft_create_elem(data);
		if (!(start_address->next))
			return ;
	}
}
