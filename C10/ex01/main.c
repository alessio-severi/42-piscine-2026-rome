/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:45:01 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/08 18:57:00 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE	28672

void	ft_read(int fd)
{
	int			nb;
	static char	buffer[BUF_SIZE];

	nb = read(fd, buffer, BUF_SIZE);
	while (nb > 0)
	{
		write(1, buffer, nb);
		nb = read(fd, buffer, BUF_SIZE);
	}
}

void	ft_putstr_error(char *str)
{
	while (*str)
		write(2, str++, 1);
}

void	ft_print_error_msg(char *prog_name, char *file_name)
{
	ft_putstr_error(basename(prog_name));
	ft_putstr_error(": ");
	ft_putstr_error(file_name);
	ft_putstr_error(": ");
	ft_putstr_error(strerror(errno));
	ft_putstr_error("\n");
	errno = 0;
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

int	main(int argc, char *argv[])
{
	int		hf;
	char	*prog_name;

	prog_name = argv[0];
	if (argc == 1)
		ft_read(0);
	while (*(++argv))
	{
		if (!ft_strcmp(*argv, "-"))
		{
			ft_read(0);
			continue ;
		}
		hf = open(*argv, O_RDONLY);
		if (hf == -1)
		{
			ft_print_error_msg(prog_name, *argv);
			continue ;
		}
		ft_read(hf);
		close(hf);
	}
	return (0);
}
