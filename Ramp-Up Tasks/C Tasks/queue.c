#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

bool InitQueue(QUEUE_T *q, int capacity) {
    q->arr = (int*) malloc(sizeof(int) * capacity);
    if (!q->arr) 
        return false;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return true;
}

void DeInitQueue(QUEUE_T *q) {
    free(q->arr);
    q->arr = NULL;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = 0;
}

bool IsFullQueue(QUEUE_T *q) {
    return q->size == q->capacity;
}

bool IsEmptyQueue(QUEUE_T *q) {
    return q->size == 0;
}

bool Enqueue(QUEUE_T *q, int value) {
    if (IsFullQueue(q)) {
        printf("Queue is full!\n");
        return false;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
    return true;
}

int Dequeue(QUEUE_T *q) {
    if (IsEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

int PeekQueue(QUEUE_T *q) {
    if (IsEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->arr[q->front];
}

void DisplayQueue(QUEUE_T *q) {
    if (IsEmptyQueue(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%d ", q->arr[index]);
    }
    printf("\n");
}

void run_queue(void) {
    QUEUE_T q;
    int capacity, choice, value;

    printf("Enter the queue capacity: ");
    if (scanf("%d", &capacity) != 1 || capacity <= 0) {
        printf("Invalid capacity!\n");
        while (getchar() != '\n');
        return;
    }

    if (!InitQueue(&q, capacity)) {
        printf("Error: Could not allocate memory for queue.\n");
        return;
    }

    do {
        printf("\n----- Queue Menu -----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek Front\n4. Display Queue\n5. Back to Main Menu\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input!\n");
                    while(getchar() != '\n');
                    break;
                }
                Enqueue(&q, value);
                break;
            case 2:
                printf("Dequeued: %d\n", Dequeue(&q));
                break;
            case 3: {
                int frontVal = PeekQueue(&q);
                if (frontVal != -1)
                    printf("Front element: %d\n", frontVal);
                break;
            }
            case 4:
                DisplayQueue(&q);
                break;
            case 5:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    DeInitQueue(&q);
}