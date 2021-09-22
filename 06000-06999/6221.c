#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 20)개의 직사각형을 최대한 겹치게 쌓을 때, 쌓을 수 있는 최대 개수를 구한다. 직사각형을 회전시키는 것은 불가능하다.
그리고, 위에 올라오는 직사각형은 반드시 아래의 직사각형보다 가로와 세로의 길이가 모두 작아야 한다.

해결 방법 : 각 직사각형을 가로 -> 세로 순으로 정렬한 다음, 모든 직사각형들을 쌓는 경우와 쌓지 않는 경우로 나누어
비트마스킹을 통해 모든 경우를 시도해 본다. 각 경우에서 가로로는 이미 정렬된 상태일 것이므로 세로로 순서대로 쌓였는지 확인하여
순서대로 쌓이지 않은 경우는 무시하고, 순서대로 쌓인 경우들 가운데 최댓값을 구하면 된다.

주요 알고리즘 : 브루트 포스, 비트마스킹, 정렬

출처 : USACO 2007J B3번
*/

int bale[32][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    return ai > bi ? 1 : ai < bi ? -1 : aj > bj ? 1 : aj == bj ? 0 : -1;
}

int main(void) {
    int n, lb, best = 0, cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bale[i][0], &bale[i][1]);
    }
    qsort(bale, n, sizeof(int) * 2, cmp1);

    for (int i = 0; i < (1 << n); i++) {
        lb = 0;
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                cnt++;
                if (bale[j][1] <= lb) {
                    cnt = 0;
                    break;
                }
                else lb = bale[j][1];
            }
        }
        if (cnt > best) best = cnt;
    }
    printf("%d", best);
    return 0;
}