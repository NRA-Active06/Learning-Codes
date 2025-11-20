#include "dynamicStack.h"
#include <stdio.h>
#include <stdlib.h>

bool InitDynamicStack(DYNAMIC_STACK_T* const st, int size) {
    st->STACK = malloc(size * sizeof(int));
    if (!st->STACK) return false;

    st->iTop = -1;
    st->iSize = size;
    return true;
}

void DeInitStack(DYNAMIC_STACK_T* const st) {
    free(st->STACK);
    st->STACK = NULL;
    st->iTop = -1;
    st->iSize = 0;
}

bool IsFullDynamic(DYNAMIC_STACK_T* const st) {
    return st->iTop == st->iSize - 1;
}

bool IsEmptyDynamic(DYNAMIC_STACK_T* const st) {
    return st->iTop == -1;
}

void PushDynamic(DYNAMIC_STACK_T* const st, int data) {
    if (IsFullDynamic(st)) {
        printf("Stack Overflow!\n");
        return;
    }
    st->STACK[++st->iTop] = data;
}

int PopDynamic(DYNAMIC_STACK_T* const st) {
    if (IsEmptyDynamic(st)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return st->STACK[st->iTop--];
}

int PeepDynamic(DYNAMIC_STACK_T* const st) {
    if (IsEmptyDynamic(st)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return st->STACK[st->iTop];
}

void run_dynamic_stack() {
    DYNAMIC_STACK_T st;
    int size;
    printf("Enter the stack size for dynamic stack: ");
    scanf("%d", &size);

    if(!InitDynamicStack(&st, size)) {
        printf("Error: Could not allocate memory for stack.\n");
        return;
    }

    int choice, value;

    do {
        printf("\n----- Dynamic Stack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top element)\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                PushDynamic(&st, value);
                break;
            case 2:
                printf("Popped: %d\n", PopDynamic(&st));
                break;
            case 3:
            {
                int top = PeepDynamic(&st);
                if (top != -1) {
                    printf("Top element: %d\n", top);
                } else {
                    printf("Stack is empty!\n");
                }
                break;
            }
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    DeInitStack(&st);
}