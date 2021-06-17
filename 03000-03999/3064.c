#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 지뢰찾기 판에서 테두리 부분에 인접한 지뢰의 수가 각각 주어진다.
이 때 지뢰찾기 판에 있을 수 있는 지뢰의 최대 개수를 구한다.

해결 방법 : 지뢰찾기판의 테두리와 인접하지 않은 곳은 전부 지뢰가 들어있을 수 있다.
테두리와 인접한 곳은 한 꼭지점부터 테두리를 돌아가며 찾으면 지뢰가 있는지 알 수 없는 칸이 최대 1개뿐이므로 모든 칸의 지뢰 여부를 알 수 있다.
따라서 위 두 정보를 합치면 지뢰의 최대 개수를 알 수 있다.

주요 알고리즘 : 그리디 알고리즘?
*/

char minefield[128][128];
int dxy[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

void find(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        if (minefield[x + dxy[i][0]][y + dxy[i][1]] == '*') cnt++;
    }
    if (cnt == minefield[x][y] - '0') {
        for (int i = 0; i < 8; i++) {
            if (minefield[x + dxy[i][0]][y + dxy[i][1]] == '#') minefield[x + dxy[i][0]][y + dxy[i][1]] = '.';
        }
    }
    else {
        for (int i = 0; i < 8; i++) {
            if (minefield[x + dxy[i][0]][y + dxy[i][1]] == '#') minefield[x + dxy[i][0]][y + dxy[i][1]] = '*';
        }
    }

}

int main(void) {
    int t, n, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", minefield[i] + 1);
        }
        for (int i = 1; i <= n; i++) {
            find(1, i);
        }
        for (int i = 2; i <= n; i++) {
            find(i, n);
        }
        for (int i = n - 1; i >= 1; i--) {
            find(n, i);
        }
        for (int i = n - 1; i > 1; i--) {
            find(i, 1);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (minefield[i][j] == '*' || minefield[i][j] == '#') cnt++;
                minefield[i][j] = '\0';
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}