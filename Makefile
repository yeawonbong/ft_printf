SRC = ft_printf.c\
ft_printf_utils.c\
ft_printf_utils_string.c\
pf_check.c\
pf_fill_toprint.c\
pf_write_toprint.c


SRC_BONUS = 

CC = gcc
CFLAGES = -Wall -Wextra -Werror
AR = ar rcs
NAME = libftprintf.a
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $(OBJ)

%.o:%.c
	$(CC) $(CFLAGES) -c $< -o $@

clean :
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all