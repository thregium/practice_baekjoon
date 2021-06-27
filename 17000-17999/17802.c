#include <stdio.h>

/*
문제 : N(N <= 20)층이고 맨 위의 값이 X(X <= 10^6)인 합 피라미드를 만든다. 만들 수 없는 경우 Impossible을 출력한다.

해결 방법 : 먼저 맨 밑칸이 전부 1이라고 가정하면 맨 위의 수는 2^(N - 1)이 된다. 즉, X가 2^(N - 1)보다 작다면 만들 수 없다.
2^(N - 1)보다 크다면 맨 왼쪽 값을 키우면 그대로 각 층의 맨 왼쪽 값이 그만큼 늘어나기 때문에,
바닥칸이 전부 1이고 맨 왼쪽의 값만 늘어나는 수만큼 키운 수를 쓰면 된다.

주요 알고리즘 : 애드혹, 구성적

출처 : UKIEPC 2019 I번
*/

int main(void) {
    int n, x, l;
    scanf("%d %d", &n, &x);
    l = x - (1 << (n - 1));
    if (l < 0) {
        printf("impossible");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", l + (1 << (n - 1 - i)));
        for (int j = 1; j <= i; j++) {
            printf("%d ", (1 << (n - 1 - i)));
        }
        printf("\n");
    }
    return 0;
}