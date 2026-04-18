/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 07:33:20 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/02 08:54:45 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_s(char c, char *charset)
{
	while (*charset)
		if (c == *charset++)
			return (1);
	return (0);
}

int	size_array_address(char *str, char *charset)
{
	int	count;
	int	start_string;

	count = 0;
	start_string = 0;
	while (*str)
	{
		if (is_s(*str, charset))
			start_string = 0;
		else if (start_string == 0)
		{
			start_string = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	*add_string(char *str, char *charset)
{
	int		s;
	char	*stringa;

	s = 0;
	while (str[s] && !is_s(str[s], charset))
		s++;
	stringa = malloc(s + 1);
	if (!stringa)
		return (0);
	stringa[s] = 0;
	while (s--)
		stringa[s] = str[s];
	return (stringa);
}

char	**ft_split(char *str, char *charset)
{
	char	**address_arr;
	int		np;
	int		start_string;
	int		size;

	size = size_array_address(str, charset);
	address_arr = malloc(sizeof(char *) * (size + 1));
	if (!address_arr)
		return (0);
	np = 0;
	start_string = 0;
	while (*str)
	{
		if (is_s(*str, charset))
			start_string = 0;
		else if (start_string == 0)
		{
			start_string = 1;
			address_arr[np++] = add_string(str, charset);
		}
		str++;
	}
	address_arr[np] = 0;
	return (address_arr);
}
/*
#include <stdio.h>

int	main()
{
	char    **address_arr;
	int 	i = 0;
	int		j = 0;

	char *size_address = "";
	char *size_address1 = "ciao";
	char *size_address2 = " ciao mondo ";
	char *size_address3 = "ciao-mondo";

	address_arr = ft_split(size_address2, " ");
	if (!address_arr)
	{
		printf("errore");
		return 0;
	}

	printf("array:\n");
	
	while (address_arr[i]){
		while (address_arr[i][j]){
			printf("%c",address_arr[i][j]);
			j++;
		}
		printf("@");
		j = 0;
		i++;
	}
	return 0;
}
*/
