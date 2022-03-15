#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

/*
문제 : N(N <= 100000)개의 100000 이하인 자연수가 주어진다. 이때, 이 자연수들의 순서를 마음대로 하여
인접한 두 수들 가운데 어떤 쌍도 오른쪽 수가 왼쪽 수 - T(1 <= T <= 100000) 이상이 되도록
하는 방법의 가짓수를 구한다.

해결 방법 : 먼저 수들을 정렬한 다음 1부터 수들을 끼워넣는 것을 생각해 본다.
각 수를 끼워넣을 때 넣을 수 있는 위치의 개수는 가장 오른쪽에 넣는 경우 + 오른쪽 수가
(현재 수 - T) 이상인 경우이다. 이러한 수의 개수는 이분 탐색으로 찾을 수 있다.
현재 수를 포함해 이분 탐색 하면 현재 수는 반드시 현재 수 - T 이상이므로 추가 계산을 하지 않아도 된다.
그 다음 이 개수를 계속해서 곱해나가면 된다. 현재 수는 반드시 현재 수 - T 이상이므로
매번 해당하는 수는 1 이상이다.

주요 알고리즘 : DP, 이분 탐색, 조합론

출처 : JAG 2011W4 E번
*/

int d[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
};

int main(void) {
    int n, t, w = 1, lo, hi, mid;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    qsort(d, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        lo = 0, hi = i;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (d[mid] >= d[i] - t) hi = mid;
            else lo = mid + 1;
        }
        w = ((long long)w * (i - lo + 1)) % MOD;
    }
    printf("%d\n", w);
    return 0;
}