NAME ?= ft_ls

CFLAGS ?= -Wall -Wextra -Werror

SRC := \
	btree/btree_add.c \
	btree/btree_clean.c \
	btree/btree_create.c \
	btree/btree_each.c \
	main.c \
	filesystem_hidden.c \
	filesystem_initargs.c \
	filesystem_readargs.c \
	filesystem_readtree_directory.c \
	filesystem_readtree_long.c \
	filesystem_readtree_long_aux.c \
	filesystem_readtree_short.c \
	filesystem_savetree.c \
	filesystem_subtree.c \
	ft_ls_readpath.c \
	ft_ls_error.c \
	ft_ls_itoan.c \
	printer/printer_bin.c \
	printer/printer_bin_padding_left.c \
	printer/printer_bin_padding_right.c \
	printer/printer_char.c \
	printer/printer_endl.c \
	printer/printer_flush.c \
	printer/printer_init.c \
	printer/printer_int.c \
	printer/printer_int_padding_left.c \
	printer/printer_int_padding_right.c \
	printer/printer_long.c \
	printer/printer_long_padding_left.c \
	printer/printer_long_padding_right.c \
	printer/printer_numeric_length.c \
	printer/printer_padding.c \
	printer/printer_str.c \
	printer/printer_str_padding_left.c \
	printer/printer_str_padding_right.c \
	printer/printer_uint.c \
	printer/printer_uint_padding_left.c \
	printer/printer_uint_padding_right.c \
	printer/printer_ulong.c \
	printer/printer_ulong_padding_left.c \
	printer/printer_ulong_padding_right.c \
	sort_alpha.c \
	sort_alpha_handle.c \
	sort_alpha_reverse.c \
	sort_func.c \
	sort_mtime.c \
	sort_mtime_reverse.c

OBJ := $(addprefix src/,$(SRC:.c=.o))

CFLAGS += -MMD -MP -Ilibft

ifneq (, $(findstring linux, $(shell $(CC) -dumpmachine)))
	CFLAGS += -Dst_mtimespec=st_mtim
endif

.PHONY: all clean fclean re libft

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(CFLAGS) -o $@ $^

-include $(OBJ:.o=.d)

clean:
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean:
	$(MAKE) clean
	$(MAKE) -C libft fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

libft libft/libft.a:
	$(MAKE) -C libft

.syntastic_c_config:
	echo "-Ilibft" > $@
