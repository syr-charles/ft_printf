/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:45:29 by cdana             #+#    #+#             */
/*   Updated: 2019/12/27 12:23:00 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_find(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (str[i] == c);
}

void	ft_struct_init(t_arg *arg)
{
	arg->minus = 0;
	arg->zero = 0;
	arg->min_width = 0;
	arg->s_width = 0;
	arg->prec = 0;
	arg->lenght= 0;
	arg->s_lenght = 0;
	arg->type = 0;
}

int		ft_fill_struct(const char *s, t_arg *arg)
{
	int	i;

	ft_struct_init(arg);
	i = 0;
	while (ft_find(s[i], "-0+#"))
	{
		if (s[i] == '-')
			arg->minus = 1;
		if (s[i] == '0')
			arg->zero = 1;
		i++;
	}
	if (s[i] == '*')
	{
		arg->s_width = 1;
		i++;
	}
	if (ft_find(s[i], "0123456789"))
		arg->min_width = ft_atoi(s + i);
	while (ft_find(s[i], "0123456789"))
		i++;
	if (s[i] == '.')
	{
		arg->prec = 1;
		i++;
		if (s[i] == '*')
		{
			arg->s_lenght = 1;
			i++;
		}
		if (ft_find(s[i], "0123456789"))
			arg->lenght = ft_atoi(s + i);
		while (ft_find(s[i], "0123456789"))
			i++;
	}
	if (ft_find(s[i], "cspdiuxX%"))
	{
		arg->type = s[i];
		return (i + 1);
	}
	return (-1);
}

void	ft_putchar_and_add(char c, int *len, int *i, int nb)
{
	write(1, &c, 1);
	(*len)++;
	*i += nb;
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	int			len;
	int			i;
	int 		j;
	t_arg		arg;
	
	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
			ft_putchar_and_add(s[i], &len, &i, 1);
		if (s[i + 1] == '%')
			ft_putchar_and_add('%', &len, &i, 2);
		if (s[i] == 0)
			break;
		if ((j = ft_fill_struct(s + i, &arg)) == -1)
			return (-1);
		i += j;
		if (arg.s_width == 1)
			arg.min_width = va_arg(ap, int);
		if (arg.s_lenght == 1)
			arg.lenght = va_arg(ap, int);
	}
	va_end(ap);
	return (len);
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	int			len;
	int			i;
	int			ret;

	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			write(1, s + i, 1);
			i++;
			len++;
		}
		if (s[i] == '%')
		{
			ret = ft_printarg(s, &i, ap);
			if (ret == -1)
				return (-1);
			len += ret;
		}
	}
	va_end(ap);
	return (len);
}
