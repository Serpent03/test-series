#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int bitAnd(int x, int y) {
  // max ops: 8
  // legal ops: ~, |
  return ~(~x | ~y);
}

int bitOr(int x, int y) {
  return ~(~x & ~y);
}

int bitXor(int x, int y) {
  // max ops: 14
  // legal ops: ~ &
  return bitOr((~x & y), (x & ~y));
}

int sign(int x) {
  // legal ops: ! ~ & ^ | + << >>
  // max ops : 10
  // return 1 if positive, 0 if zero, and -1 if negative

  // implementing the !!x operator reduces the dimensionality
  // of x from whatever number it was to either 0 or 1
  return !!x | x >> 31;
  // if x is 0, then x will be 0; as will be the bitshift operation to the right
  // if x > 0; !!x == 1, x >> 31 is 0. OR operation results in 1
  // if x < 0; !!x == 1, x >> 31 is 1
}

int getByte(int x, int n) {
  return (x >> (n * 8)) & 0xFF;
}

int logicalShift(int x, int n) {
  return x >> n & ~(0xF << (32 - n));
}

int conditional(int x, int y, int z) {
  // return (x) ? y : z
  // (!!x | y) - !!x
  printf("%d :: -%d --%d\n", !x, (!!x & y), (!x & z));
  return !!x & y & !!!x & z; 
}

int bang(int x) {
  // computer !x 
  return (x >> 31 | ((~x + 1) >> 31)) + 1;
}

int invert(int x, int p, int n) {
  // return x, with n bits that are inverted, starting from position p
  // 0111 1100, 3, 4
  //      ^  ^
  // 0111 0011
  int mask = ~(~0x0 << n);
  int maskShifting = p + 1 - n;
  int shiftedMask = mask << maskShifting;
  return x ^ shiftedMask;
}

int main() {
  // printf("%d :: %d", bitAnd(4, 5), 4 & 5);
  assert(bitAnd(4, 5) == 4 & 5);
  assert(bitXor(4, 5) == 4 ^ 5);
  assert(sign(-45) == -1);
  assert(getByte(0x12345678, 1) == 0x56);
  assert(logicalShift(0x87654321, 4) == 0x8765432);
  // assert(conditional(0, 4, 5) == 4);
  assert(bang(123) == 0);
  assert(invert(124, 3, 2) == 112);

}