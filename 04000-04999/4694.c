#include <stdio.h>

/*
문제 : 4 * 4 크기의 퍼즐에서 조각들이 주어질 때, 조각을 맞추는 방법을 출력한다. 각 조각들은 4 * 4 크기 이하이다.

해결 방법 : 백트래킹을 통해 각 조각들을 놓을 수 있는 모든 곳에 놓아본다. 놓는 방법이 없다면 탐색을 종료하고,
놓는 방법이 있다면 해당 위치에 조각을 놓고 다음 조각을 살펴본 다음 돌아와서 다음 방법을 찾는다.
모든 조각을 놓는데 성공했다면 빈 칸이 있는지 확인하고 빈 칸이 없다면 성공한 것이므로 탐색을 종료하고 해당 방법을 출력한다.

주요 알고리즘 : 구현, 백트래킹

출처 : MidC 1995 3번
*/

int sz[64][2], puzzle[4][4];
char piece[64][8][8];
int success = 0;

void track(int n, int p) {
    int t;
    if (p >= n) {
        t = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!puzzle[i][j]) t++;
            }
        }
        if (t) return;
        success = 1;
        return;
    }

    for (int i = 0; i <= 4 - sz[p][0]; i++) {
        for (int j = 0; j <= 4 - sz[p][1]; j++) {
            t = 0;
            for (int x = 0; x < sz[p][0]; x++) {
                for (int y = 0; y < sz[p][1]; y++) {
                    if (puzzle[i + x][j + y] && piece[p][x][y]) t = 1;
                }
            }
            if (t) continue;
            for (int x = 0; x < sz[p][0]; x++) {
                for (int y = 0; y < sz[p][1]; y++) {
                    if (piece[p][x][y]) puzzle[i + x][j + y] = p + 1;
                }
            }
            track(n, p + 1);
            if (success) return;
            for (int x = 0; x < sz[p][0]; x++) {
                for (int y = 0; y < sz[p][1]; y++) {
                    if (piece[p][x][y]) puzzle[i + x][j + y] = 0;
                }
            }
        }
    }
}

int main(void) {
    int n;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\puzzle.in", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        success = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &sz[i][0], &sz[i][1]);
            for (int j = 0; j < sz[i][0]; j++) {
                scanf("%s", piece[i][j]);
                for (int k = 0; k < sz[i][1]; k++) {
                    if (piece[i][j][k] == '1') piece[i][j][k] = 1;
                    else piece[i][j][k] = 0;
                }
            }
        }

        track(n, 0);
        if (!success) {
            printf("No solution possible\n\n");
            continue;
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d", puzzle[i][j]);
                puzzle[i][j] = 0;
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}