#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^18)이 주어질 때, 합이 N이 되도록 하는 10개 이하의 대칭수로 나타낸다.

해결 방법 : 매 단계마다 N 이하의 크기인 가장 긴 대칭수를 만든다. 그러면 다음 단계에서의 자릿수는
현재 단계의 자릿수를 D라고 했을 때, 최대 (D + 1) / 2이 된다. 첫 단계에서 최대 19자리가 나올 수 있으므로,
대칭수는 19->10->5->3->2->1->1로 많아야 7개면 충분하다. 이때 1->1이 되는 경우는 10이 나오는 경우로,
같은 자리 수를 2번 써야 하는 유일한 경우이다.

주요 알고리즘 : 

출처 : UKIEPC 2020 B번 // BAPC 2020 B번
*/

long long ns[16], b10[24];
int ncnt = 0;

int getdigits(long long n) {
    for (int i = 18; i > 0; i--) {
        if (n >= b10[i]) return i + 1;
    }
    return 1;
}

long long getpal(long long n) {
    if (n == 10) return 9;
    int digits = getdigits(n);
    long long fpal = 0;
    for (int i = 0, j = digits - 1; i <= j; i++, j--) {
        fpal += b10[i] * (n / b10[j] % 10);
        if (i != j) fpal += b10[j] * (n / b10[j] % 10);
    }
    if (fpal <= n) return fpal;
    long long m = n - b10[digits >> 1];
    fpal = 0;
    digits = getdigits(m);
    for (int i = 0, j = digits - 1; i <= j; i++, j--) {
        fpal += b10[i] * (m / b10[j] % 10);
        if (i != j) fpal += b10[j] * (m / b10[j] % 10);
    }
    return fpal;
}

int main(void) {
    b10[0] = 1;
    for (int i = 1; i <= 18; i++) b10[i] = b10[i - 1] * 10;
    long long n;
    scanf("%lld", &n);
    while (n > 0) {
        ns[ncnt++] = getpal(n);
        n -= ns[ncnt - 1];
    }
    printf("%d\n", ncnt);
    for (int i = 0; i < ncnt; i++) {
        printf("%lld\n", ns[i]);
    }
    return 0;
}