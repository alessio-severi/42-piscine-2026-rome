/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 09:18:04 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/15 10:10:59 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	void	*result_ref;

	if (!root)
		return (0);
	result_ref = btree_search_item(root->left, data_ref, cmpf);
	if (result_ref)
		return (result_ref);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	result_ref = btree_search_item(root->right, data_ref, cmpf);
	if (result_ref)
		return (result_ref);
	return (0);
}
