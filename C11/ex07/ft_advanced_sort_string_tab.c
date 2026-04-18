/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 03:59:42 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/10 04:11:22 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_strings(char **tab, int size, int (*cmp)(char *, char *))
{
	char	*temp;
	int		i;
	int		j;
	int		ni;

	j = 0;
	while (j < size)
	{
		ni = j;
		i = j + 1;
		while (i < size)
		{
			if (cmp(tab[i], tab[ni]) < 0)
				ni = i;
			i++;
		}
		temp = tab[j];
		tab[j] = tab[ni];
		tab[ni] = temp;
		j++;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;

	if (!tab || !cmp)
		return ;
	size = -1;
	while (tab[++size])
		;
	ft_sort_strings(tab, size, cmp);
}
