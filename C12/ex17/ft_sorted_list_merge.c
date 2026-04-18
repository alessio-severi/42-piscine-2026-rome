/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 02:59:23 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/15 03:17:48 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void	ft_sorted_list_insert_node(t_list **begin_list, t_list *node,
	int (*cmp)())
{
	t_list	*first_element;
	t_list	*virtual_list;
	t_list	*prev;
	int		flag;

	if (!cmp)
		return ;
	first_element = node;
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list	*next;

	while (begin_list2)
	{
		next = begin_list2->next;
		ft_sorted_list_insert_node(begin_list1, begin_list2, cmp);
		begin_list2 = next;
	}
}
