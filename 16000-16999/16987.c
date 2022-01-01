#include <stdio.h>

/*
문제 : N(N <= 8)개의 계란이 일렬로 있다. 맨 왼쪽 계란부터 차례로 다른 계란과 부딛혀 최대한 많은 계란을 깨려고 할 때,
가장 많은 계란을 깼을 때 깨는 계란 개수를 구한다. 이미 깨진 계란이거나 깰 계란이 없으면 넘어가고,
계란을 깰 때는 두 계란의 내구도가 상대 계란의 무게만큼 줄어든다. 내구도가 0 이하가 되면 계란은 깨진다.

해결 방법 : 브루트 포스를 통해 첫 번째 계란부터 다른 계란과 부딛혀본다. 이때, 이미 깨진 계란이면 넘어가도록 해야 한다.
계란을 부딛힌 다음 상태를 바꾸고 다음 계란으로 넘어간다. 부딛힌 적이 없다면 부딛히지 않고 넘어가야 함에 유의한다.
N개의 모든 계란을 부딛혔다면 부딛힌 횟수를 살피고 최댓값을 구하면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹
*/

int egg[16][2];
int best = 0;

void track(int n, int p) {
    int cnt = 0;
    if (p == n) {
        for (int i = 0; i < n; i++) {
            if (egg[i][0] <= 0) cnt++;
        }
        if (cnt > best) best = cnt;
        return;
    }
    if (egg[p][0] <= 0) {
        track(n, p + 1);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == p) continue;
        if (egg[i][0] > 0) {
            egg[i][0] -= egg[p][1];
            egg[p][0] -= egg[i][1];
            track(n, p + 1);
            egg[i][0] += egg[p][1];
            egg[p][0] += egg[i][1];
            cnt++;
        }
    }
    if (cnt == 0) track(n, p + 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &egg[i][0], &egg[i][1]);
    }
    track(n, 0);
    printf("%d", best);
    return 0;
}