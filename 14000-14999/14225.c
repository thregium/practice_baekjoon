#include <stdio.h>

/*
문제 : N(N <= 20)개의 자연수(<= 100000)로 이루어진 수열이 주어질 때, 이 수열의 부분수열의 합이 아닌 가장 작은 자연수를 구한다.

해결 방법 : 수열의 모든 부분수열의 합을 비트마스킹을 통해 2^N가지 경우에 대해 구하고 저장한다.
그리고, 1부터 확인하며 저장되지 않은 가장 작은 값을 출력하면 된다.

주요 알고리즘 : 브루트 포스, 비트마스킹
*/

char chk[2097152];
int a[32];

int main(void) {
    int n, s, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < (1 << n); i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) s += a[j];
        }
        chk[s] = 1;
    }
    for (int i = 1;; i++) {
        if (!chk[i]) {
            printf("%d", i);
            return 0;
        }
    }
    return 1;
}