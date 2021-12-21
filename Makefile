PATH_TREE = ./src/
PATH_UTILS = $(PATH_TREE)utils/
PATH_OBJS = $(PATH_TREE)objs/

NAME = philo

FILES = $(PATH_UTILS)ft_calloc.c $(PATH_UTILS)utils.c $(PATH_UTILS)ft_digit.c $(PATH_UTILS)ft_atoi.c \
		$(PATH_UTILS)initialize.c $(PATH_UTILS)open_house.c \
		$(PATH_TREE)actions.c $(PATH_TREE)main.c 

CC = gcc
CFLAGS = -Wextra -Werror -Wall -fsanitize=leak
RM = rm -rf

OBJS = $(patsubst $(PATH_TREE)%.c, $(PATH_OBJS)%.o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lpthread  $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o:	$(PATH_TREE)%.c
	@mkdir -p $(PATH_OBJS)utils
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all