
####	CONTROL PANEL	########################################################

NAME		=	fillit
LIB			=	libfillit.a
BUILDdir	=	build/
OBJdir		=	obj/
OBJdir		:=	$(addprefix $(BUILDdir), $(OBJdir))
CFILES		=	\
				source/fillit.c \
				source/map_func.c \
				source/readfile.c \
				source/tetra_func.c \
				source/validation.c \
				includes/get_next_line.c \
				includes/libft/ft_bzero.c \
				includes/libft/ft_lstnew.c \
				includes/libft/ft_lstdel.c \
				includes/libft/ft_lstdelone.c \
				includes/libft/ft_memset.c \
				includes/libft/ft_putendl.c \
				includes/libft/ft_putnbr.c \
				includes/libft/ft_strjoin.c \
				includes/libft/ft_strlen.c \
				includes/libft/ft_strnew.c \
				includes/libft/ft_memalloc.c \
				includes/libft/ft_memcpy.c \
				includes/libft/ft_memdel.c \
				includes/libft/ft_putstr.c \
				includes/libft/ft_strdup.c \
				includes/libft/ft_strncat.c \
				includes/libft/ft_strncpy.c \
				includes/libft/ft_strsub.c \
				includes/libft/ft_strsplit.c \
				includes/libft/ft_strcpy.c \
				includes/libft/ft_strchr.c \
				includes/libft/added_functions/ft_arrlen.c \
				includes/libft/added_functions/ft_lstlen.c \
				includes/libft/added_functions/ft_lstpush.c \
				includes/libft/added_functions/ft_error.c \
				includes/libft/added_functions/ft_del.c
FTDIR		=	includes/libft/
CFLAGS		:=	-Wall -Wextra -Werror -L$(FTDIR)
LIB			:=	$(addprefix $(BUILDdir), $(LIB))
OBJECTS		=	$(addprefix $(OBJdir), $(notdir $(CFILES:.c=.o)))

all: $(NAME)

$(NAME): $(LIB) | $(BUILDdir)
	@gcc -o $@ $(CFLAGS) $(CFILES) -lft

$(LIB): $(OBJECTS)
	@ar rc $@ $<
	@ranlib $@

$(OBJECTS): $(CFILES) | $(OBJdir)
	@gcc -c -g -Wall -Wextra -Werror source/fillit.c source/map_func.c source/readfile.c source/tetra_func.c source/validation.c includes/get_next_line.c includes/libft/ft_bzero.c includes/libft/ft_lstnew.c includes/libft/ft_lstdel.c includes/libft/ft_lstdelone.c includes/libft/ft_memset.c includes/libft/ft_putendl.c includes/libft/ft_putnbr.c includes/libft/ft_strjoin.c includes/libft/ft_strlen.c includes/libft/ft_strnew.c includes/libft/ft_memalloc.c includes/libft/ft_memcpy.c includes/libft/ft_memdel.c includes/libft/ft_putstr.c includes/libft/ft_strdup.c includes/libft/ft_strncat.c includes/libft/ft_strncpy.c includes/libft/ft_strsub.c includes/libft/ft_strsplit.c includes/libft/ft_strcpy.c includes/libft/ft_strchr.c includes/libft/added_functions/ft_arrlen.c includes/libft/added_functions/ft_lstlen.c includes/libft/added_functions/ft_lstpush.c includes/libft/added_functions/ft_error.c includes/libft/added_functions/ft_del.c

$(BUILDdir):
	@mkdir -p $@

$(OBJdir):
	@mkdir -p $@

clean:
	@rm -rf $(OBJdir)
	@rm -rf *.o

fclean: clean
	@rm -rf $(BUILDdir) $(NAME) $(LIB)

re: fclean all

.PHONY: clean fclean all re