/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:07:27 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/09 20:32:40 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putstr_option(char *str, int std)
{
	while (*str)
		write(std, str++, 1);
}

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

int	ft_atoi_option(char *str)
{
	int	number;

	number = 0;
	if (!(*str) || !(*str >= '0' && *str <= '9'))
		return (-1);
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*(str++) - '0');
	return (number);
}
