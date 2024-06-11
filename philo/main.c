
#include <unistd.h>

int	check_number_of_arguments(int argc)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Pass exactly 4 or 5 arguments.\n", 31);
		write(2, "./philo [# of philosophers] [time to die (ms)] ", 48);
		write(2, "[time to eat (ms)] [time to sleep (ms)] ", 41);
		write(2, "--- OPTIONAL [# of times a philosopher eats] ---\n", 49);
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (check_number_of_arguments(argc) == 1)
		return (1);

	return (0);
}
