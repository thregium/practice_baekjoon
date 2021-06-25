#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
문제 : N(N <= 5000)개의 수 가운데 합의 절댓값이 가장 작은 세 수를 찾는다.

해결 방법 : 수를 정렬한 후, 한 수를 고정시킨 다음 해당 수 다음 수와 가장 마지막 수에서부터 포인터를 좁혀가는 방식으로
세 수의 합이 0에 가까워지게 만드는 수의 쌍을 찾는다. 이 방법을 반복해 가장 절댓값이 작아지는 세 수를 찾으면 된다.

주요 알고리즘 : 정렬, 투 포인터

출처 : 정올 2010 고1번
*/

long long a[5120];
long long best = 12345678987654321, b[3];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, p1, p2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    qsort(a, n, sizeof(long long), cmp1);
    for (int i = 0; i < n; i++) {
        p1 = i + 1;
        p2 = n - 1;
        while (p1 < p2) {
            if (llabs(a[i] + a[p1] + a[p2]) < best) {
                best = llabs(a[i] + a[p1] + a[p2]);
                b[0] = a[i];
                b[1] = a[p1];
                b[2] = a[p2];
            }
            if (a[i] + a[p1] + a[p2] > 0) p2--;
            else p1++;
        }
    }
    qsort(b, 3, sizeof(long long), cmp1);
    printf("%lld %lld %lld", b[0], b[1], b[2]);
    return 0;
}