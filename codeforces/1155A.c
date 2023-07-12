#include <stdio.h>

#define FIRST_LINE_MAX_LEN 10
#define INPUT_MAX_LEN 3 * 100000 + 2

int main() {
    char first_line_buf[FIRST_LINE_MAX_LEN];
    char input_buf[INPUT_MAX_LEN];
    int i;
    int result;

    fgets(first_line_buf, FIRST_LINE_MAX_LEN, stdin);
    fread(input_buf, INPUT_MAX_LEN, 1, stdin);

    result = 0;
    for (i = 0; i < INPUT_MAX_LEN; i++) {
        if (input_buf[i] == '\0' || input_buf[i] == '\n') break;
        if (input_buf[i+1] == '\0' || input_buf[i+1] == '\n') break;
        if (input_buf[i] > input_buf[i+1]) {
            result = 1;
            break;
        }
    }

    if (result) {
        printf("YES\n%d %d", i + 1, i + 2);
    } else {
        printf("NO");
    }

    return 0;
}
