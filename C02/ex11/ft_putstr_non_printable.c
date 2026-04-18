/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 16:15:50 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/24 17:21:37 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_hex(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (c >= 32 && c < 127)
			write(1, &str[i], 1);
		else
			ft_putchar_hex(c);
		i++;
	}
}
