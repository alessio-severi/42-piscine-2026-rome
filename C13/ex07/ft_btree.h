/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 01:18:44 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/16 06:55:15 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	void			*item;
	struct s_btree	*left;
	struct s_btree	*right;
}	t_btree;

typedef struct s_queue
{
	t_btree			*node;
	int				level;
	struct s_queue	*next;
}	t_queue;

#endif
