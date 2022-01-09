#include <stdio.h>

/*
문제 : 8 * 8 크기의 격자에 'o'와 'x'가 적힌 상태의 판이 있다. 이 판에서 선공은 'o', 후공은 'x'를 자신의 말로 둔다.
각 플레이어는 말을 둘 때 새로 둔 말과 자신의 말 사이 상대의 말만 있다면 그 상대의 말들을 전부 뒤집을 수 있다.
이는 상하좌우대각선 8개 방향에서 성립한다. 선공은 매번 가장 많이 뒤집을 수 있는 곳 중 왼쪽 위를,
후공은 그 중 오른쪽 아래를 선택한다. 상대의 말을 뒤집을 수 없다면 자신의 턴을 넘겨야 한다.
이때, 양쪽 모두 새로운 말을 둘 수 없어진 상태의 판을 출력한다.

해결 방법 : 각 플레이어가 말을 놓을 수 있는 모든 위치에 대해 뒤집을 수 있는 상대의 말 개수를 확인한다.
각 방향으로 상대의 말만 나오다 자신의 말이 나오는 경우 사이의 상대 말 개수를 세면 된다.
이 값을 바탕으로 선공 또는 후공이 말을 놓을 위치를 구하고, 그곳에 말을 놓은 다음 다시 뒤집을 수 있는 말들을 뒤집는다.
최대 128턴까지(선공 또는 후공 가운데 하나가 절대 말을 둘 수 없는 경우) 가능하므로
128턴이 지난 후 판을 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JAG 2011S4 B번
*/

char board[16][16];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int main(void) {
    int best, bx, by, cnt, xx, yy;
    for (int i = 0; i < 8; i++) {
        scanf("%s", board[i]);
    }
    for (int i = 0; i < 159; i++) {
        best = 0, bx = -1, by = -1;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (board[x][y] != '.') continue;
                cnt = 0;
                for (int d = 0; d < 8; d++) {
                    for (int p = 1;; p++) {
                        xx = x + dxy[d][0] * p;
                        yy = y + dxy[d][1] * p;
                        if (xx < 0 || yy < 0 || xx >= 8 || yy >= 8) break;
                        if (board[xx][yy] == '.') break;
                        if (board[xx][yy] == ((i & 1) ? 'x' : 'o')) {
                            cnt += p - 1;
                            break;
                        }
                    }
                }
                if (cnt > best) {
                    bx = x;
                    by = y;
                    best = cnt;
                }
                else if (cnt == best && (i & 1)) {
                    bx = x;
                    by = y;
                }
            }
        }
        if (best == 0) continue;
        board[bx][by] = ((i & 1) ? 'x' : 'o');
        for (int d = 0; d < 8; d++) {
            for (int p = 1;; p++) {
                xx = bx + dxy[d][0] * p;
                yy = by + dxy[d][1] * p;
                if (xx < 0 || yy < 0 || xx >= 8 || yy >= 8) break;
                if (board[xx][yy] == '.') break;
                if (board[xx][yy] == ((i & 1) ? 'x' : 'o')) {
                    for (int pp = 1; pp < p; pp++) {
                        board[bx + dxy[d][0] * pp][by + dxy[d][1] * pp] = ((i & 1) ? 'x' : 'o');
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        printf("%s\n", board[i]);
    }
    return 0;
}