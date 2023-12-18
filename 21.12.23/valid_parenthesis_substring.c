#include <stdbool.h>

typedef struct {
    int size;
    int top;
    int* arr;
} stack;

stack* init_stack(int size) {
    stack* s = (stack*)calloc(1, sizeof(stack));
    s -> top = -1;
    s -> size = size;
    s -> arr = (int*)calloc(s -> size + 1, sizeof(int));
    return s;
}

void push(stack* s, int x) {
    if (s -> top + 1 < s -> size) {
        s -> arr[++s -> top] = x;
    }
}

int pop(stack* s) {
    if (s -> top >= 0) {
        return s -> arr[s -> top--];
    } else {
        return '\0';
    }
}

int peek(stack* s) {
    if (s -> top >= 0) {
        return s -> arr[s -> top];
    } else {
        return '\0';
    }
}

bool isEmpty(stack* s) {
    return s -> top == -1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int longestValidParentheses(char* s) {
    int vp = 0;
    int out;

    stack* stk = init_stack(strlen(s));
    push(stk, -1);
    // we initialize from -1 because of the
    // 0-indexed array. If a closing bracket comes on index 1,
    // then 1 - (-1) will result in 2, which is correct 

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            push(stk, i);
        } else {
            if (!isEmpty(stk)) {
                pop(stk);
                // popping the index associated with the most recent
                // opening bracket
            }
            if (!isEmpty(stk)) {
                vp = max(vp, i - peek(stk));
                // if the stack is still filled, then we compute at what index we last
                // had leftover brackets to find our current maximum valid substring
            } else {
                push(stk, i);
            }
        }
    }
    return vp;
}