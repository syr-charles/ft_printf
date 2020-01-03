/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:02:17 by cdana             #+#    #+#             */
/*   Updated: 2020/01/03 12:51:46 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_blank(char c, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_print_mod(t_arg *arg)
{
	char	c;

	c = ' ';
	if (arg->minus == 1)
		return (ft_putchar('%') + ft_blank(c, arg->min_width - 1));
	if (arg->zero == 1)
		c = '0';
	return (ft_blank(c, arg->min_width - 1) + ft_putchar('%'));
}

static int	ft_print_c(t_arg *arg, va_list ap)
{
	char	c;
	char	ch;

	c = ' ';
	ch = va_arg(ap, int);
	if (arg->minus == 1)
		return (ft_putchar(ch) + ft_blank(c, arg->min_width - 1));
	if (arg->zero == 1)
		c = '0';
	return (ft_blank(c, arg->min_width - 1) + ft_putchar(ch));
}

int			ft_printarg(const char *s, int *i, va_list ap)
{
	t_arg	arg;
	int		ret;

	if ((ret = ft_fill_struct(s + *i, &arg, ap)) < 0)
		return (-1);
	(*i) += ret;
	if (arg.type == 'c')
		return (ft_print_c(&arg, ap));
	if (arg.type == 's')
		return (ft_print_s(&arg, ap));
	if (arg.type == 'p')
		return (ft_print_p(&arg, ap));
	if (arg.type == 'd' || arg.type == 'i')
		return (ft_print_di(&arg, ap));
	if (arg.type == 'u')
		return (ft_print_u(&arg, ap));
	if (arg.type == 'x')
		return (ft_print_x(&arg, ap));
	if (arg.type == 'X')
		return (ft_print_xx(&arg, ap));
	if (arg.type == '%')
		return (ft_print_mod(&arg));
	return (-1);
}
