/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:28:59 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/13 05:16:36 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
#define MODE_0	0
#define MODE_1 1

t_list	*ft_list_remove(t_list *begin_list_copy, void (*free_fct)(void *))
{
	t_list	*next_address;

	next_address = begin_list_copy->next;
	free_fct(begin_list_copy->data);
	free(begin_list_copy);
	return (next_address);
}

void	ft_control_last_address(int mode, t_list **last_address,
	t_list *begin_list_copy)
{
	if (!mode)
	{
		if (*last_address)
			(*last_address)->next = 0;
	}
	else
	{
		if (*last_address)
			(*last_address)->next = begin_list_copy;
		*last_address = begin_list_copy;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
	void (*free_fct)(void *))
{
	t_list	*begin_list_copy;
	t_list	*last_address;

	if (!cmp || !free_fct || !begin_list)
		return ;
	begin_list_copy = *begin_list;
	last_address = 0;
	while (begin_list_copy)
	{
		if (!cmp(begin_list_copy->data, data_ref))
		{
			begin_list_copy = ft_list_remove(begin_list_copy, free_fct);
			ft_control_last_address(MODE_0, &last_address, begin_list_copy);
		}
		else
		{
			if (!last_address)
				*begin_list = begin_list_copy;
			ft_control_last_address(MODE_1, &last_address, begin_list_copy);
			begin_list_copy = begin_list_copy->next;
		}
	}
	if (!last_address)
		*begin_list = 0;
}
