/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 03:53:41 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/28 05:11:18 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	index_of(char *base, char c)
{
	int	i;

	i = -1;
	while (base[++i] && base[i] != c)
		;
	if (!base[i])
		return (-1);
	return (i);
}

int	to_decimal(char *str, char *base, int i)
{
	int	sgn;
	int	number;
	int	val;

	sgn = 1;
	number = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sgn *= -1;
	while (*str)
	{
		val = index_of(base, *(str++));
		if (val == -1)
			break ;
		number = number * i + val;
	}
	return (number * sgn);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		j;

	i = -1;
	if (!base || !base[0] || !base[1])
		return (0);
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] >= '\t' && base[i] <= '\r')
			|| base[i] == 32)
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (to_decimal(str, base, i));
}
/*
#include <stdio.h>

int main (){
	printf("%d", ft_atoi_base( "FF", "0123456789ABCDEF"));
}
*/
