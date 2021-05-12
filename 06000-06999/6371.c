#include <stdio.h>
#include <ctype.h>

/*
문제 : 최대 100 * 100 크기의 논리회로의 모습이 주어진다. 각 알파벳(대문자)은 입력을 나타내고, or와 and 게이트가 있으며,
소문자 o는 not을 의미한다. 또한, 게이트를 제외하면 모든 선은 한 줄씩 끊김 없이 이어져 있다. 이때 각 입력이 주어지면 출력(물음표)을 구한다.

해결 방법 : 먼저, 논리회로가 주어지면 각 게이트들과 출력의 위치를 저장해 놓는다. 그 다음, 입력이 주어지면
각 입력에 대해 입력부터 게이트 또는 출력까지의 값을 선을 따라 저장해 놓는다. 이후로는 모든 게이트에 대해 두 입력이 모두 정의된 경우에 대해
출력을 알 수 있으므로 다음 게이트 또는 출력까지 반복하여 저장해 나가면 된다. 출력이 정의되면 비로소 그 값을 출력하고 다음 입력을 받는다.

주요 알고리즘 : 구현, 그래프 탐색

출처 : GNY 2001 E번 // MidC 1993 5번
*/

char logics[128][128], data[32];
int nums[128][128], vis[128][128], gates[256][2], result[2];
int gp = 0;
int dxy[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

void move(int x, int y, int n, int d) {
    //선을 따라 정보를 전달한다.
    if (logics[x][y] == 'o') n = !n;
    nums[x][y] = n;
    vis[x][y] = 1;
    if (logics[x][y] == ':' || logics[x][y] == '?') {
        return;
    }
    if (logics[x][y] == '+') {
        if (logics[x + dxy[0][0]][y + dxy[0][1]] == '|' && d != 2) d = 0;
        else if (logics[x + dxy[1][0]][y + dxy[1][1]] == '-' && d != 3) d = 1;
        else if (logics[x + dxy[2][0]][y + dxy[2][1]] == '|' && d != 0) d = 2;
        else if (logics[x + dxy[3][0]][y + dxy[3][1]] == '-' && d != 1) d = 3;
    }
    move(x + dxy[d][0], y + dxy[d][1], n, d);
}

int main(void) {
    int row, t, end = 0;
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2001\\e\\logic.in", "r", stdin);
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Mid Central\\1993\\logic.in", "r", stdin);
    while (1) {
        gp = 0;
        for (int i = 0;; i++) {
            if (fgets(logics[i], 120, stdin) == NULL) {
                //더이상 값을 받을 수 없다면 종료한다.
                end = 1;
                break;
            }
            for (int j = 0; logics[i][j]; j++) {
                if (logics[i][j] == '>' || logics[i][j] == ')') {
                    //게이트의 위치를 저장한다.
                    gates[gp][0] = i;
                    gates[gp][1] = j;
                    gp++;
                }
                if (logics[i][j] == '?') {
                    //출력의 위치를 저장한다.
                    result[0] = i;
                    result[1] = j;
                }
            }
            //printf("%s", logics[i]);
            if (logics[i][0] == '*') {
                row = i;
                break;
            }
        }
        if (end) break;
        while (1) {
            scanf("%s", data);
            //printf("%s\n", data);
            if (data[0] == '*') break;
            for (int i = 0; i < row; i++) {
                for (int j = 0; logics[i][j]; j++) {
                    if (isupper(logics[i][j])) {
                        //입력이 있는 위치에서 출발해 다음 게이트 또는 출력까지 정보를 전달한다.
                        if (logics[i + dxy[0][0]][j + dxy[0][1]] == '|') move(i, j, data[logics[i][j] - 'A'] - '0', 0);
                        else if (logics[i + dxy[1][0]][j + dxy[1][1]] == '-') move(i, j, data[logics[i][j] - 'A'] - '0', 1);
                        else if (logics[i + dxy[2][0]][j + dxy[2][1]] == '|') move(i, j, data[logics[i][j] - 'A'] - '0', 2);
                        else if (logics[i + dxy[3][0]][j + dxy[3][1]] == '-') move(i, j, data[logics[i][j] - 'A'] - '0', 3);
                    }
                }
            }
            t = 0;
            while (t < gp) {
                for (int i = 0; i < gp; i++) {
                    if (!vis[gates[i][0]][gates[i][1] + 1] && vis[gates[i][0] - 1][gates[i][1] - 2] && vis[gates[i][0] + 1][gates[i][1] - 2]) {
                        //아직 처리하지 않은 모든 입력이 정의된 게이트인 경우
                        if (logics[gates[i][0]][gates[i][1]] == '>') {
                            //OR
                            move(gates[i][0], gates[i][1] + 1, nums[gates[i][0] - 1][gates[i][1] - 2] || nums[gates[i][0] + 1][gates[i][1] - 2], 1);
                        }
                        else {
                            //AND
                            move(gates[i][0], gates[i][1] + 1, nums[gates[i][0] - 1][gates[i][1] - 2] && nums[gates[i][0] + 1][gates[i][1] - 2], 1);
                        }
                        t++;
                    }
                }
            }
            printf("%c\n", nums[result[0]][result[1]] + '0');
            for (int i = 0; i < row; i++) {
                for (int j = 0; logics[i][j]; j++) {
                    vis[i][j] = 0; //방문 배열을 초기화한다.
                    nums[i][j] = 0;
                }
            }
        }
        printf("\n");
        for (int i = 0; i < row; i++) {
            for (int j = 0; logics[i][j]; j++) {
                logics[i][j] = '\0'; //받았던 값들을 초기화한다.
            }
        }
    }
    return 0;
}