/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 03:32:48 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/28 09:16:53 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	control(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	char			*start_src;
	char			*start_dest;

	i = 0;
	start_dest = dest;
	start_src = src;
	if (!size || !dest)
		return (size + control(src));
	while (i < size && dest[i])
		i++;
	dest = dest + i;
	while (*src)
	{
		if ((unsigned int)(dest - start_dest + 1) < size)
			*(dest++) = *src;
		src++;
	}
	if (i < size)
		*dest = 0;
	if (i < size)
		return ((unsigned int)(src - start_src) + i);
	return ((unsigned int)(src - start_src) + size);
}
