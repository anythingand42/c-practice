#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define INPUT_MAX_LEN 102

int
main()
{
    char input_buf[INPUT_MAX_LEN];
    char output_buf[INPUT_MAX_LEN];
    int amount[3] = {0, 0, 0};
    int i = 0;
    int a = 0;


    fread(input_buf, INPUT_MAX_LEN, 1, stdin);

    for (i = 0; i < INPUT_MAX_LEN; i++) {
        if (input_buf[i] == '1') amount[0]++;
        else if (input_buf[i] == '2') amount[1]++;
        else if (input_buf[i] == '3') amount[2]++;
        else if (input_buf[i] == '\0') break;
    }

    i = 0;

    for (a = 0; a < amount[0]; a++) {
        output_buf[i] = '1';
        output_buf[i+1] = '+';
        i += 2;
    }

    for (a = 0; a < amount[1]; a++) {
        output_buf[i] = '2';
        output_buf[i+1] = '+';
        i += 2;
    }

    for (a = 0; a < amount[2]; a++) {
        output_buf[i] = '3';
        output_buf[i+1] = '+';
        i += 2;
    }

    output_buf[i-1] = '\0';

    printf("%s", output_buf);

    return 0;
}
