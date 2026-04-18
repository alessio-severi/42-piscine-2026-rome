/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:13:06 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/14 07:24:06 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_swap(t_list **a, t_list **b, t_list *prev[])
{
	t_list	*temp;

	if (prev[0])
		prev[0]->next = *b;
	temp = (*b)->next;
	if (prev[1] != *a)
	{
		(*b)->next = (*a)->next;
		prev[1]->next = *a;
	}
	else
		(*b)->next = *a;
	(*a)->next = temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return (*a);
}

t_list	*ft_find_ordinato(t_list *begin_list_copy, t_list *prev[], int (*cmp)())
{
	t_list	*start_ordinare;
	t_list	*ordinato;
	t_list	*prev_start_ordinare;

	ordinato = begin_list_copy;
	prev_start_ordinare = begin_list_copy;
	start_ordinare = begin_list_copy->next;
	while (start_ordinare)
	{
		if (cmp(start_ordinare->data, ordinato->data) < 0)
		{
			ordinato = start_ordinare;
			prev[1] = prev_start_ordinare;
		}
		prev_start_ordinare = start_ordinare;
		start_ordinare = start_ordinare->next;
	}
	return (ordinato);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ordinato;
	t_list	*begin_list_copy;
	t_list	*prev[2];

	if (!begin_list || !cmp)
		return ;
	begin_list_copy = *begin_list;
	prev[0] = 0;
	while (begin_list_copy)
	{
		ordinato = ft_find_ordinato(begin_list_copy, prev, cmp);
		if (begin_list_copy != ordinato)
		{
			if (*begin_list == begin_list_copy)
				prev[0] = ft_list_swap(begin_list, &ordinato, prev);
			else
				prev[0] = ft_list_swap(&begin_list_copy, &ordinato, prev);
		}
		else
			prev[0] = begin_list_copy;
		begin_list_copy = prev[0]->next;
	}
}
