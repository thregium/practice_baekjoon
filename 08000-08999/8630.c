#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^18)이 주어질 때, 골롱 수열(a_1 = 1이고, 단조 증가하며,
각 자연수 k가 a_k회 있는 수열)의 N번째 수를 구한다.

해결 방법 : N <= 1011만까지 각 골롱 수열의 값을 구한 다음, 각 번째의 수에 대해 그 수열의 값만큼
건너 뛰어가며 현재의 수를 찾아나가면 된다. 

주요 알고리즘 : 수학, DP?

출처 : JPOI 2008 3-2번
*/

int a[32768];

int main(void) {
    long long n, p = 4, r = 1;
    scanf("%lld", &n);
    a[1] = 1;
    a[2] = 2;
    a[3] = 2;
    for (int i = 3; p < 30000; i++) {
        for (int j = 0; j < a[i]; j++) a[p++] = i;
    }
    p = 1;
    for (long long i0 = 1;; i0++) {
        for (long long i = 1; i <= a[i0]; i++) {
            if (n <= i0 * p) {
                for (long long j = 0; j < i0; j++) {
                    if (n <= p) {
                        printf("%lld", r);
                        return 0;
                    }
                    else {
                        n -= p;
                        r++;
                    }
                }
                break;
            }
            else {
                n -= i0 * p;
                r += i0;
            }
            p++;
        }
    }
    return 0;
}