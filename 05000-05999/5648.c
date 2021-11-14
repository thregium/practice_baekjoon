#include <stdio.h>
#include <stdlib.h>

/*
문제 : 주어진 N(N <= 10^6)개의 자연수를 역순으로 한 수들을 정렬한 결과를 출력한다.

해결 방법 : 자연수를 역순으로 한 수를 구하고, 그 수들을 배열에 넣은 다음 정렬해서 출력하면 된다.

주요 알고리즘 : 수학, 정렬

출처 : Phuket 2011 P1번
*/

long long a[1048576];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        y = 0;
        while (x) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        a[i] = y;
    }
    qsort(a, n, sizeof(long long), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%lld\n", a[i]);
    }
    return 0;
}