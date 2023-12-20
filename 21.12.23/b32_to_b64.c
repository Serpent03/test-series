#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
    printf("\n");
}

int base32(char in) {
  printf("%c :: %d\n", in, in - 65);
    if (in >= 'A' && in <= 'Z') {
        return (int)in - 65;
    }
    if (in >= '2' && in <= '7') {
        return (int)in - 4; 
    }
    return 0; // if the character is for padding
}

int main() {
    // how the heck do you encode base32 to base64 ?? lol
    
    int N;
    // scanf("%d", &N);
    
    // char inp[201];
    // scanf("%s", inp);

    char inp[201];
    strcpy(inp, "ORXXAY3PMRSXE==="); 

    unsigned int binaryMessage = 0;
    char decodedString[201];
    int idx = 0;
    int mask = ~((~0) << 8);
    
    // binaryMessage |= base32(inp[0]);
    // bin(binaryMessage);
    // binaryMessage <<= 5; // base32 has a length of 5 bits
    // binaryMessage |= base32(inp[1]);
    // bin(binaryMessage);
    // binaryMessage <<= 5;
    // binaryMessage |= base32(inp[2]);
    // bin(binaryMessage);
    // binaryMessage &= mask; // retain only one byte
    // bin(binaryMessage);
    
    binaryMessage |= base32(inp[0]);
    binaryMessage <<= 3; // necessary
    bin(binaryMessage);
    binaryMessage |= base32(inp[1]);
    bin(binaryMessage);
    bin(mask);
    binaryMessage &= mask;
    bin(binaryMessage);
    printf("%c", binaryMessage);
    
    // for (int i = 0; i < strlen(inp); i += 2) {
    //     binaryMessage |= base32(inp[i]);
    //     binaryMessage <<= 5;
    //     bin(binaryMessage);
    //     binaryMessage |= base32(inp[i+1]);
    //     binaryMessage &= mask;
    //     // printf("%d\n", binaryMessage);
    // }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
