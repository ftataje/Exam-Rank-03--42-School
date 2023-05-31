#include "get_next_line.h"

char *get_next_line(int fd)
{
    if (BUFFER_SIZE <= 0)
        return (NULL);
    int     i = 0;
    int     rd = 0; //# bytes leidos
    char    character;
    char    *buffer = malloc(100000);

    while ((rd = read(fd, &character, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0) //cada vez que se ejecuta la función read, lee el siguiente carácter disponible en el archivo porque esta es la forma en que la función está diseñada para trabajar
    {
        buffer[i++] = character;
        if (character == '\n')
            break ;
    }
    buffer[i] =  '\0';
    if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
        return (free(buffer), NULL); // liberar la memoria de buffer (mediante free(buffer)) y retornar NULL al mismo tiempo.
    return(buffer);
}

int	main(void)
{
	int	file;

	file = open("test.txt", O_RDWR);
	printf("Llamada 1: %s\n", get_next_line(file));
	printf("------\n");
	printf("Llamada 2: %s\n", get_next_line(file));
	//printf("file: %s\n", get_next_line(file));
}
