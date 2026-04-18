/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 05:02:31 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/13 00:37:58 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next_address;

	if (!free_fct)
		return ;
	while (begin_list)
	{
		next_address = begin_list->next;
		free_fct(begin_list->data);
		free(begin_list);
		begin_list = next_address;
	}
}
