#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 30)개의 물건 무게(<= 10^9)가 주어질 때, 전체 무게의 합이 C(C <= 10^9) 이하가 되도록
가방을 싸는 방법을 구한다. 아무것도 싸지 않는 것도 유효한 방법이다.

해결 방법 : 물건을 반으로 나누어 우선 모든 경우의 무게 합을 저장해 둔다.
그리고 나머지 절반에 대해 모든 경우를 확인하면서 이분 탐색으로 앞쪽 절반 가운데
무게가 맞도록 싸는 방법의 가짓수를 더해나가면 된다.

주요 알고리즘 : 밋 인 더 미들, 이분 탐색

출처 : ?
*/

int a[32];
long long weigh[32768];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, n1, n2, lo, hi, mid;
    long long s, r = 0;
    scanf("%d %d", &n, &c);
    n1 = n >> 1;
    n2 = n - n1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < (1 << n1); i++) {
        for (int j = 0; j < n1; j++) {
            weigh[i] += a[j] * ((i >> j) & 1);
        }
    }
    qsort(weigh, (1LL << n1), sizeof(long long), cmp1);
    for (int i = 0; i < (1 << n2); i++) {
        s = 0;
        for (int j = 0; j < n2; j++) {
            s += a[j + n1] * ((i >> j) & 1);
        }
        lo = -1, hi = (1 << n1) - 1;
        while (lo < hi) {
            mid = (lo + hi + 1) >> 1;
            if (weigh[mid] + s <= c) lo = mid;
            else hi = mid - 1;
        }
        r += lo + 1;
    }
    printf("%lld", r);
    return 0;
}