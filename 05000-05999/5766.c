#include <stdio.h>

/*
문제 : N * M(N, M <= 400)개의 10000 이하의 자연수 가운데 2 번째로 많이 나온 수를 전부 구한다.

해결 방법 : 먼저 모든 수의 등장 횟수를 구한다. 그 다음 가장 많이 나온 수의 등장 횟수를 구한 후,
그보다 작으면서 가장 많이 나온 수의 등장 횟수를 구한 다음 그 수와 등장 횟수가 같은 수를 전부 출력하면 된다.

주요 알고리즘 : 구현

출처 : Latin 2004 G번
*/

int pts[10240];

int main(void) {
    int n, m, x, best, second;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n * m; i++) {
            scanf("%d", &x);
            pts[x]++;
        }
        best = -1;
        second = -1;
        for (int i = 1; i <= 10000; i++) {
            if (pts[i] > best) best = pts[i];
        }
        for (int i = 1; i <= 10000; i++) {
            if (pts[i] > second && pts[i] < best) second = pts[i];
        }
        for (int i = 1; i <= 10000; i++) {
            if (pts[i] == second) printf("%d ", i);
            pts[i] = 0;
        }
        printf("\n");
    }
    return 0;
}