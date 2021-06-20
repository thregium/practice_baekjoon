#include <stdio.h>

/*
문제 : N(N <= 100)개의 바구니에 바구니 번호와 같은 번호의 공이 들어있다. M(M <= 100)회의 다음 연산을 수행한 후 각 바구니에 들어있는 공의 번호를 구한다.
a번 바구니와 b번 바구니의 공을 꺼내서 a번 바구니에 있던 공은 b번에, b번 바구니에 있던 공은 a번에 넣는다.

해결 방법 : 문제에 쓰인대로 구현한다.

주요 알고리즘 : 구현, 시뮬레이션
*/

int balls[128];

int main(void) {
    int n, m, a, b, t;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        balls[i] = i;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        t = balls[a];
        balls[a] = balls[b];
        balls[b] = t;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", balls[i]);
    }
    return 0;
}