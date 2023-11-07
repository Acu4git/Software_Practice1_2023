#include <stdio.h>

int fibonacci(int n);

int main(void)
{
    int n;

    printf(" input \"n\" \n ");
    fflush(stdout);
    scanf("%d", &n);

    if(n <= 0 || n > 20){
        printf("Input error.\n");
        return(-1);
    } else {
        printf("Entered number is %d.\n", n );
    }

    printf("fn = %d\n", fibonacci(n));
    return (0);
}

int fibonacci(int n)
{
    int fn, fn_1, fn_2;
    static int cnt=0;

    cnt++;
    if(n == 1 || n == 2){
        return (1);
    } else {
        fn_1 = fibonacci(n-1);
        fn_2 = fibonacci(n-2);
        fn   = fn_1 + fn_2;
        return (fn);
    }
}
