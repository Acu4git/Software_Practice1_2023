//Q2
#include <stdio.h>

int route(int m, int n);
int combination(int n, int r);

int main(){
    int m, n;
    printf("Let's solve the number of routes.\n");
    printf("Please type the height and width of map.:");
    scanf("%d %d", &m, &n);

    if(m <= 0 || n <= 0 || m + n > 12){
        printf("Illegal height or width.\n");
        return (-1);
    }

    printf("total: %d", route(m, n));
}

int route(int m, int n){
    return combination(m + n, n);
}

//総数nCrを求める
int combination(int n, int r) {
    int res = 1;
    for(int i = n; i >= n - r + 1; i--){
        res *= i;
    }
    for(int i = r; i >= 1; i--){
        res /= i;
    }

    return res;
}