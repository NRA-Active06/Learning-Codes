#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} QUEUE_T;

bool InitQueue(QUEUE_T *q, int capacity);
void DeInitQueue(QUEUE_T *q);
bool Enqueue(QUEUE_T *q, int value);
int Dequeue(QUEUE_T *q);
int PeekQueue(QUEUE_T *q);
bool IsFullQueue(QUEUE_T *q);
bool IsEmptyQueue(QUEUE_T *q);
void DisplayQueue(QUEUE_T *q);
void run_queue(void);

#endif