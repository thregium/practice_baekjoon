#include <stdio.h>

/*
문제 : N(N <= 20)개의 주사위에 있는 빈 칸에 모든 주사위를 합쳐서 점들을 M(M <= 100)개 찍을 수 있을 때,
모든 주사위를 던져 나오는 점의 개수 곱의 기댓값을 구한다.

해결 방법 : 각 주사위마다 점을 1개씩 찍어나가는 것이 최적이다.

주요 알고리즘 : 수학, 그리디 알고리즘, 확률론

출처 : UTI 2019 A번
*/

int paint[32];

int main(void) {
    int n, m;
    double res = 1.0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < n; j++) {
            if (m > 0) {
                m--;
                paint[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        res *= paint[i] / 6.0;
    }
    printf("%.9f", res);
    return 0;
}