#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20000)개의 자연수가 주어질 때, 두 수의 합이 S(S <= 10^6) 이하인 쌍의 개수를 구한다.

해결 방법 : N개의 자연수를 정렬한 다음, 작은 수부터 시작해서 오른 쪽에서부터 범위를 좁혀나가며 합이 S 이하가 되는
마지막 위치를 구하는 동시에 해당 범위를 답에 더해나가면 된다.

주요 알고리즘 : 정렬, 투 포인터

출처 : USACO 2008J B1번
*/

int cows[20480];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s, r = 0, lo = 0, hi;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cows[i]);
    }
    hi = n - 1;
    qsort(cows, n, sizeof(int), cmp1);

    while (lo < hi) {
        while (cows[lo] + cows[hi] > s) hi--;
        r += ((hi - lo) > 0 ? (hi - lo) : 0);
        lo++;
    }
    printf("%d", r);
    return 0;
}