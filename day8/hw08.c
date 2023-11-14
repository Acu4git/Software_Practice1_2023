//Q2
#include <stdio.h>

void decompose(double x, int *r_int, double *r_frac);
int my_round(int r_int, double r_frac);

int main() {
  double x, r_frac;
  int r_int;

  printf("Enter a positive floating point number. : ");
  scanf("%lf", &x);

  if(x <= 0) {
    printf("Invalid input.\n");
    return -1;
  }

  decompose(x, &r_int, &r_frac);
  printf("Integer part : %d\n", r_int);
  printf("Decimal part : %lf\n", r_frac);
  printf("Rounded number : %d\n", my_round(r_int, r_frac));

  return 0;
}

void decompose(double x, int *r_int, double *r_frac) {
  *r_int = (int)x;
  *r_frac = x - *r_int;
}

int my_round(int r_int, double r_frac) {
  if(0.5 <= r_frac && r_frac < 1) {
    r_int++;
  }
  return r_int;
}