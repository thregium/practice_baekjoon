#include <stdio.h>

/*
문제 : N(N <= 15)개의 재료의 영양성분과 가격이 주어진다.
선택한 재료의 영양성분 합이 목표치 이상이 되면서 최저가가 되도록 재료들을 선택할 때,
그렇게 선택하는 방법 가운데 사전순으로 가장 빠른 것을 구한다.
그러한 방법이 없는 경우 -1을 출력한다.

해결 방법 : 각 재료를 선택하거나 선택하지 않는 모든 경우를 구해나간다.
만약 현재 선택한 재료들이 목표 영양값에 도달했다면 가격이 현재까지 중에 가장 작은 지 확인하고
그러한 경우 결과 배열을 갱신한다.
경우의 수를 사전 순으로 탐색하기 때문에 같은 값인 경우 반드시 사전 순으로 처음 나오는 것을 선택하게 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : 정올 2020_1 중2번
*/

int mn[4], ing[16][5], stk[16], tsum[4], res[16];
int best = 103000, rcnt = 0;

void track(int n, int m, int cnt, int c) {
    int fin = 1;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < 4; j++) tsum[j] += ing[stk[i]][j];
    }
    for (int i = 0; i < 4; i++) {
        if (mn[i] > tsum[i]) fin = 0;
        tsum[i] = 0;
    }
    if (fin) {
        if (c < best) {
            best = c;
            for (int i = 0; i < cnt; i++) res[i] = stk[i];
            rcnt = cnt;
        }
        return;
    }
    for (int i = m; i < n; i++) {
        stk[cnt] = i;
        track(n, i + 1, cnt + 1, c + ing[i][4]);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &mn[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &ing[i][j]);
        }
    }
    track(n, 0, 0, 0);
    if (best == 103000) {
        printf("-1");
        return 0;
    }
    printf("%d\n", best);
    for (int i = 0; i < rcnt; i++) {
        printf("%d ", res[i] + 1);
    }
    return 0;
}