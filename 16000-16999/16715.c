#include <stdio.h>

/*
문제 : 2진법부터 N진법까지로 N(N <= 100000)을 나타내었을 때의 표시되는 값 가운데 자릿수의 합이 가장 큰 것과 그때의 합을 구한다.

해결 방법 : 2진법부터 N진법까지의 각 진법에 대해 N의 자릿수를 확인하고 그 합을 구한다.
그 값들 가운데 가장 큰 것을 고르면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : 나코더 2018 I번
*/

int main(void) {
    int n, s, r = -1, m = -1;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        s = 0;
        for (int j = n; j; j /= i) s += j % i;
        if (s > m) {
            m = s;
            r = i;
        }
    }
    printf("%d %d", m, r);
    return 0;
}