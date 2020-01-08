/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:38:55 by charles           #+#    #+#             */
/*   Updated: 2020/01/08 12:10:53 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_find(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c);
}

static int		ft_fill_flags(const char *s, t_arg *arg)
{
	int		i;

	i = 1;
	arg->minus = 0;
	arg->zero = 0;
	while (ft_find(s[i], "-0+#"))
	{
		if (s[i] == '-')
			arg->minus = 1;
		if (s[i] == '0')
			arg->zero = 1;
		i++;
	}
	return (i);
}

static int		ft_fill_width(const char *s, t_arg *arg, int i, va_list ap)
{
	arg->min_width = -1;
	if (s[i] == '*')
	{
		arg->min_width = va_arg(ap, int);
		if (arg->min_width < 0)
		{
			arg->min_width = -arg->min_width;
			arg->minus = 1;
		}
		i++;
	}
	else if (ft_find(s[i], "0123456789"))
	{
		arg->min_width = ft_atoi(s + i);
		while (ft_find(s[i], "0123456789"))
			i++;
	}
	return (i);
}

static int		ft_fill_precision(const char *s, t_arg *arg, int i, va_list ap)
{
	arg->prec = 0;
	arg->s_length = 0;
	arg->length = -1;
	if (s[i] == '.')
	{
		arg->prec = 1;
		i++;
		if (s[i] == '*')
		{
			arg->length = va_arg(ap, int);
			i++;
		}
		else if (ft_find(s[i], "-0123456789"))
		{
			arg->length = ft_atoi(s + i);
			while (ft_find(s[i], "-0123456789"))
				i++;
			arg->min_width = (arg->length < 0) ? -arg->length : arg->min_width;
			arg->minus = (arg->length < 0) ? 1 : arg->minus;
			arg->length = (arg->length < 0) ? 0 : arg->length;
		}
		else
			arg->length = 0;
	}
	return (i);
}

int				ft_fill_struct(const char *s, t_arg *arg, va_list ap)
{
	int		i;

	i = ft_fill_flags(s, arg);
	i = ft_fill_width(s, arg, i, ap);
	i = ft_fill_precision(s, arg, i, ap);
	if (arg->zero == 1 && arg->minus == 1)
		arg->zero = 0;
	if (ft_find(s[i], "cspdiuxX%"))
	{
		arg->type = s[i];
		if (arg->zero && arg->prec && arg->length >= 0
			&& ft_find(s[i], "spdiuxX"))
			arg->zero = 0;
		return (i + 1);
	}
	return (-1);
}
