#include <stdio.h>

/*
문제 : 한 가게와 N(N <= 100)곳의 가게가 있을 때, 이 가게들에서 어떤 물건을 Yg당 X원에 판다면
1000g당 최저가를 구한다.

해결 방법 : 모든 가게에 대해 1000g당 가격을 구한 후 그 중 가장 작은 것을 구하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : COCI 12/13#2 1번
*/

int main(void) {
    int x, y, n;
    double best;
    scanf("%d %d", &x, &y);
    best = x * (1000.0 / y);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x * (1000.0 / y) < best) best = x * (1000.0 / y);
    }
    printf("%f", best);
    return 0;
}