/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 20:36:37 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/06 20:58:31 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_end(struct s_stock_str s)
{
	return (s.size == 0 && s.str == 0 && s.copy == 0);
}

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

void	ft_putstr(char *str)
{
	while (*str)
		write (1, str++, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (!is_end(par[++i]))
	{
		ft_putnbr(par[i].size);
		write (1, "\n", 1);
		ft_putstr(par[i].str);
		write (1, "\n", 1);
		ft_putstr(par[i].copy);
		write (1, "\n", 1);
	}
}
