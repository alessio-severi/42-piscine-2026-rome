/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 19:53:47 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/09 20:36:54 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_print_memory(int fd, int size, int nb, char *buffer)
{
	int		shift;
	int		full;

	shift = 0;
	full = 0;
	while (nb > 0)
	{
		nb = read(fd, buffer + shift, size - shift);
		if (nb < 0)
			break ;
		shift += nb;
		if (shift == size)
		{
			full = 1;
			shift = 0;
		}
	}
	if (full)
	{
		write(1, buffer + shift, size - shift);
		if (shift)
			write(1, buffer, shift);
	}
	else
		write(1, buffer, shift);
}

void	ft_read(int fd, int size, char *file_name, int argc_flag_name)
{
	int			nb;
	static int	new_line_flag;
	char		*buffer;

	nb = 1;
	buffer = (char *) malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return ;
	if (argc_flag_name > 1)
	{
		if (new_line_flag)
			ft_putstr_option("\n", 1);
		ft_putstr_option("==> ", 1);
		ft_putstr_option(file_name, 1);
		ft_putstr_option(" <==\n", 1);
		new_line_flag = 1;
	}
	ft_print_memory(fd, size, nb, buffer);
	free(buffer);
}

void	ft_print_error_msg(char *prog_name, char *file_name, int flag_format)
{
	ft_putstr_option(basename(prog_name), 2);
	ft_putstr_option(": ", 2);
	if (flag_format)
	{
		ft_putstr_option(file_name, 2);
		ft_putstr_option(": ", 2);
		ft_putstr_option(strerror(errno), 2);
	}
	else
	{
		ft_putstr_option("illegal offset -- ", 2);
		ft_putstr_option(file_name, 2);
	}
	ft_putstr_option("\n", 2);
	errno = 0;
}

int	ft_size_buffer(int *argc, char *argv[], int *i, int *size)
{
	*i = 1;
	if (!ft_strcmp(argv[*i], "-c"))
	{
		*size = ft_atoi_option(argv[++(*i)]);
		if (*size == -1)
		{
			ft_print_error_msg(argv[0], argv[*i], 0);
			return (0);
		}
		*argc = *argc - 3;
	}
	else
	{
		*size = ft_atoi_option(argv[*i] + 2);
		if (*size == -1)
		{
			ft_print_error_msg(argv[0], argv[*i] + 2, 0);
			return (0);
		}
		*argc = *argc - 2;
	}
	return (*size);
}

int	main(int argc, char *argv[])
{
	int		hf;
	int		i;
	int		size;

	if (!ft_size_buffer(&argc, argv, &i, &size))
		return (0);
	if (!argc)
		ft_read(0, size, "", argc);
	while (argv[++i])
	{
		if (!ft_strcmp(argv[i], "-"))
		{
			ft_read(0, size, "-", argc);
			continue ;
		}
		hf = open(argv[i], O_RDONLY);
		if (hf == -1)
		{
			ft_print_error_msg(argv[0], argv[i], 1);
			continue ;
		}
		ft_read(hf, size, argv[i], argc);
		close(hf);
	}
	return (0);
}
