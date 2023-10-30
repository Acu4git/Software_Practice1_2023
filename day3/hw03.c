/**
 * Q2
 */

#include <stdio.h>

int main() {
  int month, day, count;
  printf("Please enter the date here.\n");
  count = 0;
  do {
    if (count++ > 0) printf("Invalid input! (Month: 1~12)\n");
    printf("Month:\t");
    scanf("%d", &month);
  } while (month < 1 || month > 12);

  int days;
  switch (month) {
    case 1:
      days = 31;
      break;
    case 2:
      days = 28;
      break;
    case 3:
      days = 31;
      break;
    case 4:
      days = 30;
      break;
    case 5:
      days = 31;
      break;
    case 6:
      days = 30;
      break;
    case 7:
      days = 31;
      break;
    case 8:
      days = 31;
      break;
    case 9:
      days = 30;
      break;
    case 10:
      days = 31;
      break;
    case 11:
      days = 30;
      break;
    case 12:
      days = 31;
      break;
  }

  count = 0;
  do {
    if (count++ > 0)
      printf(
          "Invalid input! (Day: 1~28{Feb}, 1~30{Apr, Jun, Sep, Nov}, "
          "1~31{Others})\n");
    printf("Day:\t");
    scanf("%d", &day);
  } while (day < 1 || day > days);

  if (month == day && (day == 5 || day == 15 || day == 25)) {
    printf("%d/%d is the bargain day. It's also the quintuple-coupon day.\n",
           month, day);
  } else if (month == day) {
    printf("%d/%d is the bargain day.\n", month, day);
  } else if (day == 5 || day == 15 || day == 25) {
    printf("%d/%d is the quintuple-coupon day.\n", month, day);
  } else {
    printf("%d/%d is the normal day.\n", month, day);
  }

  return 0;
}