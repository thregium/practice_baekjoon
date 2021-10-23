#include <stdio.h>

/*
문제 : 길이 N(N <= 100)의 M(M <= 10)개의 배열이 있다. 이때, 서로 다른 배열 쌍들 가운데 각각의 상대적인 크기 관계가
일치하는 배열 쌍의 개수를 구한다.

해결 방법 : N과 M이 작기 때문에 모든 쌍에 대해 직접 크기 관계를 확인해 일치하는지 살핀다.
먼저 모든 배열의 쌍을 확인한 후, 각 배열 내에서 모든 원소 쌍에 대해 크기 관계가 일치하는지 여부를 보면 된다.
크기 관계가 전부 일치하면 상대적 크기 관계가 일치하는 것이고, 일치하지 않는다면 상대적 크기 관계가 일치하지 않는 것이다.

주요 알고리즘 : 브루트 포스
*/

int pla[16][128];

int simp(int x) {
    if (x < 0) return -1;
    else if (x == 0) return 0;
    else return 1;
}

int main(void) {
    int m, n, r = 0, t = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &pla[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            t = 1;
            for (int k = 0; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    if (simp(pla[i][k] - pla[i][l]) != simp(pla[j][k] - pla[j][l])) t = 0;
                }
            }
            r += t;
        }
    }
    printf("%d", r);
    return 0;
}