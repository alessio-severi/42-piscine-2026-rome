/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 06:35:53 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/12 10:10:28 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_reverse_tool(t_list *begin_list)
{
	t_list	*start_address;

	if (!(begin_list)->next)
		return (begin_list);
	start_address = ft_list_reverse_tool(begin_list->next);
	(begin_list->next)->next = begin_list;
	begin_list->next = 0;
	return (start_address);
}

void	ft_list_reverse(t_list **begin_list)
{
	if (!begin_list || !*begin_list)
		return ;
	*begin_list = ft_list_reverse_tool(*begin_list);
}
