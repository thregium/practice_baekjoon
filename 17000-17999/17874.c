#include <stdio.h>

/*
문제 : N * N(N <= 10000) 크기이고 높이가 4인 직육면체 형태를 수직 방향으로 h, 수평 방향으로 v만큼 떨어진 선으로 자를 때,
가장 부피가 큰 조각의 부피를 구한다.

해결 방법 : 각 방향으로 각각 h와 n - h, v와 n - v 중 큰 것을 찾고 그 둘을 곱한 것이 가장 큰 조각의 밑넓이이다.
높이가 4이므로 이 값에 4를 곱하면 가장 큰 값이 나온다.

주요 알고리즘 : 수학

출처 : Rocky 2019 A번
*/

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, h, v;
    scanf("%d %d %d", &n, &h, &v);
    h = big(n - h, h);
    v = big(n - v, v);
    printf("%d", h * v * 4);
    return 0;
}