#include <stdio.h>

/*
문제 : 4 * 4 크기의 격자에 물고기들이 있다. 각 턴마다 물고기들이 번호 순서대로 이동한 후 상어가 움직인다.
물고기들은 칸을 벗어나거나 상어가 있는 칸을 제외한 칸으로 움직이고, 앞쪽 칸이 움직일 수 없는 칸이라면 반시계방향으로 45도씩 돈다.
해당 칸에 물고기가 있는 경우 그 물고기와 자리를 바꾼다.
상어는 자신의 앞쪽 방향 가운데 물고기가 있는 어떤 칸이든 움직일 수 있다. 움직인 다음에는 해당 물고기의 방향으로 돈다.
처음에 상어는 가장 왼쪽 위에 있는 물고기를 먹는다고 할 때, 먹을 수 있는 물고기 번호의 합 가운데 가장 큰 것을 구한다.

해결 방법 : 코드 참조

주요 알고리즘 : 구현, 시뮬레이션, 백트래킹
*/

int num[4][4], dir[32];
int dxy[9][2] = { {0, 0}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} }; //각 방향의 x, y 좌표 변화량
int best = 1, sd; //best: 최고 기록, sd: 상어의 방향

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 4 || y >= 4) return 0; //칸을 벗어난 경우
    if (num[x][y] < 0) return 0; //상어가 있는 칸인 경우
    return 1;
}

void move(void) {
    int px = 0, py = 0, t;
    for (int i = 1; i <= 16; i++) {
        if (dir[i] < 0) continue;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (num[j][k] == i) {
                    px = j; //i번 물고기의 위치를 기록한다.
                    py = k;
                }
            }
        }
        while (!isvalid(px + dxy[dir[i]][0], py + dxy[dir[i]][1])) dir[i] = ((dir[i] & 7) + 1);
        t = num[px + dxy[dir[i]][0]][py + dxy[dir[i]][1]];
        num[px + dxy[dir[i]][0]][py + dxy[dir[i]][1]] = num[px][py];
        num[px][py] = t;
    }
}

void track(int sx, int sy, int cnt) {
    //백트래킹 함수
    int t, lsd = sd;
    int onum[4][4], odir[32]; //물고기를 움직인 직후의 배열 상태
    move(); //미리 물고기들을 움직여 둔다.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            onum[i][j] = num[i][j];
        }
    }
    for (int i = 1; i <= 16; i++) odir[i] = dir[i];
    for (int i = 1; isvalid(sx + dxy[sd][0] * i, sy + dxy[sd][1] * i); i++) {
        //상어가 보고 있는 방향의 모든 칸에 대해
        t = num[sx + dxy[sd][0] * i][sy + dxy[sd][1] * i];
        if (t == 0) continue; //빈 칸은 넘어간다.
        num[sx][sy] = 0;
        num[sx + dxy[sd][0] * i][sy + dxy[sd][1] * i] = -1; //상어를 해당 칸으로 옮긴 다음
        sd = dir[t];
        dir[t] = -1; //물고기를 먹고
        track(sx + dxy[lsd][0] * i, sy + dxy[lsd][1] * i, cnt + t); //계속 진행한다.
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                num[i][j] = onum[i][j];
            }
        }
        for (int i = 1; i <= 16; i++) dir[i] = odir[i];
        sd = lsd; //배열과 상어의 방향을 복원한다.
    }
    if (cnt > best) best = cnt;
}

int main(void) {
    int x, t;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d %d", &num[i][j], &x);
            dir[num[i][j]] = x;
        }
    }
    sd = dir[num[0][0]]; //왼쪽 위의 물고기를 기록한다.
    dir[num[0][0]] = sd;
    t = num[0][0];
    dir[num[0][0]] = -1; //해당 물고기를 삭제한다.
    num[0][0] = -1;
    track(0, 0, t);
    printf("%d", best);
    return 0;
}