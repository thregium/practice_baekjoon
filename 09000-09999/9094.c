#include <stdio.h>

/*
문제 : N과 M(N, M <= 100)이 주어질 때, (0 < a < b < N)이면서 (a^2 + b^2 + M) / (a * b)가 정수인
(a, b)의 순서쌍의 개수를 구한다.

해결 방법 : (a^2 + b^2 + M)를 (a * b)로 나눈 나머지가 0이라면 이 값이 정수가 된다. 이를 이용하면 N이 매우 작은 편이므로
가능한 모든 a와 b에 대해 위 식의 나머지가 0인지 확인하고 그러한 것의 개수를 구하면 간단히 풀 수 있다.

주요 알고리즘 : 브루트 포스, 수학

출처 : Taejeon 2001 PB번
*/

int main(void) {
    int t, n, m, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        r = 0;
        for (int a = 1; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                if ((a * a + b * b + m) % (a * b) == 0) r++;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}