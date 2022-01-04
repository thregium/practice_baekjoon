#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^9)이 주어질 때, x * phi(x) == N이 성립하는 가장 작은 X를 찾는다.
그러한 값이 없다면 -1을 출력한다.

해결 방법 : sqrt(N) 이상의 N의 모든 약수에 대해 phi(x)를 포함 배제를 이용하여 구한 다음,
X과 곱하여 N이 나오는 가장 작은 X를 구하면 된다.

주요 알고리즘 : 수학, 정수론, 오일러 피 함수, 포함 배제, 브루트 포스

출처 : SUAPC 2020S1 I번
*/

int div[256], pri[64], odd[103000], even[103000];

long long phi(int n) {
    long long r = 0, m = n;
    int pp = 0, op = 0, ep = 0, c, x;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            pri[pp++] = i;
        }
    }
    if (n > 1) pri[pp++] = n;
    for (int i = 0; i < (1 << pp); i++) {
        x = 1, c = 0;
        for (int j = 0; j < pp; j++) {
            if ((i >> j) & 1) {
                c++;
                x *= pri[j];
            }
        }
        if (c & 1) odd[op++] = x;
        else even[ep++] = x;
    }
    
    for (int i = 0; i < op; i++) {
        r -= m / odd[i];
    }
    for (int i = 0; i < ep; i++) {
        r += m / even[i];
    }

    return r;
}

int main(void) {
    int n, c = 0, r = -1;
    scanf("%d", &n);
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) div[c++] = n / i;
    }
    for (int i = 0; i < c; i++) {
        if (div[i] * phi(div[i]) == n) r = div[i];
    }
    
    printf("%d", r);
    return 0;
}