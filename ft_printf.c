/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:45:29 by cdana             #+#    #+#             */
/*   Updated: 2019/12/27 15:30:50 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		{
			write(1, s + i, 1);
			i++;
			len++;
		}
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
