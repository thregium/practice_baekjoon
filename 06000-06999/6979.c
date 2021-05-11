#include <stdio.h>

/*
문제 : 길이 N(N < 1000)의 두 단조 감소하는 수열 X, Y가 있다. 이때, X[i] >= Y[j]이며 i > j일 때 두 원소 사이의 거리를
i - j, 그 외 경우 거리를 0으로 정의한다면 이 수열의 원소들 사이의 거리 중 가장 큰 것을 찾는다.

해결 방법 : 브루트 포스를 통해 두 수열의 모든 원소 쌍을 찾아보면 된다.

주요 알고리즘 : 브루트 포스

출처 : CCC 1996 5번
*/

int x[1024], y[1024];

int main(void) {
    int t, n, d;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        d = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &y[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (y[j] < x[i]) break;
                if (j - i > d) d = j - i;
            }
        }
        printf("The maximum distance is %d\n\n", d);
    }
    return 0;
}