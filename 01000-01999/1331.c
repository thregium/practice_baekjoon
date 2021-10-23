#include <stdio.h>

/*
문제 : 6 * 6 크기의 체스판에서 체스판 내의 칸 36개의 순서가 주어질 때, 이 순서가 나이트 투어의 경로인지 확인한다.

해결 방법 : 각 칸들이 주어지면 각 칸의 좌표를 수로 변환하여 X좌표와 Y좌표로 바꾸고 배열에 저장한다.
그 다음 해당 칸을 방문하였는지 확인한다. 만약 방문한 칸을 한번이라도 다시 방문했다면 나이트 투어가 될 수 없다.
그 다음으로는 2번째 칸 이후부터 이전 칸에서 나이트의 이동으로 방문 가능한 칸인지 확인한다. 방문 가능한 칸이 아니라면
역시 나이트 투어가 아니다. 마지막으로 첫 칸과 마지막 칸이 나이트의 이동으로 방문 가능한 칸인지 확인하면
나이트 투어의 확인이 끝난 것이고, 전부 통과했다면 나이트 투어이다.

주요 알고리즘 : 구현, 시뮬레이션
*/

char buff[8];
int knight[64][2], chk[8][8];
int dxy[8][2] = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2} };

int main(void) {
    int r = 1, t;
    for (int i = 0; i < 36; i++) {
        scanf("%s", buff);
        knight[i][0] = buff[0] - 'A';
        knight[i][1] = buff[1] - '1';
        if (!chk[knight[i][0]][knight[i][1]]) chk[knight[i][0]][knight[i][1]] = 1;
        else r = 0;
        if (i > 0) {
            t = 0;
            for (int j = 0; j < 8; j++) {
                if (knight[i][0] - knight[i - 1][0] == dxy[j][0] && knight[i][1] - knight[i - 1][1] == dxy[j][1]) t = 1;
            }
            r &= t;
        }
    }
    t = 0;
    for (int i = 0; i < 8; i++) {
        if (knight[35][0] - knight[0][0] == dxy[i][0] && knight[35][1] - knight[0][1] == dxy[i][1]) t = 1;
    }
    r &= t;
    printf("%s", r ? "Valid" : "Invalid");
    return 0;
}