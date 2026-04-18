/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:42:02 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/23 15:03:09 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb2(char *c, int size);

void	ft_print_comb2(void)
{
	char	c[4];
	int		flag;

	c[0] = '0' - 1;
	while (++c[0] <= '9')
	{
		c[1] = '0' - 1;
		while (++c[1] <= '9')
		{
			flag = 1;
			c[2] = c[0] - 1;
			while (++c[2] <= '9')
			{
				if (flag)
				{
					c[3] = c[1];
					flag = 0;
				}
				while (++c[3] <= '9')
					print_comb2(c, 4);
				c[3] = '0' - 1;
			}
		}
	}
}

void	print_comb2(char *c, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		write(1, &c[i], 1);
		if (i == 1)
			write(1, " ", 1);
	}
	if (!(c[0] == '9' && c[1] == '8'
			&& c[2] == '9' && c[3] == '9'))
		write (1, ", ", 2);
}
