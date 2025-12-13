SRCS = push_swap.c swap_op.c push_op.c rotate_op.c sorted.c

CC = cc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libpush.a

MAKE = make

all: makeall
	$(CC) push_swap.c libpush.a ./libft/libft.a ./ft_printf/libftprintf.a
makeall: $(NAME)
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./ft_printf
fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft
	$(MAKE) fclean -C ./ft_printf

re :fclean $(NAME)

.PHONY: all clean fclean re
