#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^10)이 주어질 때, 연속합이 N이 되는 구간을 N N을 제외하고 모두 출력한다.
순서는 상관하지 않는다.

해결 방법 : 각 수를 중심으로 두었을 때를 생각해보면 한쪽을 홀수, 나머지 한쪽을 자연수로 둔
배수의 형태로 바꿀 수 있다. 각 형태의 시작점이 1 이상이고 아직 사용하지 않은 시작점이라면
그 구간을 출력한다.

주요 알고리즘 : 수학, 정수론

출처 : COCI 16/17#7 2번
*/

long long ptd[1024], pcnt;

void swap(long long* a, long long* b) {
    long long c = *a;
    *a = *b;
    *b = c;
}

int found(long long x) {
    for (int i = 0; i < pcnt; i++) {
        if (ptd[i] == x) return 1;
    }
    return 0;
}

void printcon(long long x, long long n) {
    long long y = n / x;
    for (int i = 0; i < 2; i++) {
        if (x & 1) {
            if (y - (x >> 1) >= 1 && x > 1) {
                if (!found(y - (x >> 1))) {
                    ptd[pcnt++] = y - (x >> 1);
                    printf("%lld %lld\n", y - (x >> 1), y + (x >> 1));
                }
            }
            if ((x >> 1) - y + 1 >= 1) {
                if (!found((x >> 1) - y + 1)) {
                    ptd[pcnt++] = (x >> 1) - y + 1;
                    printf("%lld %lld\n", (x >> 1) - y + 1, (x >> 1) + y);
                }
            }
        }
        swap(&x, &y);
    }
}

int main(void) {
    long long n, d;
    scanf("%lld", &n);
    for (long long i = 1; i * i <= n; i++) {
        if (n % i) continue;
        printcon(i, n);
    }
    return 0;
}