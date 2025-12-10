SRCS =	ft_printf.c ./print/ft_con_to_hexa.c ./print/ft_putnbr.c ./print/ft_putunbr.c\
	./print/ft_putstr.c ./print/ft_putchar.c ./print/ft_putaddr.c ./print/ft_strlen.c
	
OBJS = $(SRCS:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME) 

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
