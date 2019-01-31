
CFILES	=	$(notdir $(wildcard *.c))
OBJECTS	=	$(notdir $(CFILES:%.c=%.o))

all: $(OBJECTS)
	@mv $^ ../

$(OBJECTS): $(CFILES) $(LIBFT)
	@gcc -o $@ -c -Wall -Wextra -Werror $(@:.o=.c)

clean:
	@rm -rf ../$(OBJECTS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re