/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:57:54 by aseveri           #+#    #+#             */
/*   Updated: 2026/03/24 17:14:45 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	flag;
	int	i;

	flag = 1;
	i = -1;
	while (str[++i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (flag && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - ('a' - 'A');
			else if (!flag && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + ('a' - 'A');
		}
		else if (!(str[i] >= '0' && str[i] <= '9'))
		{
			flag = 1;
			continue ;
		}
		flag = 0;
	}
	return (str);
}
