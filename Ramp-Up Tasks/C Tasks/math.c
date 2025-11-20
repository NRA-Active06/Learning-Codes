#include "math.h"
#include <stdio.h>

int amini_add(int a, int b) {
    return a + b;
}

int amini_sub(int a, int b) {
    return a - b;
}

int amini_mul(int a, int b) {
    return a * b;
}

int amini_div(int a, int b) {
    if (b == 0){
        printf("You can't divide by 0!\n");
        return 0;
    }
    else
        return (a/b);
}

void run_math() {
    int x, y;
    char op;

    printf("Add: %d + %d = %d\n", x, y, amini_add(x, y));
    printf("Sub: %d - %d = %d\n", x, y, amini_sub(x, y));
    printf("Mul: %d * %d = %d\n", x, y, amini_mul(x, y));
    printf("Div: %d / %d = %d\n", x, y, amini_div(x, y));
}