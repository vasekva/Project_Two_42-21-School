#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char	*line;
	int		fd;
	int		i;

	//fd = 42;
	fd = open("emp.txt", O_RDONLY);
	//fd = open("baud.txt", O_RDONLY);
	//fd = open("huge_file", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	if (i == 0)
	{
		printf("%s", line);
		free(line);
	}
	if (i < 0)
		printf("ALL is GOOD");
//	fd = open("two_lines.txt", O_RDONLY);
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("%s\n", line);
//		free(line);
//	}
//	if (i == 0)
//	{
//		printf("%s\n", line);
//		free(line);
//	}
//
//	fd = open("two.txt", O_RDONLY);
//	while ((i = get_next_line(fd, &line)) > 0)
//	{
//		printf("%s\n", line);
//		free(line);
//	}
//	if (i == 0)
//	{
//		printf("%s", line);
//		free(line);
//	}

	//while (1){}
	close(fd);
	return (0);
}