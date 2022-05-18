#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

/*
문제 : N(N <= 10^6)개의 동전함이 있다. 각 동전함의 크기가 N 이하일 때, 1부터 N까지의 크기의
동전이 각각 1개씩 있다면, 동전함에 동전들을 모두 넣는 경우의 수를 각각 구한다.

해결 방법 : 각 동전함의 크기를 오름차순으로 정렬한다. 만약 현재 가능한 최소 크기보다 동전함의 크기가
작은 것이 있는 경우에는 답이 0이 된다. 그러한 것이 없다면 각 동전함에 넣는 경우의 수는
가능한 최소 크기와의 차이와 같다. 따라서 그 값들을 모두 곱하면 답이 된다.

주요 알고리즘 : 수학, 조합론, 정렬

출처 : JPOI 2011 2-1번
*/

int a[1048576];

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
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i] <= i) r = 0;
        else r = (r * (a[i] - i)) % MOD;
    }
    printf("%lld", r);
    return 0;
}