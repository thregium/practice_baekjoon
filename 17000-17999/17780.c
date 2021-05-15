#include <stdio.h>
#include <string.h>

/*
문제 : N * N(N <= 12) 크기의 체스판에 말들이 K(K <= 10)개 놓여있다. 이 말들을 1번부터 차례로 움직여서 K번 말까지 움직이면 한 턴이 끝난다.
맨 밑의 말들만 움직일 수 있고, 말을 움직일 때에는 움직이는 말과 함께 위에 있는 모든 말들이 움직인다. 움직인 다음에는 그 칸에 있던 말들의 위에 움직인 말들을 놓는다.
움직이려고 하는 칸이 빨간 색이라면 움직인 후에 움직였던 말들의 순서를 반전시킨다. 파란 색이라면 그 방향이 아닌 반대 방향으로 움직인다.
그 방향이 빨간 색이라면 역시 순서를 반전시키고 파란 색이라면 그 지점에서 방향만 바꾼 채 멈춰 있는다.
말이 한 칸에 4개 이상 쌓이는 경우 게임이 끝난다고 하면 게임이 끝나는 턴을 구한다. 단, 턴이 1000번 지날 동안 끝나지 않는다면 끝나지 않는 것으로 간주한다.

해결 방법 : 칸 위에 있는 각 말들의 종류와 방향들을 문자열로 생각하고 체스판 전체를 돌며 현재 말이 있는 위치를 strchr을 통해 찾는다.
만약 맨 밑의 말이 아닌 경우 다음 말로 넘어간다.
찾은 다음에는 해당 말의 방향을 찾은 다음 해당 위치의 말들을 strcat을 통해 다음 위치의 문자열에 붙인다. 그와 함께 원래 위치의 말들은 지운다.
만약 빨간색 칸이 나오는 경우 그 말들과 위의 말들을 반전시키는 것도 구현한다. 문자열을 붙이는 과정에서 길이가 말 4개 이상의 길이가 되면 게임을 끝낸다.

주요 알고리즘 : 구현, 시뮬레이션, 문자열
*/

int chess[16][16];
int dxy[5][2] = { {0, 0},  {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
char pos[16][16][32];
int n;

int cell(int x, int y) {
    //해당 위치의 색을 가져온다. 범위에 없는 경우는 파란 색으로 간주한다.
    if (x < 1 || y < 1 || x > n || y > n) return 2;
    else return chess[x][y];
}

int opposite(int d) {
    //반대 방향의 번호를 반환한다.
    if (d & 1) return d + 1;
    else return d - 1;
}

void swap(char* a, char* b) {
    //두 문자를 바꾼다.
    char t = *a;
    *a = *b;
    *b = t;
}

void rev(int p, int x, int y) {
    int sz = strlen(pos[x][y]);
    for (int i = p, j = sz - 2; i < j; i += 2, j -= 2) {
        //해당 위치 위의 말들의 순서를 바꾼다.
        swap(&pos[x][y][i], &pos[x][y][j]);
        swap(&pos[x][y][i + 1], &pos[x][y][j + 1]);
    }
}

int main(void) {
    int k, x, y, d = 0, p, nxc;
    char tmp[32] = { 0, };
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &chess[i][j]);
        }
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &x, &y, &d);
        pos[x][y][0] = i + 'A';
        pos[x][y][1] = d + '0';
        //저장 형식 : 알파벳(번호 + 'A')숫자(방향)
    }
    for (int turn = 1; turn <= 1000; turn++) {
        for (int i = 0; i < k; i++) {
            //말의 번호
            for (x = 1; x <= n; x++) {
                for (y = 1; y <= n; y++) {
                    if (strchr(pos[x][y], i + 'A')) break; //해당 말을 찾은 경우
                }
                if (strchr(pos[x][y], i + 'A')) break;
            }
            for (p = 0; pos[x][y][p]; p++) {
                if (pos[x][y][p] == i + 'A') {
                    d = pos[x][y][p + 1] - '0'; //말의 방향과 위치를 얻는다.
                    break;
                }
            }
            if (p) continue; //맨 밑의 말이 아닌 경우
            nxc = cell(x + dxy[d][0], y + dxy[d][1]);
            if (nxc == 2) {
                //파란 칸인 경우
                d = opposite(d);
                pos[x][y][p + 1] = d + '0'; //방향을 바꾸고 업데이트한다.
                if (cell(x + dxy[d][0], y + dxy[d][1]) == 2) continue; //다시 파란 칸이라면 이동을 취소한다.
                else if (cell(x + dxy[d][0], y + dxy[d][1]) == 1) {
                    rev(p, x, y); //움직일 칸이 빨간 칸이라면 순서를 반전시킨다.
                }
                strcpy(tmp, &pos[x][y][p]);
                pos[x][y][p] = '\0';
                x += dxy[d][0];
                y += dxy[d][1];
                strcat(pos[x][y], tmp); //이동한다.
                //if (strlen(pos[x][y]) & 1) return 1;
                if ((strlen(pos[x][y]) >> 1) >= 4) {
                    //쌓인 말들이 4개 이상인 경우
                    printf("%d\n", turn);
                    return 0;
                }
            }
            else {
                if (nxc == 1) rev(p, x, y); //이동할 칸이 빨간색이라면 순서를 반전시킨다.
                strcpy(tmp, &pos[x][y][p]);
                pos[x][y][p] = '\0';
                x += dxy[d][0];
                y += dxy[d][1];
                strcat(pos[x][y], tmp); //이동한다.
                //if (strlen(pos[x][y]) & 1) return 1;
                if ((strlen(pos[x][y]) >> 1) >= 4) {
                    //쌓인 말들이 4개 이상인 경우
                    printf("%d\n", turn);
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}