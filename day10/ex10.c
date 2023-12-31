#include <stdio.h>

int isinteger(char *arg);

int main( int argc, char *argv[] )
{
	int i;
	int count = 0;

	if(argc>9) {
		printf("Illegal number of argument.\n");
		return(-1);
	}
	
	for(i = 1; i < argc ; i++) {
		if( isinteger(argv[i]) ){
			count++;
		}
	}
	printf("Number of integer argument is %d.\n", count);

	return (0);
}

int isinteger(char *arg)
{
	if( (*arg == '-') || (*arg == '+') ){
		arg++;
	}

	do {
		if( (*arg < '0') || (*arg > '9') ){
			return (0);
		}
		arg++;
	} while( *arg != '\0' );
	return (1);
}
