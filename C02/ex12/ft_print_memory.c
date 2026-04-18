/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:23:13 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/24 18:50:23 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_core(void *addr, int j, int n);

int		ft_print_space(int j);

void	ft_print_hex(unsigned int num);

void	ft_print_address(unsigned long addr);

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*original;
	int		i;
	int		j;
	int		imax;
	int		n;

	original = addr;
	if (size == 0)
		return (addr);
	i = 0;
	j = -1;
	imax = size / 16;
	if ((size % 16) != 0)
		imax++;
	while (++i <= imax)
	{
		if (i == imax && size % 16 != 0)
			n = size % 16;
		else
			n = 16;
		ft_print_core(addr, j, n);
		addr = (unsigned char *)addr + 16;
	}
	return (original);
}

void	ft_print_core(void *addr, int j, int n)
{
	ft_print_address((unsigned long)addr);
	write (1, ":", 1);
	while (++j < n)
	{
		if (j % 2 == 0)
			write(1, " ", 1);
		if ((unsigned int)((unsigned char *)addr)[j] == 0)
			write(1, "00", 2);
		else
		{
			if ((unsigned int)((unsigned char *)addr)[j] <= 15)
				write(1, "0", 1);
			ft_print_hex((unsigned int)((unsigned char *)addr)[j]);
		}
	}
	j = ft_print_space(j);
	while (++j < n)
		if ((((unsigned char *)addr)[j] <= 31)
				|| (((unsigned char *)addr)[j] >= 127))
			write (1, ".", 1);
	else
		write (1, &((unsigned char *)addr)[j], 1);
	write (1, "\n", 1);
}

int	ft_print_space(int j)
{
	while (j < 16)
	{
		if (j % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		j++;
	}
	write (1, " ", 1);
	return (-1);
}

void	ft_print_hex(unsigned int num)
{
	int		resto;
	char	car;

	if (num == 0)
		return ;
	ft_print_hex(num / 16);
	resto = num % 16;
	if (resto >= 10)
		car = resto - 10 + 'a';
	else
		car = resto + '0';
	write(1, &car, 1);
}

void	ft_print_address(unsigned long addr)
{
	char	*hex;
	char	result[16];
	int		i;

	hex = "0123456789abcdef";
	i = 16;
	while (i--)
	{
		result[i] = hex[addr % 16];
		addr /= 16;
	}
	write(1, result, 16);
}
