#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 길 구간이 있다. 각 길 구간은 10000 이하의 자연수 거리를 가지며
단위 거리당 습격당하는 횟수의 기댓값 s(s <= 10, 음이 아닌 정수)를 갖는다.
이때, 자금 1로 특정한 1만큼의 거리에서 습격당하지 않도록 호위 병력을 배치할 수 있다면,
자금 M(M <= 10^9)으로 습격당하는 횟수를 최소한으로 했을 때의 습격당한 횟수의 기댓값을 구한다.

해결 방법 : 먼저 아무런 병력도 없을 때의 기댓값을 구한다. 이는 전체 길의 구간에 대해 길이 * s의 합이다.
여기서 각 구간을 s에 대해 내림차순으로 정렬한 다음, s가 높은 길부터 우선 호위 병력을 배치한다.
남는 자금이 길의 길이 이상이면 길 전체에 배치하고, 그보다 적다면 남는 자금만큼만 배치한다.
그리고 배치하며 기댓값을 줄이고 줄어든 기댓값을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : JAG 2008D B번
*/

int itv[10240][2];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m;
    long long r = 0;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &itv[i][0], &itv[i][1]);
            r += itv[i][0] * itv[i][1];
        }
        qsort(itv, n, sizeof(int) * 2, cmp1);
        for (int i = 0; i < n; i++) {
            if (m >= itv[i][0]) {
                m -= itv[i][0];
                r -= itv[i][0] * itv[i][1];
            }
            else {
                r -= m * itv[i][1];
                break;
            }
        }
        printf("%lld\n", r);
    }
    return 0;
}