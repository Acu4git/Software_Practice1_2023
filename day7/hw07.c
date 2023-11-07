//Q2
#include <stdio.h>

int route(int m, int n);

int main(){
    int m, n;
    printf("Let's solve the number of routes.\n");  
    printf("Please type the height and width of map.:");
    scanf("%d%d", &m, &n);

    if(m <= 0 || n <= 0 || m + n > 12){
        printf("Illegal height or width.\n");
        return -1;
    }

    printf("total: %d\n", route(m, n));
    return 0;
}

/**
 * m行n列の碁盤状道路の最短経路の総数 route(m, n)
 * -> スタート地点の隣の点から考える
 * -> 縦方向に移動した場合の最短経路 + 横方向に移動した場合の最短経路
 * -> route(m - 1, n) + route(m, n - 1)
*/
int route(int m, int n){
    if(m == 0 || n == 0){
        return 1;
    } else {
        return route(m - 1, n) + route(m, n - 1);
    }
}