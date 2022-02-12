#include <stdio.h>

/*
문제 : R * C(R, C <= 100) 크기의 격자에 1000 이하의 자연수가 적혀있다. 각 칸마다 그 칸의
상하좌우 4 방향 중 한 방향으로 이어진 칸들 가운데 그 칸의 수보다 작은 수만 있는 방향의 개수 합을 구한다.

해결 방법 : 각 칸마다 네 방향의 칸들에 대해 최댓값을 구하고,
그 최댓값이 해당 칸의 값보다 작은 것의 개수를 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : NEERC 2015N L번
*/

int a[128][128];

int main(void) {
    int r, c, hi, res = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            hi = 0;
            for (int k = 0; k < i; k++) {
                if (a[k][j] > hi) hi = a[k][j];
            }
            if (hi < a[i][j]) res++;
            hi = 0;
            for (int k = i + 1; k < r; k++) {
                if (a[k][j] > hi) hi = a[k][j];
            }
            if (hi < a[i][j]) res++;
            hi = 0;
            for (int k = 0; k < j; k++) {
                if (a[i][k] > hi) hi = a[i][k];
            }
            if (hi < a[i][j]) res++;
            hi = 0;
            for (int k = j + 1; k < c; k++) {
                if (a[i][k] > hi) hi = a[i][k];
            }
            if (hi < a[i][j]) res++;
        }
    }
    printf("%d", res);
    return 0;
}