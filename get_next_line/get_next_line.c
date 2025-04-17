#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 5
// # endif

char *get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1 )
		return 0;

	char *str  = malloc (100000);
	char *temp = str;

	if (BUFFER_SIZE == 1)
	{
		while(read(fd, temp, BUFFER_SIZE) > 0 && *temp++ != '\n');
		if(temp > str)
			return (*temp = 0,str);
		else
			return (free(str),NULL);
	}
	else
	{
		while(read(fd, temp, 1) > 0 && *temp++ != '\n');
		
		if(temp > str)
			return (*temp = 0,str);
		else
			return (free(str),NULL);
	}
    return(str);
}
// int main ()
// {
// 	int fd = open("file.txt", O_RDWR);
// 	char *line = get_next_line(fd);

// 	while (line)
// 	{
// 		printf ("%s\n",line);
// 		free (line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// }
