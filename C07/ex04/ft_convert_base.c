/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:53:41 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/02 10:06:40 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		index_of(char *base, char c);
int		is_valid_base(char *base);
int		to_decimal(char *str, char *base, int i);
int		nb_len(long n, int base_len);

static int	result(char *res, long number, char *base, int base_len)
{
	int	pos;

	pos = 0;
	if (number >= base_len)
		pos = result(res, number / base_len, base, base_len);
	res[pos] = base[number % base_len];
	return (pos + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		from_len;
	int		to_len;
	long	number;
	char	*res;
	int		size;

	from_len = is_valid_base(base_from);
	to_len = is_valid_base(base_to);
	if (from_len == -1 || to_len == -1)
		return (0);
	number = to_decimal(nbr, base_from, from_len);
	size = nb_len(number, to_len) + (number < 0) + 1;
	res = (char *) malloc(sizeof(char) * size);
	if (!res)
		return (0);
	if (number < 0)
	{
		res[0] = '-';
		res[result(res + 1, -number, base_to, to_len) + 1] = 0;
	}
	else
		res[result(res, number, base_to, to_len)] = 0;
	return (res);
}
