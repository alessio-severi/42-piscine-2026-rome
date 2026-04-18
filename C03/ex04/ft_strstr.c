/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 01:55:16 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/29 18:45:41 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (!to_find[i])
		return (str);
	while (*str)
	{
		if (*(str++) == to_find[i])
		{
			if (!to_find[++i])
				return (str - i);
		}
		else
		{
			str = str - i;
			i = 0;
		}
	}
	return (0);
}
/*
#include <stdio.h>

char *ft_strstr(char *str, char *to_find);

int main(void)
{
    char *str = "mississippi";
    char *to_find = "issip";
    char *result;

    result = ft_strstr(str, to_find);

    if (result)
        printf("Trovato: %s\n", result);
    else
        printf("Non trovato\n");

    return (0);
}
*/
