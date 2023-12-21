#include <stdio.h>
#include <stdlib.h>

int binaryLength(unsigned n) {
  int len = -1;
  for (unsigned int i = 1 << 31; i > 0; i >>= 1) {
    if (len > 0) {
      len++;
    }
    if (len == -1 && (n & i)) {
      len = 1;
    }
  }
  return (len == -1) ? 0 : len;
}

long long int _max(long long int a, long long int b) {
  return (a > b) ? a : b;
}

int main() {
  // given a number C,
  // computer A ^ B = C,
  // such that length(A) <= len(C) && len(B) <= len(C)
  // find the maximum possible pair of A * B


  int C = 13;
  int ibLenOfC = binaryLength(13);
  long long int maxProduct = 0;

  for (int i = 1; i < (1 << (ibLenOfC)); i++) {
    int B = i ^ C;
    maxProduct = _max(i * B, maxProduct);
  }

  printf("%lld", maxProduct);

}