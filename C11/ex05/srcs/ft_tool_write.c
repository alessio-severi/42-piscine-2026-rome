/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:26:17 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/17 11:38:09 by aseveri          ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	sgn;
	int	number;

	sgn = 1;
	number = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sgn *= -1;
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*(str++) - '0');
	return (number * sgn);
}
