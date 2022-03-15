#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 칸에 N개와 M개의 자연수(<= 1000) 각각의 곱들을 썼다.
쓴 수들에서 확인 가능한 숫자들(0 ~ 9)의 개수를 각각 출력한다.

해결 방법 : 각 자연수의 값을 구한 다음, 10으로 나누어 가며 자릿수들을 각각 세 나가면 된다.

주요 알고리즘 : 구현

출처 : JAG 2020D A번
*/

int a[128], b[128], cnt[10];

int main(void) {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = a[i] * b[j]; k; k /= 10) cnt[k % 10]++;
            }
        }
        for (int i = 0; i < 10; i++) {
            printf("%d%c", cnt[i], i == 9 ? '\n' : ' ');
            cnt[i] = 0;
        }
    }
    return 0;
}