#include <stdio.h>
#include <math.h>
#define INF 1012345678

/*
문제 : 4개의 점이 주어질 때, 첫 번째 점에서 나머지 모든 점을 방문할 때 최단 거리를 구한다.
소숫점 이하는 버린다. 또한, 각 점의 좌표 범위는 절댓값 10 이하의 정수이다.

해결 방법 : 모든 경우의 수를 해본다. 매번 직전 위치와의 거리를 더해나가다 마지막 점에 도착했을 때의 거리 가운데
가장 작은 값을 찾고 출력하면 된다.

주요 알고리즘 : 브루트 포스, 기하학

출처 : 경찰대 2019 D번
*/

int pos[3][2], vis[3];
int r = INF;

int sqr(int x) {
    return x * x;
}

void track(int c, int x, int y, double t) {
    if (c == 3) {
        if (t < r) r = t;
        return;
    }
    for (int i = 0; i < 3; i++) {
        if (vis[i]) continue;
        vis[i] = 1;
        track(c + 1, pos[i][0], pos[i][1], t + sqrt(sqr(x - pos[i][0]) + sqr(y - pos[i][1])) + 0.00001);
        vis[i] = 0;
    }
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    track(0, x, y, 0);
    if (r >= INF) return 1;
    printf("%d", r);
    return 0;
}