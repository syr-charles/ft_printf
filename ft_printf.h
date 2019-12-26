/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:46:30 by cdana             #+#    #+#             */
/*   Updated: 2019/12/26 12:59:06 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_arg
{
	int		left_justify;
	int		fill_with_zeros;
	int		signed_value;
	int		argument_type;
};

int		ft_printf(const char *s, ...);
#endif
