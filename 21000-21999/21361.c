#include <stdio.h>

/*
문제 : R * C(R, C <= 2000) 크기의 방에서 로봇 청소기의 이동 명령이 주어질 때,
로봇 청소기가 이동한 적 있는 칸의 개수를 구한다. 이동 명령은 2000자 이하의 '^', 'v', '<', '>'로 이루어진
문자열로 주어지며, 왼쪽부터 순서대로 해당 방향으로 벽('#')에 닿을 때 까지 이동한다.

해결 방법 : 로봇 청소기의 위치를 찾은 다음 각 방향으로 벽에 닿을 때 까지 반복해 나가며
로봇 청소기를 이동시켜 나간다. 로봇 청소기가 이동한 적 있는 칸들을 전부 기록한 다음,
그 칸들의 개수를 세서 답을 구하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : SwOI 2021O B번
*/

char room[2048][2048], inst[2048];

int main(void) {
    int r, c, n, x = -1, y = -1, res = 0;
    scanf("%d %d %d", &r, &c, &n);
    scanf("%s", inst);
    for (int i = 0; i < r; i++) {
        scanf("%s", room[i]);
        for (int j = 0; j < c; j++) {
            if (room[i][j] == 'O') {
                room[i][j] = '*';
                x = i, y = j;
            }
        }
    }
    if (x < 0) return 1;
    for (int i = 0; i < n; i++) {
        if (inst[i] == '^') {
            while (room[x - 1][y] != '#') room[--x][y] = '*';
        }
        else if (inst[i] == 'v') {
            while (room[x + 1][y] != '#') room[++x][y] = '*';
        }
        else if (inst[i] == '<') {
            while (room[x][y - 1] != '#') room[x][--y] = '*';
        }
        else if (inst[i] == '>') {
            while (room[x][y + 1] != '#') room[x][++y] = '*';
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res += (room[i][j] == '*');
        }
    }
    printf("%d", res);
    return 0;
}