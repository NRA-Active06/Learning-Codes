#include <stdio.h>

int main(void) {
    
    int row;
    int stars; 
    int spaces;
    
    int length = 7;


    for (row = 1; row <= length; row++) {

        for (spaces = 1; spaces <= length - row; spaces++) { //this makes spaces so that it goes to the other end (rhs)
            printf(" ");
        }

        for (stars = 1; stars <= row; stars++) {
            printf("*");
        }
        printf("\n");
    }


    for (row = length - 1; row >= 1; row--) {

        for (spaces = 1; spaces <= length - row; spaces++) {
            printf(" ");
        }

        for (stars = 1; stars <= row; stars++) {
            printf("*");
        }
        printf("\n");
    }

    return (0);
}
