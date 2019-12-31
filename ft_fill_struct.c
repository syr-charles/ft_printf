/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 13:38:55 by charles           #+#    #+#             */
/*   Updated: 2019/12/31 17:28:25 by cdana            ###   ########.fr       */
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

static int		ft_fill_width(const char *s, t_arg *arg, int i)
{
	arg->s_width = 0;
	arg->min_width = -1;
	if (s[i] == '*')
	{
		arg->s_width = 1;
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

static int		ft_fill_precision(const char *s, t_arg *arg, int i)
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
			arg->s_length = 1;
			i++;
		}
		else if (ft_find(s[i], "0123456789"))
		{
			arg->length = ft_atoi(s + i);
			while (ft_find(s[i], "0123456789"))
				i++;
		}
	}
	return (i);
}

int     ft_fill_struct(const char *s, t_arg *arg)
{
    int i;

    i = ft_fill_flags(s, arg);
    i = ft_fill_width(s, arg, i);
    i = ft_fill_precision(s, arg, i);
	if (arg->zero == 1 && (arg->minus == 1 || arg->prec == 1))
		arg->zero = 0;
    if (ft_find(s[i], "cspdiuxX%"))
    {
        arg->type = s[i];
        return (i + 1);
    }
	return (-1);
}
