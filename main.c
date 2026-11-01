#include "get_next_line.h"

int main(void)
{
	int		fd;
	int		read_count;
	char	buffer[100];

	fd = open("README.md", O_RDONLY);
	if (fd == -1)
		return (-1);
	read_count = read(fd, buffer, 25);
	while (read_count)
	{
		buffer[read_count] = '\0';
		
		printf("%s\n", buffer);
		// write(1, &buffer, ft_strlen(buffer));
		read_count = read(fd, buffer, 25);
	}
	return (0);
}
