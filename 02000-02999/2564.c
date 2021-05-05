#include <stdio.h>
#include <math.h>

/*
문제 : H * W 크기의 직사각형 테두리에 점이 N개(N, H, W <= 100) 있다. 직사각형 내부로 들어가는 것은 불가능하다면,
이후 주어진 점에서 N개의 점까지 이동하는데 걸리는 최단거리의 합을 구한다.

해결 방법 : 각 점들이 차지하는 변마다 경우의 수를 나누어 푼다.

주요 알고리즘 : 케이스 워크

출처 : 정올 2007지 초3번
*/

int pos[128][2];
int w, h, n;

int small(int a, int b) {
    return a < b ? a : b;
}

int dist(int x) {
    if (pos[x][0] == pos[n][0]) {
        return abs(pos[x][1] - pos[n][1]); //같은 변인 경우
    }
    if ((pos[x][0] == 1 && pos[n][0] == 2) || (pos[x][0] == 2 && pos[n][0] == 1)) {
        return small(pos[x][1] + pos[n][1], w * 2 - (pos[x][1] + pos[n][1])) + h; //서로 위, 아래 관계인 경우
    }
    if ((pos[x][0] == 3 && pos[n][0] == 4) || (pos[x][0] == 4 && pos[n][0] == 3)) {
        return small(pos[x][1] + pos[n][1], h * 2 - (pos[x][1] + pos[n][1])) + w; //서로 왼쪽, 오른쪽 관계인 경우
    }
    if ((pos[x][0] == 1 && pos[n][0] == 3) || (pos[x][0] == 3 && pos[n][0] == 1)) return pos[x][1] + pos[n][1]; //서로 왼쪽, 위인 경우
    if (pos[x][0] == 1 && pos[n][0] == 4) return w - pos[x][1] + pos[n][1]; //직사각형의 점은 위, 주어진 점은 오른쪽인 경우
    if (pos[x][0] == 2 && pos[n][0] == 3) return pos[x][1] + h - pos[n][1]; //직사각형의 점은 아래, 주어진 점은 왼쪽인 경우
    if ((pos[x][0] == 2 && pos[n][0] == 4) || (pos[x][0] == 4 && pos[n][0] == 2)) return w - pos[x][1] + h - pos[n][1]; //서로 오른쪽, 아래인 경우
    if (pos[x][0] == 3 && pos[n][0] == 2) return pos[n][1] + h - pos[x][1]; //직사각형의 점은 왼쪽, 주어진 점은 아래인 경우
    if (pos[x][0] == 4 && pos[n][0] == 1) return w - pos[n][1] + pos[x][1]; //직사각형의 점은 오른쪽, 주어진 점은 위인 경우
    return -7654321;
}

int main(void) {
    int d = 0;
    scanf("%d %d%d", &w, &h, &n);
    for (int i = 0; i <= n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) {
        d += dist(i);
    }
    if (d < 0) return 1;
    printf("%d", d);
    return 0;
}