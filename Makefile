NAME ?= ft_ls

CFLAGS ?= -Wall -Wextra -Werror

SRC := \
	main.c \
	ft_ls_error.c \
	ft_ls_long_format.c \
	ft_ls_itoan.c

OBJ := $(addprefix src/,$(SRC:.c=.o))

CFLAGS += -MMD -MP -Ilibft

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^

-include $(OBJ:.o=.d)

clean:
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re: fclean all

libft libft/libft.a:
	$(MAKE) -C libft

.syntastic_c_config:
	echo "-Ilibft" > $@
