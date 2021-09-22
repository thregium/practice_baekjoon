#include <stdio.h>

/*
문제 : N(N <= 4000)개의 전구가 일렬로 있다. 처음 상태와 M(M <= 4000)개의 명령이 주어지면 명령이 끝난 후 전구의 상태를 구한다.
1. B번째 전구의 상태를 C로 바꾼다.
2. B번째부터 C번째까지의 전구 상태를 반전시킨다.
3. B번째부터 C번째까지의 전구를 끈다.
4. B번째부터 C번째까지의 전구를 킨다.
전구를 끈 상태는 0, 킨 상태는 1로 주어진다.

해결 방법 : N과 M이 크지 않으므로 모든 명령에 대해 일일히 전구를 키고 끄면 된다.

주요 알고리즘 : 구현, 시뮬레이션
*/

int s[4096];

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) s[b] = c;
        else {
            for (int j = b; j <= c; j++) {
                if (a == 2) s[j] = !s[j];
                else if (a == 3) s[j] = 0;
                else s[j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", s[i]);
    }
    return 0;
}