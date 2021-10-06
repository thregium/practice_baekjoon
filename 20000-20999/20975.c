#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20)개의 자연수(<= 10^9)로 이루어진 수열이 주어진다. 이 수열의 순서를 임의로 바꾸어
수열의 모든 수가 대응하는 두 번째 수열의 수 이하가 되도록 하는 경우의 수를 구한다.

해결 방법 : 첫 번째 수열의 각 수에 대해 대응 가능한 두 번째 수열의 개수를 각각 기록한다.
그 다음, 이를 오름차순으로 정렬하면 가장 매칭이 적은 수부터 앞쪽으로 오게 되는데, 매칭이 더 많은 수는
매칭이 더 적은 수의 모든 매칭을 포함하므로 각 수는 (현재 가능한 매칭 수 - 앞에서 했던 매칭 수) 만큼의 매칭이 가능하다.
따라서, 각 수마다 가능한 매칭의 수의 곱이 답이 된다.

주요 알고리즘 : 수학, 조합론, 그리디 알고리즘

출처 : USACO 2021J B3번
*/

int a[32], b[32], c[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] <= b[j]) c[i]++;
        }
    }
    qsort(c, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        r *= (c[i] - i);
    }
    printf("%lld", r);
    return 0;
}