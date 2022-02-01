#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 200000)개의 버스 노선이 수직선상에 있다. 한 점이라도 겹치는 노선은 전부 통합한 후
가장 낮은 비용으로 통일한다고 할 때, 통합 이후의 버스 노선들을 좌표 오름차순으로 출력한다.

해결 방법 : 각 버스 노선의 시작점과 끝점을 배열에 저장 후 버스 노선의 수가 1 이상인 지점 동안을
하나의 버스 노선으로 한다. 비용은 그 중 가장 작은 것으로 선택하면 된다.

주요 알고리즘 : 정렬, 스위핑

출처 : 서강대 2021 D번
*/

int pos[409600][2], res[204800][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, s, e, c = 0, cnt = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &s, &e, &c);
        pos[i << 1][0] = s;
        pos[i << 1][1] = c;
        pos[(i << 1) + 1][0] = e;
        pos[(i << 1) + 1][1] = -c;
    }
    qsort(pos, n * 2, sizeof(int) * 2, cmp1);
    for (int i = 0; i < (n << 1); i++) {
        if (pos[i][1] > 0) {
            if (cnt++ == 0) {
                res[r][0] = pos[i][0];
                c = INF;
            }
            if (pos[i][1] < c) c = pos[i][1];
        }
        else {
            if (--cnt == 0) {
                res[r][1] = pos[i][0];
                res[r++][2] = c;
            }
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
    }
    return 0;
}