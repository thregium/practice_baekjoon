#include <stdio.h>

/*
문제 : 8 * 8 크기의 판에서 주어진 말이 움직이는 방법을 모두 출력한다. 말은 직선으로 움직일 수 있다.
각 직선 방향으로 정확히 해당 직선상에 있는 말의 수 만큼의 칸을 이동해야 한다. 중간에 있는 자신의 말은 뛰어넘을 수 있지만
상대의 말은 뛰어넘을 수 없다. 반대로, 상대의 말이 목적지에 있는 경우 잡을 수 있지만, 자신의 말이 있는 곳으로는 갈 수 없다.
움직일 수 있는 방법이 없다면 "No moves are possible"을 출력한다.

해결 방법 : 각 칸마다 자신의 말이 있는 칸을 찾는다. 그 칸에서 8개 방향으로 각각 말을 옮겨본다.
먼저 옮길 거리를 확인하고, 그 거리만큼 이동했을 때 판 안에 있는지 확인한다. 판 밖으로 나간 경우 이동이 불가능하다.
판 안쪽이라면 중간에 상대의 말이 있거나 도착한 곳에 자신의 말이 있는지 확인한다. 둘 다 아니라면 해당 방법을 출력하면 된다.
이를 반복한 후 방법이 없는 경우 "No moves are possible"을 출력하고, 종료하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : MidC 1996 D번
*/

char board[16][16];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 8 || y >= 8) return 0;
    return 1;
}

int main(void) {
    int cnt, okay, res;
    char c, o;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM4\\BOARD.IN", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM4\\BOARD_T.OUT", "w", stdout);
    while (1) {
        for (int i = 0; i < 8; i++) {
            if (scanf("%s", board[i]) == EOF) return 0;
        }
        scanf(" %c", &c);
        if (c == 'O') o = 'X';
        else if (c == 'X') o = 'O';
        else return 1;

        res = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != c) continue;
                for (int k = 0; k < 8; k++) {
                    cnt = 0;
                    okay = 1;
                    for (int l = -8; l <= 8; l++) {
                        if (!isvalid(i + dxy[k][0] * l, j + dxy[k][1] * l)) continue;
                        if (board[i + dxy[k][0] * l][j + dxy[k][1] * l] != '.') cnt++;
                    }
                    if (!isvalid(i + dxy[k][0] * cnt, j + dxy[k][1] * cnt)) continue;
                    for (int l = 1; l <= cnt; l++) {
                        if (l < cnt && board[i + dxy[k][0] * l][j + dxy[k][1] * l] == o) {
                            okay = 0;
                            break;
                        }
                        if (l == cnt && board[i + dxy[k][0] * l][j + dxy[k][1] * l] == c) {
                            okay = 0;
                            break;
                        }
                    }
                    if (okay) {
                        printf("%c%d-%c%d\n", i + 'A', j + 1, i + dxy[k][0] * cnt + 'A', j + dxy[k][1] * cnt + 1);
                        res++;
                    }
                }
            }
        }
        if (res == 0) printf("No moves are possible\n");
        printf("\n");
    }
    return 0;
}