NAME	= libftprintf.a
SRCS	= ft_printf.c		\
		ft_itoa_base.c		\
		ft_fill_struct.c	\
		ft_printarg.c 		\
		ft_utils.c			\
		ft_print_d.c		\
		ft_print_s.c		\
		ft_print_p.c		\
		ft_print_u.c		\
		ft_print_x.c		\
		ft_print_xx.c		\

CFLAGS	= -Wall -Wextra -Werror
OBJS	= ${SRCS:.c=.o}

all:		${NAME}

$(NAME):	${OBJS}
		ar rc ${NAME} ${OBJS}
		ranlib ${NAME}

%.o:%.c
		gcc ${CFLAGS} -o $@ -c $< -I ft_printf.h

clean:		
		rm -f ${OBJS}

fclean:		clean
		rm -f ${NAME}

re:		fclean all

.PHONY:		clean fclean 
