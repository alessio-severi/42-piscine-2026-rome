/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:48:28 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/28 01:22:36 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_number(long number)
{
	char	c;

	if (number > 9)
		print_number(number / 10);
	c = (number % 10) + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	number;

	number = nb;
	if (number < 0)
	{
		write (1, "-", 1);
		number = -number;
	}
	print_number(number);
}
