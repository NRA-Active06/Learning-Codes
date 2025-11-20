#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

#include <stdbool.h>

typedef struct {
    int *STACK;   ///this one is dynamic, so it would be dynamically allocated size for the array
    int iTop;
    int iSize;    // additional 'size' member in struct
} DYNAMIC_STACK_T;

bool InitDynamicStack(DYNAMIC_STACK_T* const st, int size);
void DeInitStack(DYNAMIC_STACK_T* const st);
void PushDynamic(DYNAMIC_STACK_T* const st, int data);
int PopDynamic(DYNAMIC_STACK_T* const st);
bool IsFullDynamic(DYNAMIC_STACK_T* const st);
bool IsEmptyDynamic(DYNAMIC_STACK_T* const st);
int PeepDynamic(DYNAMIC_STACK_T* const st);
void run_dynamic_stack();

#endif