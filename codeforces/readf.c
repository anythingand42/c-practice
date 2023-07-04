#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd, sz;
    char *c = (char *) malloc(100 * sizeof(char));
    
    // fd = open("r1", O_RDONLY);
    // if (fd < 0) { perror("r1"); exit(1); }
    
    sz = read(STDIN_FILENO, c, 10);
    printf("called read(% d, c, 10). returned that"
            " %d bytes were read.\n", fd, sz);
    c[sz] = '\0';
    printf("Those bytes are as follows: %s\n", c);
}
