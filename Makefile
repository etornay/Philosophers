NAME = philo

PHILO = philo.a

FILES = src/main.c\
src/checker.c\
src/utils.c\
src/init_struct.c\
src/time_utils.c\
src/routine.c\



OBJECTS = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra -g

$(NAME):			$(OBJECTS)
						@ ar rcs $(PHILO) $(OBJECTS)
						@ gcc $(INC_SYS) $(LIB_SYS) $(FLAGS) $(PHILO) -o $(NAME)

$(OBJECTS):			src/%.o : src/%.c
						@ gcc $(INC_SYS) $(FLAGS) -c $< -o $@

all:				$(NAME)

clean:
					@ rm -f $(OBJECTS)

fclean:
					@ rm -f $(NAME) $(OBJECTS) $(PHILO)

re:					fclean all

.PHONY: all re clean fclean
