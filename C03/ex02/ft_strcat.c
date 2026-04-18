/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:47:23 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/26 01:07:57 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*start_address;

	start_address = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*(dest++) = *(src++);
	}
	*dest = 0;
	return (start_address);
}
