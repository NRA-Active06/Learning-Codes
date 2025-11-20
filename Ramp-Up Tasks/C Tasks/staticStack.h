#ifndef STATIC_STACK_H
#define STATIC_STACK_H

#include <stdbool.h>
#define MAX 5

typedef struct {
    int STACK[MAX];  //since this one is static, fixed size
    int iTop;        
} STACK_T;

void InitStaticStack(STACK_T* const st);
void Push(STACK_T* const st, int data);
int Pop(STACK_T* const st);
bool IsFull(STACK_T* const st);
bool IsEmpty(STACK_T* const st);
int Peep(STACK_T* const st);
void run_static_stack(void);

#endif