#include <stdio.h>
#include <stdlib.h>
#define MX 2147483647

/*
문제 : N(N <= 200000)개의 재료들의 유통기한과 부패 속도, 중요한 지 여부가 주어지면,
중요하지 않은 재료를 K개까지 빼서 세균의 수가 G(G <= 10^9) 이하가 될 수 있는
음식을 먹는 최후의 시점을 구한다. 항상 1일차에는 음식을 먹을 수 있도록 주어진다.

해결 방법 : 음식을 먹는 시점으로 매개 변수 탐색을 한다. 매번 세균의 수 합이 G 이하인 지 확인하면 된다.
이 과정은 각 재료의 세균의 수를 센 다음, 내림차순으로 정렬하고 그리디하게 재료들을 빼내서 확인할 수 있다.
단, 모든 과정에서 오버플로에 주의한다. 특히 세균의 수를 셀 때에는 합이 G를 넘어가면 바로 종료해야
오버플로를 방지할 수 있다. 또한, 가능한 최댓값이 2 * 10^9임에도 주의한다.

주요 알고리즘 : 그리디 알고리즘, 파라메트릭, 정렬

출처 : GBOJ 2021 C번
*/

unsigned long long mkt[204800][3], germ[204800][2];

int cmp1(const void* a, const void* b) {
    unsigned long long ai = *(unsigned long long*)a;
    unsigned long long bi = *(unsigned long long*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int edible(unsigned long long n, unsigned long long g, unsigned long long k, unsigned long long m) {
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (m <= mkt[i][1]) germ[i][0] = mkt[i][0];
        else germ[i][0] = mkt[i][0] * (m - mkt[i][1]);
        germ[i][1] = mkt[i][2];
    }
    qsort(germ, n, sizeof(unsigned long long) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (k > 0 && germ[i][1] == 1) {
            k--;
            continue;
        }
        sum += germ[i][0];
        if (sum > g) return 0;
    }
    return 1;
}

int main(void) {
    unsigned long long n, g, k, lo = 0, hi = MX, mid;
    scanf("%llu %llu %llu", &n, &g, &k);
    for (int i = 0; i < n; i++) {
        scanf("%llu %llu %llu", &mkt[i][0], &mkt[i][1], &mkt[i][2]);
    }
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (edible(n, g, k, mid)) lo = mid;
        else hi = mid - 1;
    }
    printf("%llu", lo);
    return 0;
}