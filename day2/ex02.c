#include <stdio.h>  //;を消した

int main(void) {
  int x, y;                     // zの削除
  int add, sub, mul, div, mod;  // subの追加

  printf("Please input two natural numbers and press ENTER KEY.:");
  fflush(stdout);
  scanf(" %d %d", &x, &y);
  printf("x = %d\ty = %d\n\n", x, y);  //;と&の追加

  add = x + y;
  printf("%d + %d = %d\n", x, y, add);  // yの追加
  sub = x - y;
  printf("%d - %d = %d\n", x, y, sub);
  mul = x * y;
  printf("%d * %d = %d\n", x, y, mul);
  div = x / y;
  printf("%d / %d = %d\n", x, y, div);
  mod = x % y;
  printf("%d %% %d = %d\n", x, y, mod);  //%fを%dに変更

  return (0);
}