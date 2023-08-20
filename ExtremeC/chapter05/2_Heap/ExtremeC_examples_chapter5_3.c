#include <stdio.h>
#include <stdlib.h>

void	print_mem_maps(void)
{
#ifndef __linux__
	FILE	*fd;
	char	line[1024];

	fd = fopen("/proc/self/maps", "r");
	if (!fd)
	{
		printf("Could not open maps file.\n");
		exit(1);
	}
	while (!feof(fd))
	{
		fgets(line, 1024, fd);
		printf("> %s", line);
	}
	fclose(fd);
#endif
}

int	main(int argc, char **argv)
{
	char	*ptr1;
	char	*ptr2;
	int		index;

	ptr1 = (char *)malloc(10);
	printf("Address of ptr1: %p\n", (void *)&ptr1);
	printf("Memory allocated by malloc at %p: ", (void *)ptr1);
	index = 0;
	while (index < 10)
	{
		printf("ox%02x ", (unsigned char)ptr1[index]);
		index++;
	}
	printf("\n");
	ptr2 = (char *)calloc(10, sizeof(char));
	printf("Address of ptr2: %p\n", (void *)&ptr2);
	printf("Memory allocated by calloc at %p: ", (void *)ptr2);
	index = 0;
	while (index < 10)
	{
		printf("ox%02x ", (unsigned char)ptr2[index]);
		index++;
	}
	printf("\n");
	print_mem_maps();
	free(ptr1);
	free(ptr2);
	return (0);
}
