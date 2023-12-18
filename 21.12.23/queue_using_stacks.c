#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int top;
    int size;
    int arr[101];
    // this can be malloc'd, but the problem
    // only expects up to 100 operations. plus one for margin   
} Stack;

Stack* STACK_INIT() {
    Stack* stack = (Stack*)calloc(1, sizeof(Stack));
    stack -> top = -1;
    stack -> size = 101;
    return stack;
}

bool IS_STACK_EMPTY(Stack* s) {
    return s -> top == -1;
}

void STACK_PUSH(Stack* s, int elem) {
    if (s -> top + 1 < s ->  size) {
        s -> arr[++s -> top] = elem;
    }
} 

int STACK_POP(Stack* s) {
    // if (s -> top >= 0) {
    //     return s -> arr[s -> top--];
    // }
    return s -> arr[s -> top--];
}

int STACK_PEEK(Stack* s) {
    // if (s -> top >= 0) {
    //     return s -> arr[s -> top];
    // }
    return s -> arr[s -> top];
}

typedef struct {
    Stack* s1; // this stack is for pushing
    Stack* s2; // this stack is for temporary storage
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* queue = (MyQueue*)calloc(1, sizeof(MyQueue));
    queue -> s1 = STACK_INIT();
    queue -> s2 = STACK_INIT();
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    STACK_PUSH(obj -> s1, x);
}

int myQueuePop(MyQueue* obj) {
    while (!IS_STACK_EMPTY(obj -> s1)) {
        STACK_PUSH(obj -> s2, STACK_POP(obj -> s1));
    }
    int ret = STACK_POP(obj -> s2);
    while (!IS_STACK_EMPTY(obj -> s2)) {
        STACK_PUSH(obj -> s1, STACK_POP(obj -> s2));
    }
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    while (!IS_STACK_EMPTY(obj -> s1)) {
        STACK_PUSH(obj -> s2, STACK_POP(obj -> s1));
    }
    int ret = STACK_PEEK(obj -> s2);
    while (!IS_STACK_EMPTY(obj -> s2)) {
        STACK_PUSH(obj -> s1, STACK_POP(obj -> s2));
    }
    return ret;
}

bool myQueueEmpty(MyQueue* obj) {
    return IS_STACK_EMPTY(obj -> s1);    
}

void myQueueFree(MyQueue* obj) {
    free(obj -> s1);
    free(obj -> s2);
    free(obj);
    // the array is assigned statically, so we can only call a free
    // the calloc'd queue structure
}
