#include <stdio.h>

/*
문제 : N * N(N <= 1000) 크기 격자에 0과 1이 쓰여있다. N개 이하의 비트를 뒤집어 한 행 또는 열을 1로,
나머지 행 또는 열을 0으로 할 수 있는 지를 행, 열에 대해 구한다.

해결 방법 : 각 행과 열의 1 개수와 전체 1 개수를 센 다음, 각 행, 열에 대해서 그 행의 0 개수(N - cnt)와
그 행이 아닌 곳의 1 개수(tot - cnt) 합이 N 이하인 가로줄과 세로줄이 있는 지 각각 확인한다.

주요 알고리즘 : 브루트 포스, 누적 합

출처 : KTH 2022 H번
*/

char bar[1024][1024];
int hor[1024], ver[1024];
const char* bars = " -|+";

int main(void) {
    int n, tot = 0, res = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", bar[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (bar[i][j] == '1') {
                hor[i]++;
                ver[j]++;
                tot++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (n - hor[i] + tot - hor[i] <= n) res |= 1;
        if (n - ver[i] + tot - ver[i] <= n) res |= 2;
    }

    if (res == 0) return 1;
    printf("%c", bars[res]);
    return 0;
}