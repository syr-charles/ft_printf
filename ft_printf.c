/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:45:29 by cdana             #+#    #+#             */
/*   Updated: 2020/01/02 15:14:48 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putchar_and_add(char c, int *i, int *len)
{
	write(1, &c, 1);
	(*i)++;
	(*len)++;
	return (1);
}

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	int			len;
	int			i;
	int			ret;

	if (!s)
		return (-1);
	va_start(ap, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != '%')
			ft_putchar_and_add(s[i], &i, &len);
		if (s[i] == '%')
		{
			if ((ret = ft_printarg(s, &i, ap)) == -1)
				return (-1);
			len += ret;
		}
	}
	va_end(ap);
	return (len);
}
