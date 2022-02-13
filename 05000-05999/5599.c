#include <stdio.h>

/*
문제 : N * 2(N <= 100)장의 카드가 차례로 있다. M(M <= 1000)번 주어진대로 섞은 후 카드의 순서를 출력한다.

해결 방법 : 카드의 이동을 시뮬레이션한 후 그 결과를 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JOI 2007예 4번
*/

int card[256], tcard[256];

int main(void) {
    int n, m, k;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 2; i++) {
        card[i - 1] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        if (k) {
            for (int j = k; j < 2 * n; j++) tcard[j - k] = card[j];
            for (int j = 0; j < k; j++) tcard[j + 2 * n - k] = card[j];
        }
        else {
            for (int i = 0; i < n; i++) {
                tcard[i * 2] = card[i];
                tcard[i * 2 + 1] = card[i + n];
            }
        }
        for (int j = 0; j < 2 * n; j++) card[j] = tcard[j];
    }
    for (int i = 0; i < n * 2; i++) {
        printf("%d\n", card[i]);
    }
    return 0;
}