#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int top;
    int size;
    int* arr;
} STACK;

STACK* STACK_INIT(int size) {
    STACK* stk = (STACK*)calloc(1, sizeof(STACK));
    stk -> size = size;
    stk -> arr = (int*)calloc(stk -> size, sizeof(int));
    stk -> top = -1;
    return stk;
}

void STACK_PUSH(STACK* stk, int x) {
    if (stk -> top + 1 < stk -> size) {
        stk -> arr[++stk -> top] = x;
    }
}

int STACK_POP(STACK* stk) {
    return stk -> arr[stk -> top--];
}

int main() {
    int N;
    scanf("%d", &N);
    
    STACK* stk = STACK_INIT(512);  
    while (N > 0) {
        char input[1024];
        char buffer[64];
        int bufferIdx = 0;
        int val1 = 0;
        int val2 = 0;
        scanf(" %[^\n]", input);
        
        for (int i = 0; i < strlen(input); i++) {
            if (isalnum(input[i])) {
                buffer[bufferIdx++] = input[i];
            }
            if (input[i] == ' ' && bufferIdx > 0) {
                // if bufferIdx > 0, then we've actually read some
                // alphanumeric characters, so the atoi() function does not trigger on just some
                // empty 0 filled buffer array
                buffer[bufferIdx] = '\0';
                bufferIdx = 0;
                STACK_PUSH(stk, atoi(buffer));
            }
            if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*') {
                if (input[i] == '+') {
                    val2 = STACK_POP(stk);
                    val1 = STACK_POP(stk) + val2;
                    STACK_PUSH(stk, val1);
                }
                if (input[i] == '-') {
                    val2 = STACK_POP(stk);
                    val1 = STACK_POP(stk) - val2;
                    STACK_PUSH(stk, val1);
                }
                if (input[i] == '*') {
                    val2 = STACK_POP(stk);
                    val1 = STACK_POP(stk) * val2;
                    STACK_PUSH(stk, val1);
                }
                if (input[i] == '/') {
                    val2 = STACK_POP(stk);
                    val1 = STACK_POP(stk) / val2;
                    STACK_PUSH(stk, val1);
                }
            }
            if (input[i] == '?') {
                break;
            }
        }
        printf("%d\n", STACK_POP(stk));
        N--;
    }
    return 0;
}