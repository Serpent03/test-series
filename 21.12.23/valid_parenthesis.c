#include <stdbool.h>

typedef struct {
    int top;
    int size;
    char* arr;
} STACK; 

void STACK_INIT(STACK* stack, int size) {
    stack -> size = size;
    stack -> top = -1;
    stack -> arr = (char*)calloc(size + 2, sizeof(char));
}

void STACK_PUSH(STACK* stack, char elem) {
    if (stack -> top + 1 < stack -> size) {
        stack -> arr[++stack -> top] = elem;
    }
    return;
}

char STACK_POP(STACK* stack) {
    if (stack -> top >= 0) {
        return stack -> arr[stack -> top--];
    } else {
        return '\0';
    }
}

bool IS_STACK_EMPTY(STACK* stack) {
    return stack -> top == -1;
}

bool isValid(char* s) {
    if (strlen(s) < 2) {
        return false;
    }
    
    STACK* stack = (STACK*)calloc(1, sizeof(STACK));
    STACK_INIT(stack, strlen(s));
    char out;
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            STACK_PUSH(stack, s[i]);
        }
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            out = STACK_POP(stack);
            if (out == '\0') {
                // called on an empty stack!
                return false;
            }
            if (out == '(' && s[i] != ')') {
                return false;
            }
            if (out == '[' && s[i] != ']') {
                return false;
            }
            if (out == '{' && s[i] != '}') {
                return false;
            }
        }
    }
    // incase the stack still has some leftover opening brackets,
    // they don't form a valid string anyway -- so if stack is still filled,
    // we return false
    return IS_STACK_EMPTY(stack);
}