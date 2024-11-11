NAME = philo

CFLAGS = -Wall -Werror -Wextra
SOURCES = 	check_arguments_1.c\
			check_arguments_2.c\
			destroy_and_free_utils.c\
			eat.c\
			initialize_1.c\
			initialize_2.c\
			initialize_3.c\
			init_threads_and_simulation.c\
			main.c\
			philo_simulator.c\
			run_monitor_1.c\
			run_monitor_2.c\
			utils.c\
			utils_simulator.c\

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re