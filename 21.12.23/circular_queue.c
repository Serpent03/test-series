#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int front;
    int rear;
    int size;
    int* arr;
} MyCircularQueue;

typedef MyCircularQueue cq;

bool full(cq* q) {
    return (
        q -> front == 0 && q -> rear == q -> size - 1 
        ||
        q -> front - 1 == q -> rear
    );
}

bool empty(cq* q) {
    return q -> front == -1;
    // both front and rear are -1 as long as the queue is empty
}

MyCircularQueue* myCircularQueueCreate(int k) {
    cq* cqueue = (cq*)calloc(1, sizeof(cq));
    cqueue -> size = k;
    cqueue -> arr = (int*)calloc(cqueue -> size, sizeof(int));
    cqueue -> front = -1;
    cqueue -> rear = -1;    
    return cqueue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (!full(obj)) {
        obj -> rear = (obj -> rear + 1) % obj -> size;
        obj -> arr[obj -> rear] = value;
        if (obj -> front == -1) {
            obj -> front = 0;
        }
        return true;
    }
    return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (!empty(obj)) {
        if (obj -> front == obj -> rear) {
            obj -> front = -1;
            obj -> rear = -1;
            // only one element is present in the queue 
        } else {
            obj -> front = (obj -> front + 1) % obj -> size;
        }
        return true;
    }
    return false;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (empty(obj)) {
        return -1;
    }
    return obj -> arr[obj -> front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (empty(obj)) {
        return -1;
    }
    return obj -> arr[obj -> rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return empty(obj);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return full(obj);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj -> arr);
    free(obj);
}
