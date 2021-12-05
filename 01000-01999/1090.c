#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 50)개의 체커가 매우 큰 체커 판에 있다. 각 체커 말들은 겹칠 수 있고, 상하좌우로 1칸씩 움직일 수 있다.
각 말들의 위치(자연수, <= 10^6)가 주어질 때, 체커 말들을 1개, 2개, ..., N개 겹치기 위해 필요한 최소 이동 횟수를 구한다.

해결 방법 : 각 체커 말들이 만나는 위치는 각 말들의 좌표의 중앙값이다.
따라서, 각 체커 말이 있는 X좌표와 Y좌표의 위치만 확인하면 된다. 각 위치에서의 거리를 구한 다음, 가까운 순으로 정렬한다.
K개의 거리의 합을 매번 구하고, 그 중 가장 가까운 것들을 찾아나간다. 마지막에 각 개수별 거리 합이 가장 작은 것들이 답이 된다.

주요 알고리즘 : 브루트 포스, 그리디 알고리즘?

출처 : SRM 423 D1A / D2B
*/

int pos[64][2], dist[64], res[64];

int small(int a, int b) {
    return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, y, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) res[i] = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x = pos[i][0], y = pos[j][1];
            for (int k = 0; k < n; k++) {
                dist[k] = abs(pos[k][0] - x) + abs(pos[k][1] - y);
            }
            qsort(dist, n, sizeof(int), cmp1);
            s = 0;
            for (int k = 0; k < n; k++) {
                s += dist[k];
                if (s < res[k]) res[k] = s;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    return 0;
}