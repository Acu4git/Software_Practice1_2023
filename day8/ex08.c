#include <stdio.h>

int get_coins( int yen, int *n50, int *n10, int *n5, int *n1 );
int get_coin1( int *py, int unit );

int main(void) {
	int price, money, num_50, num_10, num_5, num_1;

	printf("Enter the price of your want and your money in hand (both 1-99 yen):" );
	fflush(stdout);
	if (scanf("%d %d", &price, &money)!=2 || price<1 || price>99 || money<1 || money>99 ) {
		printf("Invalid input(s). \n");
		return(-1);
	}

	printf("Your money is %d yen.\n", money);
	printf("It is represented by minimum %d coins: ", get_coins(money, &num_50, &num_10, &num_5, &num_1));
	printf("(50, 10, 5, 1)=(%d, %d, %d, %d)\n", num_50, num_10, num_5, num_1 );

	if( price > money ) {
		printf("It is short by %d yen to buy your want.\n", price - money );
	} else {
		printf("You can buy your want.\n");
		printf("Your change is %d yen.\n", money - price );
		printf("It is represented by minimum %d coins: ", get_coins(money - price, &num_50, &num_10, &num_5, &num_1));
		printf("(50, 10, 5, 1)=(%d, %d, %d, %d)\n", num_50, num_10, num_5, num_1 );
	}
	return 0;
}

int get_coins( int yen, int *n50, int *n10, int *n5, int *n1 )
{
	*n50 = get_coin1(&yen, 50);
	*n10 = get_coin1(&yen, 10);
	*n5  = get_coin1(&yen, 5);
	*n1  = get_coin1(&yen, 1);

	return *n50 + *n10 + *n5 + *n1;
}

int get_coin1( int *py, int unit )
{
	int n=0;

	if( *py >= unit ) {
		n = *py / unit;
		*py = *py % unit;
	}
	return n;
}
