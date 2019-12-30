/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 12:02:17 by cdana             #+#    #+#             */
/*   Updated: 2019/12/27 18:56:54 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_print_mod(t_arg *arg)
{
	if (arg->minus > 0 || arg->zero > 0 || arg->min_width > 0
			|| arg->s_width > 0 || arg->prec > 0 || arg->length > 0
			|| arg->s_length > 0)
		return (-1);	
	ft_putchar('%');
	return (1);
}

static int	ft_print_c(t_arg *arg, va_list ap)
{
	if (arg->minus > 0 || arg->zero > 0 || arg->min_width > 0
			|| arg->s_width > 0 || arg->prec > 0 || arg->length > 0
			|| arg->s_length > 0)
		return (-1);
	ft_putchar(va_arg(ap, int));
	return (1);
}

int			ft_printarg(const char *s, int *i, va_list ap)
{
	t_arg	arg;
	int 	ret;

	if ((ret = ft_fill_struct(s + *i, &arg)) < 0)
		return (-1);
	(*i) += ret;
	if (arg.type == 'c')
		return (ft_print_c(&arg, ap));
	if (arg.type == 's')
		return (ft_print_s(&arg, ap));
	/*
	if (arg.type == 'p')
		return (ft_print_p(&arg, ap));
	if (arg.type == 'd')
		return (ft_print_d(&arg, ap));
	if (arg.type == 'i')
		return (ft_print_i(&arg, ap));
	if (arg.type == 'u')
		return (ft_print_u(&arg, ap));
	if (arg.type == 'x')
		return (ft_print_x(&arg, ap));
	if (arg.type == 'X')
		return (ft_print_X(&arg, ap));
	*/
	if (arg.type == '%')
		return (ft_print_mod(&arg));
	return (-1);
}
