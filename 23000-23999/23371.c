#include <stdio.h>

/*
문제 : N개의 칸과 S의 단위, K(N, S, K <= 1000)개의 데이터를 이용하여 만들어진
히스토그램을 출력한다.

해결 방법 : 각 칸의 등장 횟수를 센 다음 각 칸의 높이를 맞추어 출력한다.

주요 알고리즘 : 구현

출처 : BAPC 2021P H번
*/

int cnt[1024];

int main(void) {
    int n, s, k, x, h = 0;
    scanf("%d %d %d", &n, &s, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        cnt[(x + s - 1) / s]++;
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > h) h = cnt[i];
    }
    for (int i = h; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            if (cnt[j] >= i) printf("#");
            else printf(".");
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++) printf("-");
    return 0;
}