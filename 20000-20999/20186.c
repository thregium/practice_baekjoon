#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 5000)개의 자연수(<= 100000)들이 주어질 때, 해당 자연수 가운데 K(K <= N)개를 뽑는 방법 가운데
가장 점수가 큰 것을 고른다. 점수는 각 수를 뽑을 때의 점수의 합이고, 각 수의 점수는 해당 수에서 앞쪽 수 가운데
이미 뽑은 수를 뺀 값과 같다.

해결 방법 : 앞쪽에서 이미 뽑은 수는 어떠한 수를 뽑든 K에 따라 고정임을 알 수 있다.
따라서, 가장 큰 수들을 선택하면 항상 최적이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 정올 2020_2 초1번
*/

int a[5120];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    long long r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < k; i++) {
        r += a[i];
    }
    r -= k * (k - 1) / 2;
    printf("%lld", r);
    return 0;
}