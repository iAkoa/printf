SRC		=  ft_printf.c 

OBJS		= ${SRC:.c=.o}

HEADER		= ft_printf.h

NAME		= libftprintf.a

CC			= gcc

FLAGS		= -Wall -Wextra -Werror

LIBFT		= libft/libft.a

all:		${NAME}

%.o : %.c	${HEADER} Makefile
			${CC} ${FLAGS} -c  $< -o $@

${NAME}:	 ${LIBFT} ${OBJS}
			cp libft/libft.a ${NAME}
			ar -crs ${NAME} ${OBJS}

${LIBFT}:
			make -C libft

bonus:		${NAME}

clean:
			make clean -C libft
			rm -f ${OBJS}

fclean:		clean 
			make fclean -C libft
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
