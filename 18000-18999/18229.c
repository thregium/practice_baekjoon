#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 배열이 주어진다. 이때, 왼쪽부터 가장 적은 개수의 값을 더해서 K 이상이 되는
가장 작은 수와 그때까지 더한 값의 개수를 구한다. 이러한 값은 하나 이상 있다.

해결 방법 : 문제에 주어진대로 구현한다. 왼쪽부터 값을 더해나가되, 작은 행부터 더하면 된다.

주요 알고리즘 : 구현

출처 : 인하대 2019 B번
*/

int hand[128][128], dist[128];

int main(void) {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &hand[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dist[j] += hand[j][i];
            if (dist[j] >= k) {
                printf("%d %d", j, i);
                return 0;
            }
        }
    }
    return 1;
}