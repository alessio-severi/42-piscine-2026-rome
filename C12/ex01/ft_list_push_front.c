/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 03:11:42 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/11 03:37:15 by aseveri          ###   ########.fr       */
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

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first_element;

	if (!begin_list)
		return ;
	first_element = ft_create_elem(data);
	if (!first_element)
		return ;
	first_element->next = *begin_list;
	*begin_list = first_element;
}
