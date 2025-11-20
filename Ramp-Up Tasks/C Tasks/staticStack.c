#include "staticStack.h"
#include <stdio.h>

void InitStaticStack(STACK_T* const st) {
    st->iTop = -1;
}

bool IsFull(STACK_T* const st) {
    return st->iTop == MAX - 1;
}

bool IsEmpty(STACK_T* const st) {
    return st->iTop == -1;
}

void Push(STACK_T* const st, int data) {
    if (IsFull(st)) {
        printf("Stack Overflow!\n");
        return;
    }
    st->STACK[++st->iTop] = data;
}

int Pop(STACK_T* const st) {
    if (IsEmpty(st)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return st->STACK[st->iTop--];
}

int Peep(STACK_T* const st) {
    if (IsEmpty(st)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return st->STACK[st->iTop];
}

void run_static_stack() {
    STACK_T myStack;
    InitStaticStack(&myStack);

    int choice, value;

    do {
        printf("\n----- Static Stack Menu -----\n");
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
                Push(&myStack, value);
                break;
            case 2:
                printf("Popped: %d\n", Pop(&myStack));
                break;
            case 3:
                printf("Top element: %d\n", Peep(&myStack));
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
}