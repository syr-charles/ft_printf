/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:46:30 by cdana             #+#    #+#             */
/*   Updated: 2019/12/26 15:38:39 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_arg
{
	int 	minus;
	int 	zero;
	int 	min_width;
	int		s_width;
	int 	prec;
	int 	lenght;
	int 	s_lenght;
	char	type;
}				t_arg;

int		ft_printf(const char *s, ...);
int		ft_atoi(const char *s);
#endif
