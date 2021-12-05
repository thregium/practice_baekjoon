#include <stdio.h>

/*
문제 : N개의 면을 가진 주사위와 M(4 <= N, M <= 20)개의 면을 가진 주사위를 동시에 굴릴 때, 두 주사위 눈의 합으로
나올 가능성이 가장 높은 수를 오름차순으로 전부 출력한다. 모든 면이 나올 확률은 같다.

해결 방법 : N > M이라고 할 때, M + 1부터 N + 1까지가 가장 나올 가능성이 크다.

주요 알고리즘 : 수학, 조합론

출처 : SWERC 2015 D번
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n < m) swap(&n, &m);
    for (int i = m + 1; i <= n + 1; i++) {
        printf("%d\n", i);
    }
    return 0;
}