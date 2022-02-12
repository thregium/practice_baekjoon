#include <stdio.h>

/*
문제 : N(N <= 100)개의 문제에 주어진 형태로 수들이 쓰인 주사위가 있다. 이 주사위들을 특정 지점에
주어진 방향으로 떨어뜨릴 때, 최종적으로 주사위들이 쌓인 상태에서 맨 위에 있는 수들의 개수를 각각 구한다.
주사위들은 4, 5, 6이 쓰인 방향으로 구를 수 있으며, 그쪽 방향으로 굴러서 내려가는 것이 가능한 경우
그 중 가장 큰 수가 쓰인 방향으로 구른다. 이는 더이상 구를 수 없을 때 까지 반복된다.

해결 방법 : 주사위를 1개씩 굴려나간다. 가운데 칸에서 출발하여 주사위들을 굴릴 방향을 찾고
그 방향으로 주사위의 방향을 바꾼 다음 이를 더이상 구를 곳이 없을 때 까지 반복한다.
모든 주사위를 굴린 다음, 맨 위에 있는 주사위들에 대해 위에 쓰인 수들마다 개수를 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JDC 2012 C번
*/

int ht[64][64], top[64][64], res[7];
int side[7][4] = { {0}, {2, 3, 5, 4}, {1, 4, 6, 3},
    {1, 2, 6, 5}, {1, 5, 6, 2}, {1, 3, 6, 4}, {2, 4, 5, 3} };
int dxy[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int main(void) {
    int n, t, f, fi = -1, x, y, d, roll;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            x = 32, y = 32;
            scanf("%d %d", &t, &f);
            for (int j = 0; j < 4; j++) {
                if (side[t][j] == f) fi = j;
            }
            roll = 1;
            while (roll) {
                roll = 0;
                d = -1;
                for (int j = 0; j < 4; j++) {
                    if (ht[x][y] + 1 > ht[x + dxy[j][0]][y + dxy[j][1]] + 1 &&
                        side[t][(j + fi) & 3] >= 4) {
                        if (d < 0 || (side[t][(d + fi) & 3] < side[t][(j + fi) & 3])) d = j;
                        roll = 1;
                    }
                }
                if (!roll) break;
                x += dxy[d][0];
                y += dxy[d][1];
                if (d == 0) f = t;
                else if (d == 2) f = 7 - t;
                t = side[t][(d + fi + 2) & 3];
                for (int j = 0; j < 4; j++) {
                    if (side[t][j] == f) fi = j;
                }
            }
            ht[x][y]++;
            top[x][y] = t;
        }
        for (int i = 0; i < 64; i++) {
            for (int j = 0; j < 64; j++) {
                res[top[i][j]]++;
                ht[i][j] = 0;
                top[i][j] = 0;
            }
        }
        for (int i = 1; i <= 6; i++) {
            printf("%d%c", res[i], i == 6 ? '\n' : ' ');
            res[i] = 0;
        }
    }
    return 0;
}