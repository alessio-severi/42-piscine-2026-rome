/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:00:14 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/29 14:39:45 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

	j = 1;
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

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	ft_sort_strings(argv, argc);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			write (1, &argv[i][j++], 1);
		i++;
		write (1, "\n", 1);
	}
}
