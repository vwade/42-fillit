
####	CONTROL PANEL	########################################################

NAME = fillit
BUILD = build
CFILES = source/fillit.c\
source/map_func.c\
source/readfile.c\
source/tetra_func.c\
source/validation.c\
includes/get_next_line.c includes/libft/ft_bzero.c includes/libft/ft_lstnew.c includes/libft/ft_lstdel.c includes/libft/ft_lstdelone.c includes/libft/ft_memset.c includes/libft/ft_putendl.c includes/libft/ft_putnbr.c\
includes/libft/ft_strjoin.c includes/libft/ft_strlen.c includes/libft/ft_strnew.c includes/libft/ft_memalloc.c includes/libft/ft_memcpy.c includes/libft/ft_memdel.c includes/libft/ft_putstr.c includes/libft/ft_strdup.c includes/libft/ft_strncat.c includes/libft/ft_strncpy.c includes/libft/ft_strsub.c includes/libft/ft_strsplit.c includes/libft/ft_strcpy.c includes/libft/ft_strchr.c includes/libft/added_functions/ft_arrlen.c includes/libft/added_functions/ft_lstlen.c includes/libft/added_functions/ft_lstpush.c includes/libft/added_functions/ft_error.c includes/libft/added_functions/ft_del.c

all: $(NAME)

$(NAME): $(BUILD)
	@gcc -o $@ -Wall -Wextra -Werror $(CFILES)

$(BUILD):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re