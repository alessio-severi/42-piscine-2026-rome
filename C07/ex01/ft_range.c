/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 21:59:47 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/31 15:51:21 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	result = (int *) malloc(sizeof(int) * (max - min));
	if (!result)
		return (0);
	while (min < max)
		result[i++] = min++;
	return (result);
}
