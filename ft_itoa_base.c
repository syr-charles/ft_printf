/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 11:38:38 by cdana             #+#    #+#             */
/*   Updated: 2020/01/07 12:09:17 by cdana            ###   ########.fr       */
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

int			ft_itoa_base(char *base, unsigned long nb, char **line)
{
	unsigned long	x;
	unsigned long	len;
	int				i;

	if (!base || (len = ft_strlen(base)) < 2 || !line || !(*line))
		return (-1);
	i = 0;
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
