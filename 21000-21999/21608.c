#include <stdio.h>

/*
문제 : N * N(N <= 20) 크기의 좌석에서 좌석을 배정하는 순서와 선호하는 사람 4명이 주어질 때, 좌석을 배정하고 만족도를 구한다.
각 사람은 상하좌우 4칸 가운데 가장 선호하는 사람이 많은 좌석에 앉으며, 그러한 자리가 여럿이라면 주위에 가장 빈 좌석이
많은 좌석에 앉는다. 그마저도 같다면 행 -> 열의 오름차순으로 앉는다.
만족도는 주위에 선호하는 사람이 0명이면 0, 1명이면 1, 2명이면 10, 3명이면 100, 4명이면 1000으로, 각 사람의 만족도의 합이다.

해결 방법 : 문제에 주어진대로 구현한다. 만족도를 구하기 위해서는 각 순서가 아닌 각 사람에 대한 선호하는 사람을
저장해야 함에 유의한다.

주요 알고리즘 : 구현, 시뮬레이션, 브루트 포스
*/

int seat[32][32], order[512], fav[512][4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, r = 0, best, score, bx, by;
    scanf("%d", &n);
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) seat[i][j] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) seat[i][j] = 0;
    }
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &order[i]);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &fav[order[i]][j]);
        }
    }

    for (int i = 0; i < n * n; i++) {
        best = -1, bx = -1, by = -1;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (seat[x][y] > 0) continue;
                score = 0;
                for (int d = 0; d < 4; d++) {
                    if (seat[x + dxy[d][0]][y + dxy[d][1]] == 0) score++;
                    for (int f = 0; f < 4; f++) {
                        if (seat[x + dxy[d][0]][y + dxy[d][1]] == fav[order[i]][f]) score += 10;
                    }
                }
                if (score > best) {
                    best = score;
                    bx = x, by = y;
                }
            }
        }
        if (bx < 0) return 1;
        seat[bx][by] = order[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            score = 1;
            for(int d = 0; d < 4; d++) {
                for (int f = 0; f < 4; f++) {
                    if (seat[i + dxy[d][0]][j + dxy[d][1]] == fav[seat[i][j]][f]) score *= 10;
                }
            }
            r += score / 10;
        }
    }
    printf("%d", r);
    return 0;
}