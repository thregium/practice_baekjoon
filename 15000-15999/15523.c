#include <stdio.h>

/*
문제 : H * W(H, W는 4의 배수 - 1, H, W <= 39) 크기의 격자의 홀수 점에 '@'와 '*'이 있고,
나머지 점들은 '.'으로 되어 있다. 이때, @에서 출발하여 모든 *를 거치는 경로를 출력한다.
단, 경로는 외길이어야 한다.(상하좌우로 인접한 다른 도로가 있어서는 안 된다.)

해결 방법 : 제한을 잘 이용하면 모든 크기의 격자에서 모든 홀수 점을 거쳐 돌아오는
'ㅌ'자 모양의 순환 경로를 만들 수 있다. 이를 만든 다음, @에서 인접한 *까지 지나는 경로를 지워주면
구하고자 하는 답이 된다.

주요 알고리즘 : 구현, 구성적, 그래프 탐색

출처 : JAG 2017P F번
*/

char s[64][64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (s[x][y] == '.') return 0;
    return 1;
}

void dfs(int x, int y, int l) {
    if (s[x][y] == '*') return;
    for (int i = 0; i < 4; i++) {
        if (i == l) continue;
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
            dfs(x + dxy[i][0], y + dxy[i][1], i ^ 2);
            break;
        }
    }
    if (s[x][y] == '#') s[x][y] = '.';
}

int main(void) {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", s[i]);
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                if (((~i & 1) && (~j & 1)) || j == 0 || ((i & 2) && j == 2) || ((~i & 2) && j == w - 1)
                    || (j > 2 && (~i & 1)) || ((i == 0 || i == h - 1) && j == 1)) {
                    s[i][j] = '#';
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '@') {
                for (int d = 0; d < 4; d++) {
                    if (isvalid(i + dxy[d][0], j + dxy[d][1])) {
                        dfs(i, j, d);
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}
