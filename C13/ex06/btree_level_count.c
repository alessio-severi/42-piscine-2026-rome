/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 10:12:07 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/16 01:09:50 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	btree_level_count(t_btree *root)
{
	int	count_left;
	int	count_right;

	if (!root)
		return (0);
	count_left = btree_level_count(root->left);
	count_left++;
	count_right = btree_level_count(root->right);
	count_right++;
	if (count_left < count_right)
		count_left = count_right;
	return (count_left);
}
