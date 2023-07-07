#include <stdio.h>

#define INPUT_MAX_LEN 102

int
main()
{
    char input_buf[INPUT_MAX_LEN];
    char current_char;
    int i;
    int counter;

    fread(input_buf, INPUT_MAX_LEN, 1, stdin);

    counter = 1;
    for (i = 0; i < INPUT_MAX_LEN; i++) {
        current_char = input_buf[i];

        if (input_buf[i+1] == current_char) {
            counter++;
        } else {
            counter = 1;
        }

        if (input_buf[i+1] == '\0' || counter == 7) break;
    }

    if (counter == 7) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
