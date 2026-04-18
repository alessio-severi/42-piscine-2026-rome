/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:59:37 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/02 10:07:46 by aseveri          ###   ########.fr       */
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

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = -1;
	if (!base || !base[0] || !base[1])
		return (-1);
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] >= '\t' && base[i] <= '\r')
			|| base[i] == 32)
			return (-1);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (-1);
	}
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

int	nb_len(long number, int base_len)
{
	int	len;

	len = 0;
	if (number < 0)
		number = -number;
	if (number == 0)
		len++;
	while (number)
	{
		len++;
		number /= base_len;
	}
	return (len);
}
