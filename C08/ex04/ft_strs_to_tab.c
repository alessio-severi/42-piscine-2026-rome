/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:29:59 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/06 20:31:21 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			size;
	t_stock_str	*ptr_stock_str;
	int			s1;

	s1 = sizeof(t_stock_str) * (ac + 1);
	ptr_stock_str = (t_stock_str *) malloc(s1);
	i = -1;
	while (++i < ac)
	{
		size = ft_strlen(av[i]);
		ptr_stock_str[i].size = size;
		ptr_stock_str[i].str = av[i];
		ptr_stock_str[i].copy = (char *) malloc(sizeof(char) * (size + 1));
		if (!(ptr_stock_str[i].copy))
			return (0);
		ft_strcpy(ptr_stock_str[i].copy, ptr_stock_str[i].str);
	}
	ptr_stock_str[i] = (t_stock_str){0, 0, 0};
	return (ptr_stock_str);
}
