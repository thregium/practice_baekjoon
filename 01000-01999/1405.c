#include <stdio.h>

/*
문제 : 이동 횟수 N(N <= 14)과 상하좌우로 이동할 확률이 각각 주어질 때, N회 이동시 같은 지점을 지나지 않을 확률을 구한다.

해결 방법 : N의 크기가 작으므로 백트래킹을 이용한다. 시작점에서 출발해서 모든 주위 칸으로 이동해본다.
만약 이미 방문한 칸이라면 넘어가고 이동 가능하다면 해당 칸의 좌표로 이동 후 이동 확률에 해당 방향으로 이동할 확률을 곱한다.
이를 반복해 N회가 되면 결괏값에 해당 경로로 이동할 확률 p를 추가하고 다른 경로를 살펴본다.
모든 경우에 대해 반복한 결괏값이 답이 된다.

주요 알고리즘 : 수학, 확률론, 백트래킹
*/

int chk[32][32];
int prob[4];
int dxy[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
double res = 0.0;

void track(int n, int c, int x, int y, double p) {
    if (n == c) {
        res += p;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (chk[x + dxy[i][0]][y + dxy[i][1]]) continue;
        chk[x + dxy[i][0]][y + dxy[i][1]] = 1;
        track(n, c + 1, x + dxy[i][0], y + dxy[i][1], p * prob[i] / 100.0);
        chk[x + dxy[i][0]][y + dxy[i][1]] = 0;
    }
}

int main(void) {
    int n;
    scanf("%d %d %d %d %d", &n, &prob[0], &prob[1], &prob[2], &prob[3]);
    chk[16][16] = 1;
    track(n, 0, 16, 16, 1.0);
    printf("%.16f", res);
    return 0;
}