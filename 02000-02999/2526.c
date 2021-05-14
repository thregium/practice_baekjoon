#include <stdio.h>

/*
문제 : N(N <= 1000)에서 시작하여 N * N % P(P <= 97) 연산을 반복할 때 생기는 사이클의 길이를 구한다.

해결 방법 : P의 값이 작으므로 수를 직접 구해서 알아보면 된다.

주요 알고리즘 : 구현, 수학, 그래프 이론

출처 : 정올 2012지 초2번
*/

int order[1024];

int main(void) {
    int n, p, x;
    scanf("%d %d", &n, &p);
    x = n;
    for (int i = 1;; i++) {
        if (order[x]) {
            printf("%d", i - order[x]);
            return 0;
        }
        order[x] = i;
        x = (x * n) % p;
    }
    return 0;
}