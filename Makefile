NAME = philo

PHILO = philo.a

FILES = src/main.c\
src\checker.c\
src\checker_utils.c\



OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra -g

INC_SYS = -I ./include -I /Users/etornay-/.brew/opt/readline/include

LIB_SYS = -L /Users/etornay-/.brew/opt/readline/lib -lreadline

$(NAME):			$(OBJECTS)
						@ ar rcs $(PHILO) $(OBJECTS)
						@ gcc $(INC_SYS) $(LIB_SYS) $(FLAGS) $(PHILO) -o $(NAME)

$(OBJECTS):			src/%.o : src/%.c
						@ gcc $(INC_SYS) $(FLAGS) -c $< -o $@

all:				$(NAME)

clean:
					@ rm -f $(OBJECTS)
					@ make clean -s -C

fclean:
					@ rm -f $(NAME) $(OBJECTS) $(PHILO)
					@ make fclean -s -C

re:					fclean all

.PHONY: all re clean fclean
