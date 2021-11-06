#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 행사에 대해 시작 시각(<= 100000)과 운영 시간(<= 100000)이 각각 주어질 때, 시간이 겹치지 않고
참가할 수 있는 행사의 최대 개수를 구한다.

해결 방법 : 끝나는 시각이 빠른 순서대로 행사 참가를 시도해보면 된다. 끝나는 시각이 더 늦는 행사에 참가하게 되면
나중에 시작 시각이 좀더 빠른 행사에 참가하지 못해 손해일 수 있기 때문이다.
각 행사의 시작 시각과 끝 시각을 각각 구해서 끝 시각을 기준으로 오름차순으로 정렬한 다음, 마지막으로 참가한 행사의
끝나는 시각 이후에 시작하는 행사에 계속 참가해 나가며 참가한 행사의 수를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2006O S2번
*/

int evt[10240][2];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0, e = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &evt[i][0], &evt[i][1]);
        evt[i][1] += evt[i][0];
    }
    qsort(evt, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        if (evt[i][0] >= e) {
            e = evt[i][1];
            r++;
        }
    }
    printf("%d", r);
    return 0;
}