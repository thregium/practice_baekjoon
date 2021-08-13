#include <stdio.h>

/*
문제 : N(N <= 100)개의 바구니를 M(M <= 100)회 주어진 방식대로 섞었을 때, 마지막의 바구니 순서를 구한다.
i, j, k가 주어질 때, i번 바구니는 k번으로, i + 1번은 k + 1번, .. ?번은 j번, ? + 1번은 i번, ..., j번은 k - 1번으로 움직인다.

해결 방법 : 직접 매번 섞을 때 마다 바구니 순서를 확인해보면 된다. i번 이전과 j번 이후는 그대로 가고, i번과 j번 사이는
따로 변수를 선언해 어떤 바구니인지 확인할 수 있다.

주요 알고리즘 : 구현, 시뮬레이션
*/

int bas[128][128];

int main(void) {
    int n, m, a, b, c, p;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) bas[0][i] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        p = c;
        for (int j = 1; j < a; j++) bas[i][j] = bas[i - 1][j];
        for (int j = a; j <= b; j++) {
            bas[i][j] = bas[i - 1][p];
            p++;
            if (p > b) p = a;
        }
        for (int j = b + 1; j <= n; j++) bas[i][j] = bas[i - 1][j];
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", bas[m][i]);
    }
    return 0;
}