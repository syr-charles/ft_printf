/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 11:38:38 by cdana             #+#    #+#             */
/*   Updated: 2019/12/31 16:48:58 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_itoa_base(char *base, long long nb, char **line)
{
	long long	x;
	int			len;
	int			i;

	if (!base || (len = ft_strlen(base)) < 2 || !line || !(*line))
		return (-1);
	i = 0;
	if (nb < 0)
	{
		(*line)[0] = '-';
		nb = -nb;
		i++;
	}
	x = 1;
	while (nb / x >= len)
		x = len * x;
	while (x > 0)
	{
		(*line)[i] = base[(nb / x) % len];
		x = x / len;
		i++;
	}
	(*line)[i] = 0;
	return (i);
}
