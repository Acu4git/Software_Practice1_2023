// Q2(前回違う問題を解いちゃった)

#include <stdio.h>

int main() {
  int num;
  printf("Please enter an integer.: ");
  scanf("%d", &num);

  printf("Decimal number : %d\n", num);
  printf("Octal number : %o\n", num);
  printf("Hexadecimal number : %x\n", num);

  return 0;
}