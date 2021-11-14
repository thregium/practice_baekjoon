#include <stdio.h>

/*
문제 : N(N <= 100)개의 바구니가 순서대로 있다. M(M <= 100)번의 바꾸는 연산 후 바구니의 순서를 출력한다.
각 연산시에는 I번 바구니부터 J번 바구니까지의 순서를 역순으로 한다.

해결 방법 : 문제에 주어진대로 구현한다. swap() 함수를 사용하고 for문에 변수를 2개 적용하는 방식으로 구현했다.

주요 알고리즘 : 구현, 시뮬레이션
*/

int a[128];

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, m, x, y;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        for (int j = x, k = y; j < k; j++, k--) {
            swap(&a[j], &a[k]);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}