/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdana <cdana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:46:30 by cdana             #+#    #+#             */
/*   Updated: 2020/01/02 15:04:09 by cdana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_arg
{
	int			minus;
	int			zero;
	int			min_width;
	int			s_width;
	int			prec;
	int			length;
	int			s_length;
	char		type;
}				t_arg;

int				ft_print_s(t_arg *arg, va_list ap);
int				ft_print_p(t_arg *arg, va_list ap);
int				ft_print_di(t_arg *arg, va_list ap);
int				ft_print_u(t_arg *arg, va_list ap);
int				ft_print_x(t_arg *arg, va_list ap);
int				ft_print_xx(t_arg *arg, va_list ap);
int				ft_printf(const char *s, ...);
int				ft_atoi(const char *s);
int				ft_itoa_base(char *base, long long nb, char **line);
int				ft_printarg(const char *s, int *i, va_list ap);
int				ft_fill_struct(const char *s, t_arg *arg);
#endif
