#include <stdio.h>
#include <stdlib.h>

/*
문제 : 어떠한 자연수를 3으로 나누거나(3으로 나누어 떨어지는 경우) 2로 곱하는 것을 반복하고 이 과정에 나온 수들이 무작위 순서로 주어진다.
이 수들을 위에서 나온 순서대로 재배열해 출력한다.

해결 방법 : 위 과정을 반복할 수록 소인수 3의 개수는 줄어들고 2의 개수는 늘어나게 된다. 따라서, 각 수의 소인수 3의 개수와 2의 개수를 저장해둔 다음
3의 개수가 줄어드는 순으로, 2의 개수는 늘어나는 순으로 정렬하면 나온 순서가 된다.

주요 알고리즘 : 수학, 정수론, 그리디 알고리즘
*/

long long b[128][3];

int cmp1(const void* a, const void* b) {
    long long a2 = *(long long*)a;
    long long b2 = *(long long*)b;
    if (a2 != b2) return a2 > b2 ? 1 : -1;
    long long a3 = *((long long*)a + 1);
    long long b3 = *((long long*)b + 1);
    return a3 < b3 ? 1 : a3 == b3 ? 0 : -1;
}

int main(void) {
    long long n, x;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        b[i][2] = x;
        while (!(x & 1)) {
            b[i][0]++;
            x >>= 1;
        }
        while (!(x % 3)) {
            b[i][1]++;
            x /= 3;
        }
    }
    qsort(b, n, sizeof(long long) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%lld ", b[i][2]);
    }
    return 0;
}