CFLAGS ?= -Wall -Wextra -Werror
NAME ?= libft.a

SRC := \
	ft_memcpy.c \
	ft_strcmp.c \
	ft_strlen.c \
	ft_strncpy.c \
	ft_strnlen.c

OBJ := $(SRC:.c=.o)
CFLAGS += -MMD -MP

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $@

-include $(OBJ:.o=.d)

clean:
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
