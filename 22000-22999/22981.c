#include <stdio.h>
#include <stdlib.h>
#define INF 1234567890987654321

/*
문제 : N(2 <= N <= 200000)명의 작업 속도(<= 10^9)가 주어질 때, 두 조로 나누어 작업하면
K(K <= 10^18)의 작업량에 대한 작업 시간을 구한다.
각 조의 작업 시간은 인원수 * 가장 느린 사람의 작업 속도이다. 각 조의 인원은 최소 1명 이상 필요하다.

해결 방법 : 가장 느린 사람이 있는 조에 최대한 느린 사람을 밀어넣는 것이 최적임을 알 수 있다.
따라서, 모든 사람을 작업 시간 순으로 정렬한 다음, 두 조를 나누는 모든 경우를 살펴보며
그 중 가장 작업 시간이 빠른 것을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 브루트 포스

출처 : SUAPC 2021S A번
*/

int a[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

long long small(long long a, long long b) {
    return a < b ? a : b;
}

long long divu(long long u, long long d) {
    return (u + d - 1) / d;
}

int main(void) {
    int n;
    long long k, res = INF;
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (long long i = 1; i < n; i++) {
        res = small(res, divu(k, a[0] * i + a[i] * (n - i)));
    }
    printf("%lld", res);
    return 0;
}