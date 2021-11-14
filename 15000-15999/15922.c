#include <stdio.h>
#include <stdlib.h>

/*
문제 : 수직선상에 N(N <= 100000)개의 선을 그었을 때, 선의 합집합의 길이를 구한다.

해결 방법 : 선들의 시작점과 끝점들을 확인하고, 시작점이 오면 현재 선분의 개수를 1 늘리고, 끝점이 오면 1 줄인다.
현재 선분의 개수가 1 이상인 구간의 길이 합을 더하면 된다.

주요 알고리즘 : 스위핑

출처 : 선린 2회 G번
*/

int lines[204800][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, ls = 0;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lines[i << 1][0], &lines[(i << 1) + 1][0]);
        lines[(i << 1) + 1][1] = 1;
    }
    qsort(lines, n * 2, sizeof(int) * 2, cmp1);
    for (int i = 0; i < (n << 1); i++) {
        if (i > 0 && ls > 0) r += lines[i][0] - lines[i - 1][0];
        if (lines[i][1] == 0) ls++;
        else ls--;
    }
    printf("%lld", r);
    return 0;
}