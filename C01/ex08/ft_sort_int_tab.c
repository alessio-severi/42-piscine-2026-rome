/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:22:29 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/23 15:25:53 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;
	int	ni;

	j = 0;
	while (j < size)
	{
		ni = j;
		i = j + 1;
		while (i < size)
		{
			if (tab[i] < tab[ni])
				ni = i;
			i++;
		}
		temp = tab[j];
		tab[j] = tab[ni];
		tab[ni] = temp;
		j++;
	}
}
