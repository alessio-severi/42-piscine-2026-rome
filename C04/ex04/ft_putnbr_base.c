/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 01:57:42 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/28 03:32:17 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(long number, char *base, int i)
{
	char	c;

	if (number >= i)
		print_number(number / i, base, i);
	c = base[number % i];
	write (1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		j;
	long	number;

	number = nbr;
	i = -1;
	if (!base || !base[0] || !base[1])
		return ;
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+')
			return ;
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return ;
	}
	if (number < 0)
	{
		write (1, "-", 1);
		number = -number;
	}
	print_number(number, base, i);
}
/*
int	main(){

	ft_putnbr_base(10, "0123456789ABCDEF");
	return 0;
}
*/
