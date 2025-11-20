#include <stdio.h>

int main(void) {
    int row = 1;
    int stars = 1;
    
    int length = 7;
    
    for (row = 1; row <= length; row++) {
        
        for (stars = 1; stars <= row; stars++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
