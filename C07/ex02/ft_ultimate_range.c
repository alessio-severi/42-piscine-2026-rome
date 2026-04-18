/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 05:01:14 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/31 15:52:24 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	*range = (int *) malloc(sizeof(int) * size);
	if (!(*range))
		return (-1);
	while (min < max)
		(*range)[i++] = min++;
	return (size);
}
