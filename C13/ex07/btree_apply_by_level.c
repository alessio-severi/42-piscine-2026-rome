/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 01:34:29 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/16 07:25:01 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_queue	*ft_create_elem(t_btree *node, int level)
{
	t_queue	*element;

	element = (t_queue *) malloc(sizeof(t_queue));
	if (!element)
		return (0);
	element->node = node;
	element->level = level;
	element->next = 0;
	return (element);
}

int	ft_queue_add(t_queue **begin_queue, t_btree *node, int level)
{
	t_queue	*start_address;

	if (!begin_queue)
		return (1);
	if (!(*begin_queue))
	{
		start_address = ft_create_elem(node, level);
		if (!start_address)
			return (1);
		*begin_queue = start_address;
	}
	else
	{
		start_address = *begin_queue;
		while (start_address->next)
			start_address = start_address->next;
		start_address->next = ft_create_elem(node, level);
		if (!(start_address->next))
			return (1);
	}
	return (0);
}

void	ft_queue_remove(t_queue **begin_queue)
{
	t_queue	*temp;

	temp = *begin_queue;
	*begin_queue = (*begin_queue)->next;
	free(temp);
}

int	ft_list_clear(t_queue *begin_queue)
{
	t_queue	*next_address;

	while (begin_queue)
	{
		next_address = begin_queue->next;
		free(begin_queue);
		begin_queue = next_address;
	}
	return (0);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
	int current_level, int is_first_elem))
{
	t_queue	*begin_queue;
	int		flag_level;

	if (!root || !applyf)
		return ;
	begin_queue = 0;
	flag_level = -1;
	if (ft_queue_add(&begin_queue, root, 0))
		return ;
	while (begin_queue)
	{
		if ((begin_queue->node)->left && ft_queue_add(&begin_queue,
				(begin_queue->node)->left, (begin_queue->level) + 1)
			&& !ft_list_clear(begin_queue))
			return ;
		if ((begin_queue->node)->right && ft_queue_add(&begin_queue,
				(begin_queue->node)->right, (begin_queue->level) + 1)
			&& !ft_list_clear(begin_queue))
			return ;
		if (flag_level < begin_queue->level)
			applyf((begin_queue->node)->item, ++flag_level, 1);
		else
			applyf((begin_queue->node)->item, flag_level, 0);
		ft_queue_remove(&begin_queue);
	}
}
