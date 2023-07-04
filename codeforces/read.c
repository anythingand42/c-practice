#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define LINES_NUMBER_MAX_LEN 8
#define LINE_MAX_LEN 102

int
main()
{
    char lines_number_buffer[LINES_NUMBER_MAX_LEN];
    int lines_number;
    char* lines_buffer;
    
    fgets(lines_number_buffer, sizeof(lines_number_buffer), stdin);
    lines_number = strtoul(lines_number_buffer, NULL, 10);

    printf("lines_number: %d\n", lines_number);

    lines_buffer = (char *)malloc(1000 + 1);
    fread(lines_buffer, LINE_MAX_LEN, lines_number, stdin);

    printf("rest:\n%s\n", lines_buffer);





    free(lines_buffer);
    return 0;
}
