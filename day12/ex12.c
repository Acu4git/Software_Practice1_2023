#define TRUE              -1
#define FALSE             0
#define MINYEAR           2021
#define MAXYEAR           2031
#define HOLIDAYNAMELENGTH 50
#define FIX               0
#define HAPPY             1

#include <stdio.h>

typedef struct {
    int year;
    int month;
    int day;
} date_t;

typedef struct {
    int type;
    int end_year;
    int start_year;
    int month;
    int day_or_week;
    char *name;
} holiday_t;

char *monthname[] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
// char *dayweekname[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int   isvaliddate(date_t d);
char *getholidayname(date_t d);
char *getdaysuffix(int day);
// int   getdayweek(date_t d);
// int   getweeks(int day);

int main( int argc, char *argv[] )
{
    date_t today;

    printf("Type year, month and day and Enter.:");
    fflush(stdout);
    if(scanf("%d %d %d", &(today.year), &(today.month), &(today.day))!=3 || !isvaliddate(today) ) {
        printf("Error. Illegal date.\n");
        return -1;
    }

    printf("Today is the %d%s of %s, %d. It is %s.\n", today.day, getdaysuffix(today.day), monthname[today.month], today.year, getholidayname(today) );
    return 0;
}

int isvaliddate(date_t d)
{
    static int daynum[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // date_t day229={d.year,2,29}, day301={d.year,3,1};

    if(1 <= d.day && d.day <= daynum[d.month]) {
        return TRUE;
    } else {
        return FALSE;
    }
}

char *getholidayname(date_t d)
{
    static holiday_t holidays[] = {
        {FIX, MAXYEAR, 1948, 1, 1, "New Year's Day" },
        {FIX, MAXYEAR, 1967, 2,11, "National Foundation Day" },
        {FIX, MAXYEAR, 2007, 4,29, "Showa Day" },
        {FIX, MAXYEAR, 1948, 5, 3, "Constitution Memorial Day" },
        {FIX, MAXYEAR, 2007, 5, 4, "Greenery Day" },
        {FIX, MAXYEAR, 1949, 5, 5, "Children's Day" },
        {FIX, MAXYEAR, 1946, 11, 3, "Culture Day" },
        {FIX, MAXYEAR, 1948, 11, 23, "Labor Appreciation Day" },
        {FIX,       0,    0, 0, 0, "no holiday" },
    };

    holiday_t *ph;

    for(ph=holidays; ph->end_year != 0; ph++) {
        if(ph->start_year <= d.year && d.year <= ph->end_year && ph->month == d.month && ph->day_or_week == d.day) {
            break;
        }
    }
    return ph->name;
}

char *getdaysuffix(int day)
{
    static char *suffix[]={"th", "st", "nd", "rd" };
    int last_1_digit = day % 10;

    switch(last_1_digit) {
        case 1:
        case 2:
        case 3:
            return suffix[last_1_digit];
            break;
    }
    return suffix[0];
}