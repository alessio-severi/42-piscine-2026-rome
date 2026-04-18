/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 02:55:57 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/10 03:25:07 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag_crescente;
	int	flag_decrescente;

	if (!tab || !f)
		return (0);
	i = -1;
	flag_crescente = 1;
	flag_decrescente = 1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			flag_crescente = 0;
		else if (f(tab[i], tab[i + 1]) < 0)
			flag_decrescente = 0;
	}
	return (flag_crescente || flag_decrescente);
}
