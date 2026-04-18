/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 03:41:43 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/10 03:55:30 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (!(*s1))
			return (0);
		s1++;
		s2++;
	}
	return (((unsigned char) *s1) - ((unsigned char) *s2));
}

void	ft_sort_strings(char **tab, int size)
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
			if (ft_strcmp(tab[i], tab[ni]) < 0)
				ni = i;
			i++;
		}
		temp = tab[j];
		tab[j] = tab[ni];
		tab[ni] = temp;
		j++;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	size;

	if (!tab)
		return ;
	size = -1;
	while (tab[++size])
		;
	ft_sort_strings(tab, size);
}
