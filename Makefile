NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
AR = ar rcs
RM = rm -f

SRC = ft_printf ft_printf_arg ft_printf_flags ft_printf_int ft_printf_ptr ft_printf_str

SRCS = $(addprefix src/, $(addsuffix .c, $(SRC)))
OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@make -C libft fclean
	$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re libft bonus
