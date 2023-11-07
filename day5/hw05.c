// Q2
#include <stdio.h>

int daynum[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char specialdayname[][50] = {"regular", "the bargain", "the quintuple-coupon",
                             "the bargain and quintuple-coupon"};
char monthname[][10] = {
    "-",    "January", "February",  "March",   "April",    "May",     "June",
    "July", "August",  "September", "October", "November", "December"};
char suffix[][3] = {"-",  "st", "nd", "rd", "th", "th", "th", "th",
                    "th", "th", "th", "th", "th", "th", "th", "th",
                    "th", "th", "th", "th", "th", "th", "th", "th",
                    "th", "th", "th", "th", "th", "th", "th", "th"};

int main() {
  int month, day, count;

  printf("Please enter the date here.\n");
  count = 0;
  do {
    if (count++ > 0) printf("Invalid input! (Month: 1~12)\n");
    printf("Month:\t");
    scanf("%d", &month);
  } while (month < 1 || month > 12);

  count = 0;
  do {
    if (count++ > 0)
      printf(
          "Invalid input! (Day: 1~28{Feb}, 1~30{Apr, Jun, Sep, Nov}, "
          "1~31{Others})\n");
    printf("Day:\t");
    scanf("%d", &day);
  } while (day < 1 || day > daynum[month]);

  int index;
  if (month == day && (day == 5 || day == 15 || day == 25)) {
    index = 3;
  } else if (month == day) {
    index = 1;
  } else if (day == 5 || day == 15 || day == 25) {
    index = 2;
  } else {
    index = 0;
  }

  printf("%d%s day of %s is %s day.\n", day, suffix[day], monthname[month],
         specialdayname[index]);
}