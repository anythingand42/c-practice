#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define LINES_NUM_MAX_LEN 24
#define LINE_MAX_LEN 256
#define OUTPUT_LINE_MAX_LEN 24

int
main()
{
    char lines_num_buf[LINES_NUM_MAX_LEN];
    int lines_num;
    char* lines_buf;
    char* output_buf;
    char* lines_buf_ptr;
    int line_i;
    
    fgets(lines_num_buf, sizeof(lines_num_buf), stdin);
    lines_num = strtoul(lines_num_buf, NULL, 10) + 10;

    lines_buf = calloc(lines_num, LINE_MAX_LEN);
    fread(lines_buf, LINE_MAX_LEN, lines_num, stdin);

    output_buf = calloc(lines_num, OUTPUT_LINE_MAX_LEN);
    lines_buf_ptr = lines_buf;

    while(*lines_buf_ptr != '\0')
    {
        line_i = 0;
        while (lines_buf_ptr[line_i] != '\n' && lines_buf_ptr[line_i] != '\0')
            line_i++;

        if (line_i > 10)
            printf("%c%d%c\n", lines_buf_ptr[0], line_i - 2, lines_buf_ptr[line_i - 1]);
            //// sprintf(output_buf, "%s%c%d%c\n", output_buf, lines_buf_ptr[0], line_i - 2, lines_buf_ptr[line_i - 1]);
        else
        {
            printf("%.*s\n", line_i, lines_buf_ptr);
            // printf("%c%d%c\n", lines_buf_ptr[0], line_i - 2, lines_buf_ptr[line_i - 1], lines_buf_ptr[line_i - 1]);
            // strncat(output_buf, lines_buf_ptr, line_i);
            // sprintf(output_buf, "%s\n", output_buf);
        }
        
        lines_buf_ptr = lines_buf_ptr + line_i + 1;
    }

    // int len = strlen(output_buf);
    // if (output_buf[len - 1] == '\n')
    //     output_buf[len - 1] = '\0';

    // printf("%s", output_buf);

    free(output_buf);
    free(lines_buf);
    return 0;
}
