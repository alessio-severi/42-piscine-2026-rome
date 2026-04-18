/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:09:04 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/26 00:37:31 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == s2[i])
		{
			if (!(s1[i]))
				return (0);
			i++;
		}
		else
			return (((unsigned char) s1[i]) - ((unsigned char) s2[i]));
	}
	return (0);
}
