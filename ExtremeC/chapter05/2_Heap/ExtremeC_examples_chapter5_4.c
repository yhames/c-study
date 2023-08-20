#include <stdlib.h>

void	check_leak(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	char *ptr;

	ptr = (char *)malloc(16 * sizeof(char));
	free(ptr);
	atexit(check_leak);
	return (0);
}
