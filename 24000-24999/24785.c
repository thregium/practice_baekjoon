#include <stdio.h>

/*
문제 : 8 * 8 크기의 판에서 주어진 명령어대로 로봇을 움직일 때, 잘못된 입력을 하지 않고
다이아몬드에 갈 수 있는 지 여부를 구한다.

해결 방법 : 주어진 명령어들을 구현한다. 다음 칸의 위치를 미리 참조하는 함수를 만들면 좋다.
방향 이동은 방향 배열을 사용하는 것이 좋다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : VTH 2016 C번
*/

char board[16][16], prog[103000];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 8 || y >= 8) return 0;
    if (board[x][y] == 'C') return -1;
    if (board[x][y] == 'I') return -2;
    return 1;
}

int main(void) {
    int x = 7, y = 0, d = 0, bug = 0;
    for (int i = 0; i < 8; i++) {
        scanf("%s", board[i]);
    }
    board[7][0] = '.';
    scanf("%s", prog);
    for (int i = 0; prog[i]; i++) {
        if (prog[i] == 'F') {
            if (isvalid(x + dxy[d][0], y + dxy[d][1]) > 0) {
                x += dxy[d][0];
                y += dxy[d][1];
            }
            else {
                bug = 1;
                break;
            }
        }
        else if (prog[i] == 'L') d = ((d + 3) & 3);
        else if (prog[i] == 'R') d = ((d + 1) & 3);
        else if (prog[i] == 'X') {
            if (isvalid(x + dxy[d][0], y + dxy[d][1]) == -2) {
                board[x + dxy[d][0]][y + dxy[d][1]] = '.';
            }
            else {
                bug = 1;
                break;
            }
        }
        else return 1;
    }
    if (bug || board[x][y] != 'D') printf("Bug!");
    else printf("Diamond!");
    return 0;
}