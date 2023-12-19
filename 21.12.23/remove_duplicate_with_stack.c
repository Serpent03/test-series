#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char* arr;
    int top;
    int size;
} stack;

stack* init_stack(int size) {
    stack* s = (stack*)calloc(1, sizeof(stack));
    s -> size = size;
    s -> top = -1;
    s -> arr = (char*)calloc(s -> size, sizeof(char));
    return s;
}

bool isfull(stack* s) {
    return s -> top + 1 == s -> size;
}

bool isempty(stack* s) {
    return s -> top == -1;
}

void push(stack* s, char elem) {
    assert(!isfull(s));
    s -> arr[++s -> top] = elem;
}

char pop(stack* s) {
    assert(!isempty(s));
    return s -> arr[s -> top--];
}

char peek(stack* s) {
    assert(!isempty(s));
    return s -> arr[s -> top];
}

char* removeDuplicateLetters(char* s) {  
    if (strlen(s) == 1) {
        return s;
    }

    stack* stk = init_stack(strlen(s));

    int countOfElements[26] = {0}; // count
    int offset = 97; // a
    bool charactersInStack[26] = {false}; // 0 or 1
    char* outstr = (char*)calloc(27, sizeof(char));
    int ptr = 0;

    for (int i = 0; i < strlen(s); i++) {
        countOfElements[(int)s[i] - offset] += 1;
    }

    for (int i = 0; i < strlen(s); i++) {
        int curr = (int)s[i] - offset;
        countOfElements[curr] -= 1;
        if (charactersInStack[curr]) {
            continue;
        } // skip if element is already in the stack
        while (!isempty(stk) && s[i] < peek(stk) && countOfElements[(int)peek(stk) - offset] > 0) {
            // if s[i] < top of stack; then we need to pop until either:
            // - s[i] >= top of stack
            // - stack is not empty
            // - number of elements remaining in the string of the top of stack is 0, in which case
            // we can't pop the element any more
            char out = pop(stk);
            charactersInStack[(int)out - offset] = false;
        }
        push(stk, s[i]);
        charactersInStack[curr] = true;
    }
    // reverse the string
    // reversing the string through the stack is eating up a lot of time,
    // we're essentially performing 2n operations
    // a better solution is n/2 operations: a for loop!
    
    while (!isempty(stk)) {
        outstr[ptr++] = pop(stk);
    }
    free(stk);

    int r = strlen(outstr) - 1;
    int l = 0;

    while (l < r) {
        char c = outstr[l];
        outstr[l] = outstr[r];
        outstr[r] = c;
        l++;
        r--;
    }

    outstr[ptr] = '\0';
    return outstr;
}
