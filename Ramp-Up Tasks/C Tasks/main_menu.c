#include <stdio.h>
#include <stdbool.h>
#include "math.h"
#include "cmdline.h"
#include "diamondCode.h"
#include "turnonbit.h"
#include "staticStack.h"
#include "dynamicStack.h"
#include "queue.h"

int main() {
    int choice;
    while(true) {
        printf("\n---------- Main Menu ----------\n");
        printf(". 1. Bitwise Operations\n");
        printf(". 2. Diamond/Pattern Printing\n");
        printf(". 3. Command Line Tasks\n");
        printf(". 4. Static Stack\n");
        printf(". 5. Dynamic Stack\n");
        printf(". 6. Queue\n");
        printf(". 7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                run_bitwise(); 
                break;
            case 2: 
                run_diamond_code(); 
                break;
            case 3: 
                run_cmdline(); 
                break;
            case 4: 
                run_static_stack();
                break;
            case 5:
                run_dynamic_stack();
                break;
            case 6:
                run_queue();
                break;
            case 7:
                return (0);
            default: 
                printf("Invalid choice\n");
        }
    }
}