NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS = -L./libft -lft
AR = ar rcs
RM = rm -f

SRC		=	ft_printf ft_printf_arg ft_printf_flags ft_printf_int ft_printf_ptr ft_printf_str

SRCS	=	$(addprefix src/, $(addsuffix .c, $(SRC)))
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
