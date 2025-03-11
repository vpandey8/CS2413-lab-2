#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* stack_in;
    int* stack_out;
    int top_in;
    int top_out;
    int capacity;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)malloc(sizeof(MyQueue));
    queue->capacity = 100;
    queue->stack_in = (int*)malloc(queue->capacity * sizeof(int));
    queue->stack_out = (int*)malloc(queue->capacity * sizeof(int));
    queue->top_in = -1;
    queue->top_out = -1;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack_in[++(obj->top_in)] = x;
}

int myQueuePop(MyQueue* obj) {
    if (obj->top_out == -1) {
        while (obj->top_in != -1) {
            obj->stack_out[++(obj->top_out)] = obj->stack_in[(obj->top_in)--];
        }
    }
    return obj->stack_out[(obj->top_out)--];
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top_out == -1) {
        while (obj->top_in != -1) {
            obj->stack_out[++(obj->top_out)] = obj->stack_in[(obj->top_in)--];
        }
    }
    return obj->stack_out[obj->top_out];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top_in == -1 && obj->top_out == -1;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack_in);
    free(obj->stack_out);
    free(obj);
}

// Example usage:
// int main() {
//     MyQueue* myQueue = myQueueCreate();
//     myQueuePush(myQueue, 1);
//     myQueuePush(myQueue, 2);
//     printf("%d\n", myQueuePeek(myQueue));  // Output: 1
//     printf("%d\n", myQueuePop(myQueue));   // Output: 1
//     printf("%d\n", myQueueEmpty(myQueue)); // Output: 0 (false)
//     myQueueFree(myQueue);
//     return 0;
// }