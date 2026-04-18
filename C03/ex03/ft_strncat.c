/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 01:09:18 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/26 01:43:16 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*start_address;

	i = 0;
	start_address = dest;
	while (*dest)
	{
		dest++;
	}
	while (i < nb && src[i])
	{
		*(dest++) = src[i++];
	}
	*dest = '\0';
	return (start_address);
}
