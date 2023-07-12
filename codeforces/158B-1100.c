#include <stdio.h>

#define FIRST_LINE_MAX_LEN 10
#define INPUT_MAX_LEN 100000 * 2 + 2

int main() {
    char first_line_buf[FIRST_LINE_MAX_LEN];
    char input_buf[INPUT_MAX_LEN];
    int result;
    int rest;
    int i;
    int n1;
    int n2;
    int n3;
    int n4;

    fgets(first_line_buf, FIRST_LINE_MAX_LEN, stdin);
    fread(input_buf, INPUT_MAX_LEN, 1, stdin);

    n1 = 0;
    n2 = 0;
    n3 = 0;
    n4 = 0;
    for (i = 0; i < INPUT_MAX_LEN; i+=2) {
        if (input_buf[i] == '\0' || input_buf[i] == '\n') break;
        
        if (input_buf[i] == '1') n1++;
        else if (input_buf[i] == '2') n2++;
        else if (input_buf[i] == '3') n3++;
        else if (input_buf[i] == '4') n4++;

        if (input_buf[i+1] == '\0' || input_buf[i+1] == '\n') break;
    }

    result = n4;

    while (n3 > 0) {
        if (n1 > 0) {
            n3--;
            n1--;
            result++;
        } else {
            n3--;
            result++;
        }
    }

    while (n2 > 0) {
        if (n2 > 1) {
            n2 -= 2;
            result++;
        } else if (n1 > 1) {
            n2--;
            n1 -= 2;
            result++;
        } else {
            n2--;
            n1--;
            result++;
        }
    }

    result += (n1 / 4) + (n1 % 4 > 0 ? 1 : 0);

    printf("%d", result);

    return 0;
}
