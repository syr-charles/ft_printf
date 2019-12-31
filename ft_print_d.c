/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 16:09:49 by cdana             #+#    #+#             */
/*   Updated: 2019/12/31 17:26:21 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define abs(x) (x < 0) ? -x : x

static int	ft_blank(t_arg *arg, int nb)
{
	int		i;
	char	c;

	c = ' ';
	if (arg->zero == 1)
		c = '0';
	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

static int	ft_size(int nb, t_arg *arg)
{
	int		i;
	int		x;
	int		n;

	n = nb;
	if (n < 0)
		n = -n;
	x = 1;
	i = 1;
	while (n / x > 9)
	{
		x = 10 * x;
		i++;
	}
	if (arg->prec == 1 && arg->length > i)
		i = arg->length;
	i += (nb < 0);
	if (arg->zero == 1 && arg->min_width > i)
		i = arg->min_width;
	return (i);
}

static int	ft_shift(char **line)
{
	int		i;

	i = 0;
	while ((*line)[i])
		i++;
	(*line)[i + 1] = 0;
	while (i > 0)
	{
		(*line)[i] = (*line)[i - 1];
		i--;
	}
	return (1);
}

static int	ft_put(t_arg *arg, int nb, char **line)
{
	int		len;
	int		ret;

	len = ft_size(nb, arg);
	if (!(*line = malloc(len + 1)))
		return (-1);
	ret = ft_itoa_base("0123456789", nb, line);
	if (nb < 0)
		(*line)[0] = '0';
	while (ret < len)
	{
		ft_shift(line);
		(*line)[0] = '0';
		ret++;
	}
	if (nb < 0)
		(*line)[0] = '-';
	return (len);
}

int			ft_print_di(t_arg *arg, va_list ap)
{
	unsigned int	nb;
	char			*line;
	int				ret;
	int				sp;

	if (arg->s_width == 1)
		arg->min_width = va_arg(ap, int);
	if (arg->s_length == 1)
		arg->length = va_arg(ap, int);
	nb = va_arg(ap, int);
	if (arg->length == 0 && nb == 0)
		return (0);
	if ((ret = ft_put(arg, nb, &line)) == -1)
		return (-1);
	if (arg->minus)
	{
		write(1, line, ret);
		free(line);
		return (ret + ft_blank(arg, arg->min_width - ret));
	}
	sp = ft_blank(arg, arg->min_width - ret);
	write(1, line, ret);
	free(line);
	return (ret + sp);
}
