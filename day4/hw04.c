// Q2

#include <stdio.h>
#include <stdlib.h>

int main() {
  int a;
  printf("Please enter a natural number 10 or less.: ");
  scanf("%d", &a);

  if (a <= 0 || a > 10) {
    fprintf(stderr, "Invalid input.\n");
    exit(1);
  } else {
    int ans = 1;
    for (int n = 1; n <= a; n++) {
      ans *= n;
      printf("%d! = %d\n", n, ans);
    }
  }

  return 0;
}