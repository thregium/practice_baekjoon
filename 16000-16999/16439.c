#include <stdio.h>

/*
문제 : N(N <= 30)명의 M(M <= 30)개의 치킨 브랜드에 대한 선호도가 주어진다. 3개의 치킨을 시킬 때, 만족도를 최대로
했을 때의 만족도를 구한다. 만족도는 각 사람의 시킨 치킨 가운데 가장 높은 선호도의 합이다.

해결 방법 : 3개의 치킨을 시키는 모든 방법을 시도해 보며 그 중 가장 만족도가 높은 것을 고르면 된다.

주요 알고리즘 : 브루트 포스

출처 : 경북대 2018 닭번
*/

int good[32][32];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, r = -1, s;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &good[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                s = 0;
                for (int l = 0; l < n; l++) {
                    s += big(good[l][i], big(good[l][j], good[l][k]));
                }
                if (s > r) r = s;
            }
        }
    }
    printf("%d", r);
    return 0;
}