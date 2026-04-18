/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:16:08 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/09 20:33:32 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putstr_option(char *str, int std);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi_option(char *str);
void	ft_print_memory(int fd, int size, int nb, char *buffer);
void	ft_read(int fd, int size, char *file_name, int argc_flag_name);
void	ft_print_error_msg(char *prog_name, char *file_name, int flag_format);
int		ft_size_buffer(int *argc, char *argv[], int *i, int *size);

#endif
