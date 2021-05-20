SRC = ft_printf.c\
ft_printf_utils.c\
ft_printf_utils_string.c\
pf_check.c\
pf_fill_toprint.c\
pf_write_toprint.c

CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $(OBJ)

%.o:%.c
	$(CC) $(CFLAGES) -c $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
