#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 격자에 각 칸마다 도미노가 있다. R(R <= 10000)개의 라운드 동안
주어지는 도미노를 주어진 방향대로 무너뜨리고(연쇄작용 있음),
또 주어진 위치의 도미노를 세우는 것을 반복한 후 도미노가 넘어진 횟수와 넘어진 도미노의 형태를 출력한다.
연쇄작용은 새로운 도미노가 무너지면 도미노의 크기 - 1만큼의 뒤 도미노들도 무너지게 되는 것을 말한다.
이미 무너진 도미노에서는 적용되지 않는다.

해결 방법 : 도미노의 방향 배열을 설정해 놓은 다음, 도미노가 무너질 때 마다 최대 이동 거리를 갱신한다.
도미노는 최대 이동 거리까지(또는 격자를 벗어날 때 까지) 무너지게 된다.
그 과정에서 무너지는 도미노의 개수를 구하고, 다시 주어진 위치의 도미노를 세우는 것을 반복하여 답을 구해나가면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 류호석배 1회 2번
*/

int domino[128][128], fall[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, m, r, x, y, score = 0, e, xx, yy;
    char d;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &domino[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        scanf("%d %d %c", &x, &y, &d);
        if (d == 'E') d = 0;
        else if (d == 'S') d = 1;
        else if (d == 'W') d = 2;
        else if (d == 'N') d = 3;
        else return 1;
        e = 0;
        for (int j = 0; j <= e; j++) {
            xx = x + dxy[d][0] * j;
            yy = y + dxy[d][1] * j;
            if (xx < 1 || yy < 1 || xx > n || yy > m) break;
            if (!fall[xx][yy]) {
                fall[xx][yy] = 1;
                score++;
                if (domino[xx][yy] + j - 1 > e) e = domino[xx][yy] + j - 1;
            }
        }

        scanf("%d %d", &x, &y);
        fall[x][y] = 0;
    }

    printf("%d\n", score);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c ", fall[i][j] ? 'F' : 'S');
        }
        printf("\n");
    }
    return 0;
}