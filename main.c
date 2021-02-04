#include "get_next_line.h"

int main()
{
    int fd = open("text.txt", O_RDWR);
    char *string;
    get_next_line(fd, &string);
    printf("%s\n", string);
    get_next_line(fd, &string);
    printf("%s\n", string);
}