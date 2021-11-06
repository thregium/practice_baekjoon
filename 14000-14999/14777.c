#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 400)개의 지점이 있고, 각 지점의 쌍 사이 이동하는데 드는 소요 시간(0 <, <= 10^6)이 주어진다.
각 지점들마다 주어지는 특정 시각(<= 10^9, 정수)에 그 지점에 있다면 1점을 얻을 때, 얻을 수 있는 최대 점수를 구한다.
어떤 지점에서 멈춰 있는 것이 가능하고, 우회해서 소요 시간이 적게 걸리더라도 우회하지 않는다.
시작시에는 1번 지점에 시각 0에서 시작한다.

해결 방법 : 각 지점들을 목표 시각 순서대로 정렬한다. 그 다음, 각 지점마다 목표 시각이 이전인 모든 지점 + 1번 지점(시각 0)을
확인하며 해당 시각에서 현재 지점에 목표 시각에 도달 가능한지를 살핀다.
가능한 경우에는 해당 지점에서 얻을 수 있는 최대 점수 + 1이 목표 지점의 최대 점수보다 큰 경우 갱신하면 된다.
그렇게 갱신하며 모든 지점 가운데 최대 점수를 출력하도록 한다.

주요 알고리즘 : DP, 정렬

출처 : USACO 2006O S1/G1번
*/

int p[512][2], t[512][512], mem[512];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i][0]);
        p[i][1] = i;
    }
    p[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &t[i][j]);
        }
    }
    qsort(p + 1, n, sizeof(int) * 2, cmp1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (p[j][0] + t[p[j][1]][p[i][1]] <= p[i][0]) {
                if (mem[j] + 1 > mem[i]) mem[i] = mem[j] + 1;
            }
        }
        if (mem[i] > r) r = mem[i];
    }
    printf("%d", r);
    return 0;
}