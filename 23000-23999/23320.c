#include <stdio.h>

/*
문제 : N(N <= 100)명의 점수가 주어지고, 상대평가시 A의 비율(X)과 절대평가시 A의 기준치(Y)가 주어지면
상대평가와 절대평가시 A를 받는 사람 수를 구한다. 비율은 백분율로 주어진다.

해결 방법 : 상대평가시 A를 받는 사람 수는 N * X / 100으로 구할 수 있고, 절대평가시 'A'를 받는 사람은 배열을
확인하여 구할 수 있다.

주요 알고리즘 : 구현, 수학

출처 : 홍익대 2021 A번
*/

int a[128];

int main(void) {
    int n, x, y, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d %d", &x, &y);
    for (int i = 0; i < n; i++) {
        if (a[i] >= y) r++;
    }
    printf("%d %d", n * x / 100, r);
    return 0;
}