/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 07:05:17 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/31 19:18:21 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_seplen(char *sep)
{
	int	s;

	s = 0;
	while (sep[s])
		s++;
	return (s);
}

static int	ft_totallen_str(int size, char **strs)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			k++;
			j++;
		}
		i++;
	}
	return (k);
}

static void	ft_res(char *result, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[k++] = strs[i][j++];
		j = 0;
		if (i != size - 1)
			while (sep[j])
				result[k++] = sep[j++];
		i++;
	}
	result[k] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		s;
	int		k;
	char	*result;

	if (!size)
	{
		result = (char *)malloc(sizeof(char));
		if (!result)
			return (0);
		*result = 0;
		return (result);
	}
	s = ft_seplen(sep);
	k = ft_totallen_str(size, strs);
	result = (char *)malloc(sizeof(char) * (((size - 1) * s) + k + 1));
	if (!result)
		return (0);
	ft_res(result, size, strs, sep);
	return (result);
}
