/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseveri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:55:40 by aseveri           #+#    #+#             */
/*   Updated: 2026/04/17 16:10:32 by aseveri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_do_op.h"

int	(*ft_select_operator(char op))(int a, int b)
{
	char	*str_operators;
	int		(*operators[5])(int, int);
	int		i;

	str_operators = "+-*/%";
	operators[0] = ft_add;
	operators[1] = ft_minus;
	operators[2] = ft_multiply;
	operators[3] = ft_divide;
	operators[4] = ft_modulo;
	i = -1;
	while (++i < 5)
		if (op == str_operators[i])
			return (operators[i]);
	write(1, "0\n", 2);
	return (0);
}

int	ft_is_valid_operation(char op, int b)
{
	if (op == '/' && b == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (op == '%' && b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int	a;
	int	b;
	int	(*f)(int, int);

	if (argc != 4)
		return (0);
	if (argv[2][1])
	{
		write(1, "0\n", 2);
		return (0);
	}
	f = ft_select_operator(argv[2][0]);
	if (!f)
		return (0);
	b = ft_atoi(argv[3]);
	if (!ft_is_valid_operation(argv[2][0], b))
		return (0);
	a = ft_atoi(argv[1]);
	ft_putnbr(f(a, b));
	write(1, "\n", 1);
	return (0);
}
