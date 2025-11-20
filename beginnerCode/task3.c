#include <stdio.h>

int main(){
    int height = 8;
    int a, b;

    int mid = height / 2;

    for(a = 0; a <= mid; a++) {
        for(b = 0; b < mid - a; b++)
            printf(" ");
        for(b = 0; b < 2 * a + 1; b++)
            printf("*");
        printf("\n");
    }

    for (a = mid - 1; a >= 0; a--) {
        for (b = 0; b < mid - a; b++)
            printf(" ");

        for (b = 0; b < 2 * a + 1; b++)
            printf("*");
        printf("\n");
    }

    return(0);

}