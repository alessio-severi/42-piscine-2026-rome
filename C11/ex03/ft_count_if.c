/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 02:43:43 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/10 02:55:02 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;
	int	i;

	if (!tab || !f)
		return (0);
	count = 0;
	i = 0;
	while (length-- > 0)
		if (f(tab[i++]))
			count++;
	return (count);
}
