#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 점이 주어질 때, 원점에서 속도 v_i(v_i <= 1000)로 해당 점까지 이동한다면
도착하는 순서대로 점들의 번호를 출력한다. 동시에 도착하는 경우 번호가 작은 것이 우선이다.

해결 방법 : 해당 점까지의 이동 시간의 제곱을 구한 다음, 이를 비교해 이 값 -> 번호 순으로 정려하고 출력하면 된다.

주요 알고리즘 : 기하학, 정렬

출처 : 국민대 2016 PB번
*/

int miss[103000][4];

long long sqr(long long x) {
    return x * x;
}

int cmp1(const void* a, const void* b) {
    long long ax = *(int*)a;
    long long bx = *(int*)b;
    long long ay = *((int*)a + 1);
    long long by = *((int*)b + 1);
    long long av = *((int*)a + 2);
    long long bv = *((int*)b + 2);
    int ai = *((int*)a + 3);
    int bi = *((int*)b + 3);
    long long aa = sqr(ax) + sqr(ay);
    aa *= sqr(bv);
    long long ba = sqr(bx) + sqr(by);
    ba *= sqr(av);
    if (aa != ba) return aa > ba ? 1 : -1;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &miss[i][0], &miss[i][1], &miss[i][2]);
        miss[i][3] = i + 1;
    }
    qsort(miss, n, sizeof(int) * 4, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", miss[i][3]);
    }
    return 0;
}