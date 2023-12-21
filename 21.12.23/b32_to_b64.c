#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void bin(unsigned long long n) {
    for (unsigned long long i = 1ULL << 39ULL; i > 0; i >>= 1) {
        printf((n & i) ? "1" : "0");
    }
    printf("\n");
}

int base32(char in) {
    // printf("%c :: %d\n", in, in - 65);
    if (in >= 'A' && in <= 'Z') {
        return (int)in - 'A';
    }
    if (in >= '2' && in <= '7') {
        return (int)in - '2' + 26; 
    }
    return 0; // if the character is for padding: '='
}

void b32toi(char* inp, char* decodedString) {
    unsigned long long bm = 0;
    int bitLen = 0;
    int idx = 0;
    bool flush = false;

    for (int i = 0; i < strlen(inp); i++) {
        bm = (bm << 5) | base32(inp[i]);
        bitLen += 5;
        flush = bitLen == 40;
        // theoretically, we could take all the input here
        // and directly convert it to base64 with groups of 6bit 'words'
        while (flush) {
            decodedString[idx++] = (bm >> ((unsigned long long)bitLen - 8ULL)) & 0xFFULL;
            bitLen -= 8;
            if (bitLen == 0) {
                flush = false;
            }
        }
    }
    decodedString[idx] = '\0';
}

int main() {
    
    int N;
    // scanf("%d", &N);
    
    // char inp[201];
    // scanf("%s", inp);

    char inp[201];
    strcpy(inp, "NBQWG23FOJZGC3TL"); 

    char decodedString[201];
    b32toi(inp, decodedString);
    printf("%s", decodedString);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
