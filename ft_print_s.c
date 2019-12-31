/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:00:45 by cdana             #+#    #+#             */
/*   Updated: 2019/12/31 14:07:09 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


static int	ft_blank(char c, t_arg *arg, char *ctnt)
{
	int		i;
	int		len;

	len = ft_strlen(ctnt);
	if (arg->prec == 1 && len > arg->length)
		len = arg->length;
	if (arg->min_width == -1 || len >= arg->min_width)
		return (0);
	i = 0;
	while (i + len < arg->min_width)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	ft_put(t_arg *arg, char *ctnt)
{
	int		i;

	i = 0;
	while (ctnt[i] && (arg->prec == 0 || i < arg->length))
		i++;
	write(1, ctnt, i);
	return (i);
}

int			ft_print_s(t_arg *arg, va_list ap)
{
	char	*ctnt;
	char 	c;
	
	c = ' ';
	if (arg->zero == 1)
		c = '0';
	if (arg->s_width == 1)
		arg->min_width = va_arg(ap, int);
	if (arg->s_length == 1)
		arg->length = va_arg(ap, int);
	if(!(ctnt = va_arg(ap, char*)))
		return (-1);
	if (arg->minus == 1)
		return (ft_put(arg, ctnt) + ft_blank(c, arg, ctnt));
	return (ft_blank(c, arg, ctnt) + ft_put(arg, ctnt));
}
