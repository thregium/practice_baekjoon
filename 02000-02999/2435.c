#include <stdio.h>
#define INF 1012345678

/*
문제 : 길이 N(N <= 100)의 배열에서 연속한 K(K <= N)개 수의 합 가운데 가장 큰 것을 고른다.
배열에 있는 수들은 -100 이상 100 이하의 정수이다.

해결 방법 : 최댓값을 -무한대로 설정한 후 연속한 K개의 수들을 차례로 확인하며 가장 큰 것을 찾아가면 된다.

주요 알고리즘 : 브루트 포스
*/

int tem[128];

int main(void) {
    int n, k, s, best = -INF;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tem[i]);
    }
    for (int i = 0; i < n - k + 1; i++) {
        s = 0;
        for (int j = 0; j < k; j++) {
            s += tem[i + j];
        }
        if (s > best) best = s;
    }
    if (best == -INF) return 1;
    printf("%d", best);
    return 0;
}