#include <stdio.h>

#define MINYEAR 2021
#define MAXYEAR 2031
#define TRUE 1
#define FALSE 0

int  daynum[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int  fixholidays[][2] = { {1,1}, {2,11}, {2,23}, {4,29}, {5,3}, {5,4}, {5,5}, {8,11}, {11,3}, {11,23}, {0,0} };
int  happymondays[][2] = { {1,2}, {7,3}, {9,3}, {10,2}, {0,0} };


int isfixholiday(int m, int d);
int ishappymonday(int y, int m, int d);
int getdayweek(int y, int m, int d);
int getweeks(int day);

int main(void) {
	int year, month, i;

	printf("Type year (%d-%d), month(1-12) and Enter.:", MINYEAR, MAXYEAR );
	fflush(stdout);
	scanf("%d %d", &year, &month);
	if( (year<MINYEAR) || (year>MAXYEAR) || (month<1) || (month>12) ) {
		printf("Illegal year or month.\n");
		return(-1);
	}

	if( (month==2) && (getdayweek(year,2,29)!=getdayweek(year,3,1)) ) {
		daynum[2]++;
	}

	printf("%d %d\nSun Mon Tue Wed Thr Fri Sat\n", year, month);
	for(i=0; i<getdayweek(year, month, 1); i++ ) {
		printf("    ");
     	fflush(stdout);
	}
	for(i=1; i<=daynum[month]; i++) {
		printf(" %2d", i);
		fflush(stdout);
		if( isfixholiday(month,i) || ishappymonday(year,month,i) ) {
			printf("*");
			fflush(stdout);
		} else {
			printf(" ");
			fflush(stdout);
		}
		if(getdayweek(year, month, i)==6) {
			printf("\n");
		}
	}
	printf("\n");
	return (0);
}


int isfixholiday(int m, int d)
{
	int j;

	for(j=0; fixholidays[j][0] != 0 ; j++) {
		if( ( m == fixholidays[j][0]) && ( d == fixholidays[j][1] ) ) {
			return (TRUE);
		}
	}
	return (FALSE);
}


int ishappymonday(int y, int m, int d)
{
	int j;

	if(getdayweek(y,m,d) != 1) {
		return (FALSE);
	}
	for(j=0; happymondays[j][0] != 0 ; j++) {
		if(m == happymondays[j][0] && getweeks(d) == happymondays[j][1]) {
			return(TRUE);
		}
	}
	return(FALSE);
}


int getweeks(int d)
{
	return ((d-1)/7+1);
}


int getdayweek(int y, int m, int d)
{
	if((m==1) || (m==2)) {
		y-=1; m+=12;
	}
	return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;
	/* return a day of the week in figures (sun:0, mon:1, ...) */ 
}