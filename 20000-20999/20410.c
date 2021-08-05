#include <stdio.h>

/*
문제 : 선형 합동법에 따라 생성된 수열의 모듈로 M(M <= 100)와 시드 S(S < M), 첫 번째와 두 번째 수 X1, X2(X1, X2 < M)가 주어질 때,
X_i = (A * X_(i - 1) + C) 형태의 A와 C를 구한다. A와 C는 M보다 작은 음이 아닌 정수이다.

해결 방법 : M이 매우 작기 때문에, M 미만의 정수 전부에 대해 검사하더라도 시간 내로 찾는 것이 가능하다.

주요 알고리즘 : 브루트 포스, 수학

출처 : 아주대 2020 1A1/2A1번
*/

int main(void) {
    int m, s, x1, x2;
    scanf("%d %d %d %d", &m, &s, &x1, &x2);
    for (int a = 0; a < m; a++) {
        for (int c = 0; c < m; c++) {
            if ((a * s + c) % m == x1 && (a * x1 + c) % m == x2) {
                printf("%d %d", a, c);
                return 0;
            }
        }
    }
    return 0;
}