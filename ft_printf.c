/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:45:29 by cdana             #+#    #+#             */
/*   Updated: 2019/12/26 12:57:46 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find(char c, char *s);
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (s[i] == c);
}

int		ft_analyse(const char *s)
{
	int		i;
	int		nb_arg;
	
	nb_arg = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			
		}
	}
	
}

int		ft_printf(const char *s, ...)
{
	va_list		ap;
	int			len;
	int			i;
	
	va_start(ap, nb_arg(s));
	i = 0;
	len = 0;
	while (s[i])
	{
		while (
	}

	va_end(ap);
}
