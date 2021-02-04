#include "get_next_line.h"
#define BUFFER_SIZE BUFFER

// void *ft_realloc(void *ptr, size_t size)
// {
//     int i = 0;
//     unsigned char *ucptr = (unsigned char *)ptr;
//     unsigned char *newptr = malloc(size);

//     if (ptr == NULL)
//         return ((void *)newptr);
//     if (!size && ptr != NULL)
//         return (NULL);
//     while (ucptr[i] && size)
//     {
//         newptr[i] = ucptr[i];
//         ++i;
//         --size;
//     }
//     free(ptr);
//     return ((void *)newptr);
// }

int get_next_line(int fd, char **line)
{
    char buff[BUFFER_SIZE];
    static int i = 0;
    int malloc_size = BUFFER_SIZE;
    char *new_line;

    if(!line)
        return (-1);
    int finish = read(fd, buff, BUFFER_SIZE);
    buff[finish] = '\0';
    malloc_size = ft_strlen(buff) + 1;
    if (!(new_line = malloc(malloc_size + 1)))
        return (-1);
    // return 0;
    while (buff[i] != '\0')
    {
        new_line[i] = buff[i];
        // line equals to new_line
        if (buff[i] == '\n')
        {
            return (1);
        }
        else if (buff[i] == '\0')
        {
            return (0);
        }
        ++i;
    }
    new_line[i] = '\0';
    close(fd);
    // printf("%s\n", *line);
    return (0);
}

