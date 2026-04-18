/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 06:10:56 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/15 07:06:21 by aseveri          ###   ########.fr       */
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

void	btree_insert_data(t_btree **root, void *item,
	int (*cmpf)(void *, void *))
{
	if (!root)
		return ;
	if (!(*root))
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		btree_insert_data(&((*root)->left), item, cmpf);
	else
		btree_insert_data(&((*root)->right), item, cmpf);
}
