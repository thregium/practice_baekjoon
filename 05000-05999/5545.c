#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 토핑이 주어지고, 토핑과 도우의 가격이 주어진다. 그리고 도우와 각 토핑의 칼로리가 주어지면,
가장 가격 대비 칼로리가 높은 것의 가격 대비 칼로리를 구한다. 토핑은 한 종류당 한 번씩만 올릴 수 있고, 몇 개든 올릴 수 있다.

해결 방법 : 모든 토핑의 가격이 같기 때문에 칼로리가 높은 것 부터 올리는 것이 이득이다.
칼로리 기준 내림차순으로 정렬한 다음, 계속 토핑을 올려가며 가장 가격 대비 칼로리가 높은 것을 고르면 된다.

주요 알고리즘 : 그리디 알고리즘, 수학, 정렬

출처 : JOI 2012예 3번
*/

int cal[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, b, d, bestc = 0, bestp = 0, nowc = 0, nowp = 0;
    scanf("%d", &n);
    scanf("%d %d%d", &a, &b, &d);
    bestc = d, bestp = a, nowc = d, nowp = a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cal[i]);
    }
    qsort(cal, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        nowc += cal[i];
        nowp += b;
        if ((long long)nowc * bestp > (long long)bestc * nowp) {
            bestc = nowc;
            bestp = nowp;
        }
    }
    printf("%d", bestc / bestp);
    return 0;
}