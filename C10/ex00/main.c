/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 18:47:30 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/07 19:01:56 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define BUF_SIZE	4096

int	main(int argc, char *argv[])
{
	int		hf;
	int		nb;
	char	buffer[BUF_SIZE];

	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	else
	{
		hf = open(argv[1], O_RDONLY);
		if (hf == -1)
		{
			write(2, "Cannot read file.\n", 18);
			return (0);
		}
		nb = read(hf, buffer, BUF_SIZE);
		while (nb > 0)
		{
			write(1, buffer, nb);
			nb = read(hf, buffer, BUF_SIZE);
		}
		close(hf);
	}
	return (0);
}
