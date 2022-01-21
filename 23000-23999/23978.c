#include <stdio.h>

/*
문제 : N(1 <= N <= 10^6)개의 주어진 날(<= 10^9, 자연수, 오름차순)에 가격이 X원이 되고, 다른 날에는
가격이 0원이 될 때 까지 내려가는 물건이 있다. 이것을 날마다 팔 때, 수익이 K(1 <= K <= 10^18) 이상이
되도록 하는 가장 작은 X를 구한다.

해결 방법 : 매개 변수 탐색을 통해 답을 찾아나가면 된다. X에 대해 최솟값과 최댓값을 정하고,
등차수열의 합 공식을 이용해 수익을 구한 다음 K 이상인 가장 작은 X를 찾아나가면 된다.
이때, 최댓값 설정시 오버플로에 유의한다.

주요 알고리즘 : 수학, 파라메트릭

출처 : 한양대E 2021 H번
*/

int up[1048576];

long long getsum(long long s, long long e) {
    return ((s + e) * (e - s + 1)) >> 1;
}

int canbe(int n, int m, long long k) {
    long long s = 0;
    for (int i = 0; i < n - 1; i++) {
        if (up[i + 1] - up[i] > m) s += getsum(1, m);
        else s += getsum(m - up[i + 1] + up[i] + 1, m);
    }
    s += getsum(1, m);
    return (s >= k);
}

int main(void) {
    int n;
    long long k, lo = 1, hi = 0x7A35090F, mid;
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &up[i]);
    }
    while (hi > lo) {
        mid = (hi + lo) >> 1;
        if (canbe(n, mid, k)) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld", lo);
    return 0;
}