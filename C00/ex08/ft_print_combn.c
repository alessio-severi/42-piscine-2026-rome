/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:04:37 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/23 14:28:26 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_resolve_combn(char *c, int idx, int n);

void	ft_print_combn(int n)
{
	char	c[9];
	int		i;

	if (n <= 0 || n >= 10)
		return ;
	c[0] = '0' - 1;
	i = -1;
	ft_resolve_combn(c, 0, n);
}

void	ft_resolve_combn(char *c, int idx, int n)
{
	int	i_flag[2];

	while (++c[idx] <= '9' - n + 1 + idx)
	{
		if (idx != n - 1)
		{
			c[idx + 1] = c[idx];
			ft_resolve_combn(c, idx + 1, n);
		}
		else
		{
			i_flag[0] = -1;
			i_flag[1] = 0;
			while (++i_flag[0] < n)
			{
				write (1, &c[i_flag[0]], 1);
				if (c[i_flag[0]] == '9' - n + 1 + i_flag[0])
					i_flag[1]++;
			}
			if (i_flag[1] != n)
				write (1, ", ", 2);
		}
	}
}
