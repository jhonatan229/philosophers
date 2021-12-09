PATH_TREE = ./src/
PATH_UTILS = $(PATH_TREE)utils/
PATH_OBJS = $(PATH_TREE)objs/

NAME = philo

FILES = $(PATH_UTILS)ft_calloc.c $(PATH_UTILS)utils.c $(PATH_TREE)actions.c $(PATH_TREE)main.c 

CC = clang
CFLAGS = -Wextra -Werror -Wall
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