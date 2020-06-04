NAME	= lem_in.a

SRC		=	src/main.c \
			src/add_rooms.c \
			src/create_rooms.c \
			src/create_map.c \
			src/create_links.c \
			src/display_ants.c \
			src/find_path.c \
			src/ft_error.c \
			src/display_small.c

SRCO = *.o
              
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@make -C includes/libft/
	@gcc -c -g $(CFLAGS) $(SRC)
	@ar rc $(NAME) $(SRCO)
	@ranlib $(NAME)
	@gcc $(CFLAGS) src/main.c lem_in.a includes/libft/libft.a -o lem-in

clean :
	@/bin/rm -f $(SRCO)
	@/bin/rm -f includes/libft/*.o
fclean : clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f includes/libft/libft.a
	@rm lem-in
re : fclean all
