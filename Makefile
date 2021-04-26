SRC = ft_printf.c\
ft_printf_utils.c\
PF_check.c\
PF_fill_toPrint.c\
PF_write_toPrint.c

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