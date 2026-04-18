/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 04:19:16 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/12 23:23:45 by aseveri          ###   ########.fr       */
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

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*list_address;
	t_list	*next_address;
	int		i;

	if (!strs)
		return (0);
	next_address = 0;
	i = -1;
	while (++i < size)
	{
		list_address = ft_create_elem(strs[i]);
		if (!list_address)
			break ;
		list_address->next = next_address;
		next_address = list_address;
	}
	return (next_address);
}
