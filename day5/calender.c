#include <stdio.h>

#define MINYEAR 2021
#define MAXYEAR 2031

int  daynum[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getdayweek(int y, int m, int d);

int main(void) {
	int year, month, i;

	printf("Type year (2021-2031), month(1-12) and Enter.:");
	fflush(stdout);
	scanf("%d %d", &year, &month);
	if( (year<MINYEAR) || (year>MAXYEAR) || (month<1) || (month>12) ) {
		printf("Illegal year or month.\n");
		return(-1);
	}

	printf("%d %d\nSun Mon Tue Wed Thr Fri Sat\n", year, month);
	for(i=0; i<getdayweek(year, month, 1); i++ ) {
		printf("    ");
	}
	for(i=1; i<=daynum[month]; i++) {
		printf(" %2d ", i);
		if(getdayweek(year, month, i)==6) {
			printf("\n");
		}
	}
	printf("\n");
	return (0);
}

int getdayweek(int y, int m, int d)
{
	if((m==1) || (m==2)) {
		y-=1; m+=12;
	}
	return (y+y/4-y/100+y/400+(13*m+8)/5+d)%7;
	/* return a day of the week in figures (sun:0, mon:1, ...) */ 
}
