/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:33:13 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/15 02:36:28 by aseveri          ###   ########.fr       */
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

int	ft_try_insert_at(t_list **begin_list, int flag,
	int (*cmp)(), t_list *first_element)
{
	if (!begin_list)
		return (1);
	if (!*begin_list
		|| cmp(first_element->data, (*begin_list)->data) < 0)
	{
		first_element->next = *begin_list;
		if (flag)
			return (2);
		*begin_list = first_element;
		return (2);
	}
	return (0);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data,
	int (*cmp)())
{
	t_list	*first_element;
	t_list	*virtual_list;
	t_list	*prev;
	int		flag;

	if (!cmp)
		return ;
	first_element = ft_create_elem(data);
	if (!first_element)
		return ;
	flag = 0;
	if (ft_try_insert_at(begin_list, flag, cmp, first_element))
		return ;
	virtual_list = *begin_list;
	flag = 1;
	while (1)
	{
		prev = virtual_list;
		virtual_list = virtual_list->next;
		if (ft_try_insert_at(&virtual_list, flag, cmp, first_element))
		{
			prev->next = first_element;
			break ;
		}
	}
}
