#include <stdio.h>

/*
문제 : N * N(N <= 25) 크기의 삼각형에 0 이상 3000 이하의 정수가 쓰여있다. 맨 위에서 아래 2칸 중 하나로 움직이며
나오는 정수들의 합 가운데 가장 큰 것을 구한다.

해결 방법 : 맨 위부터 시작해 아래로 내려오며 해당 위치의 합 최댓값을 구한다.
이는 위쪽 두 칸 가운데 더 큰 값이다. 맨 밑 줄의 값 가운데 가장 큰 것을 구하면 된다.

주요 알고리즘 : DP

출처 : USACO 2009N B3번
*/

int tri[600][600] = { 0, };
int trmx[600][600] = { 0, };

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, s = 0;
    scanf("%d", &n);
    //if(n <= 10) return 1 / 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) scanf("%d", &tri[i][j]);
    }
    trmx[0][0] = tri[0][0];
    for (int i = 1; i < n; i++) trmx[i][0] = tri[i][0] + trmx[i - 1][0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            trmx[i][j] = big(trmx[i - 1][j], trmx[i - 1][j - 1]) + tri[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (trmx[n - 1][i] > s) s = trmx[n - 1][i];
    }
    printf("%d", s);
    return 0;
}