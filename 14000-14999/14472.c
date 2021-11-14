#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 격자에 '.'과 '#'이 있다. 이 격자들 가운데 상하 또는 좌우로 연속해서 D칸이
'.'인 구간의 개수를 구한다.

해결 방법 : N과 M이 크지 않기 때문에 모든 구간을 직접 살펴보면 된다.

주요 알고리즘 : 브루트 포스

출처 : JOI 2017예 3번
*/

char room[128][128];

int main(void) {
    int n, m, d, r = 0, t = 0;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%s", room[i]);
    }
    for (int i = 0; i < n - d + 1; i++) {
        for (int j = 0; j < m; j++) {
            t = 1;
            for (int k = i; k < i + d; k++) {
                if (room[k][j] == '#') t = 0;
            }
            r += t;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - d + 1; j++) {
            t = 1;
            for (int k = j; k < j + d; k++) {
                if (room[i][k] == '#') t = 0;
            }
            r += t;
        }
    }
    printf("%d", r);
    return 0;
}