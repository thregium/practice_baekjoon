#include <stdio.h>

/*
문제 : N(N <= 500000)개의 자연수가 주어질 때, 자연수 X(X <= 10^6)와 서로소인 자연수의 평균을 구한다.
서로소인 자연수는 최소 1개 이상 나온다.

해결 방법 : 유클리드 호제법을 이용하여 서로소 여부를 구하고 서로소인 수의 개수를 세면 된다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법
*/

int a[524288];

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, x;
    long long sum = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (gcd(a[i], x) == 1) {
            sum += a[i];
            cnt++;
        }
    }
    if (cnt == 0) return 1;
    printf("%.9f", (double)sum / cnt);
    return 0;
}