#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 절댓값이 10^6 이하인 정수들이 주어질 때, 해당 수를 나누었을 때 모든 나머지가 같은
자연수 D 가운데 가장 큰 것을 구한다. 항상 존재하는 경우만 주어진다.

해결 방법 : 모든 수에서 가장 작은 수를 뺀 다음 나오는 가장 작은 수를 제외한 모든 수의 최대공약수가 답이 된다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법
*/

int a[1024], r[2048];
int rp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, g;
    scanf("%d", &n);
    int m = 1234567890;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < m) m = a[i];
    }
    for (int i = 0; i < n; i++) a[i] -= m;
    g = a[1];
    for (int i = 2; i < n; i++) {
        g = gcd(g, a[i]);
    }
    for (int i = 2; i * i <= g; i++) {
        if (g % i == 0) {
            r[rp++] = i;
            if (g / i != i) r[rp++] = g / i;
        }
    }
    r[rp++] = g;
    qsort(r, rp, sizeof(int), cmp1);
    printf("%d", r[rp - 1]);

    return 0;
}