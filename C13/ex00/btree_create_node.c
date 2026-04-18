/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 04:26:16 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/15 04:31:13 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = (t_btree *) malloc(sizeof(t_btree));
	if (!node)
		return (0);
	node->item = item;
	node->left = 0;
	node->right = 0;
	return (node);
}
