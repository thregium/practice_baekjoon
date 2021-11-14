#include <stdio.h>

/*
문제 : N(N <= 50)개의 사탕과 각 사탕의 브랜드가 주어질 때, 1번부터 K번까지의 사탕을 하나씩 주는 방법의 수를 구한다.
브랜드 번호는 50 이하의 자연수로 주어진다.

해결 방법 : 각 브랜드별 사탕의 수를 센 다음, K가 1일 때 부터 50일 때 까지의 방법의 수를 더하면 된다.
각 방법의 수는 1부터 K까지 사탕 수의 곱이다.

주요 알고리즘 : 수학, 조합론
*/

int cnt[64];

int main(void) {
    int n, b, r = 0, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b);
        cnt[b]++;
    }
    for (int i = 1; i <= 50; i++) {
        t = 1;
        for (int j = 1; j <= i; j++) {
            t *= cnt[j];
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}