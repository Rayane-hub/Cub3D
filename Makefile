# Nom du programme à générer
NAME	= cub3D

# Compiler and flags
CC		= cc

# Drapeaux de compilation
CFLAGS = -Wall -Werror -Wextra

SRC		= main.c get_color.c get_texture.c utils.c gnl/get_next_line.c gnl/get_next_line_utils.c

OBJ		= $(SRC:.c=.o)

all : $(NAME)

%.o : %.c cub3D.h
	@$(CC) $(CFLAGS) -c $< -o $@
	printf "\033[1A\033[KCompiling $<\r"

$(NAME): $(OBJ)
	@make -sC libft && $(CC) $(OBJ) -L libft -l ft -o $(NAME)
	printf "\033[38;5;220m\033[1A\033[KExecutable $(NAME) created\n\033[0m"

clean :
	@rm -rf  $(OBJ) 
	#@make -sC libft clean
	printf "\033[38;5;220m\033[1A\033[KCleaning objects\n\033[0m"

fclean : clean
	@rm -f $(NAME)
	#@make -sC libft fclean
	printf "\033[38;5;220m\033[1A\033[KRemoving $(NAME) and libraries\n\033[0m"

re : fclean all

.PHONY : all clean fclean re
