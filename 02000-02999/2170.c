#include <stdio.h>
#include <stdlib.h>

/*
문제 : 수직선 상의 N(N <= 10^6)개의 선분에 대해 선분이 하나라도 지나는 지점을 모두 합쳤을 때의 선분의 길이를 구한다.

해결 방법 : 모든 선분들의 시작점과 끝점들을 각각 배열에 저장한 후 좌표 순으로 정렬한다.
그 후 이 선분들을 좌표 순으로 살펴보며 이전 점과 현재 점 사이에 선이 몇 개 있는지 확인하고 1개 이상이면 해당 구간의 길이를
결괏값에 더한다. 현재 점이 선분이 끝나는 점이라면 선분의 개수를 1 줄이고, 시작하는 점이라면 선분의 개수를 1 늘인다.

주요 알고리즘 : 정렬, 스위핑
*/

int lines[2097152][2];

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