/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 01:42:32 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/10 02:26:09 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*results;
	int	i;

	if (!tab || !f || length <= 0)
		return (0);
	results = (int *) malloc(sizeof(int) * length);
	if (!results)
		return (0);
	i = -1;
	while (++i < length)
		results[i] = f(tab[i]);
	return (results);
}
