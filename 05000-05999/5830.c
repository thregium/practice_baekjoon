#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : 소의 N(N <= 1000)회의 움직임이 주어질 때, 모든 움직임을 마치기 위해서 필요한 직사각형 공간의 최소 크기를 구한다.
만약 움직임 도중 발이 겹친 경우 움직임을 마칠 수 없고, -1을 출력해야 한다.
각 이동마다 움직임은 특정한 발을 현재 바라보는 방향의 앞, 오른쪽, 뒤, 왼쪽 중 한 곳으로 이동시키거나
한 발을 중심으로 시계방향으로 몸을 90도 돌리는 것 중 하나다.

해결 방법 : 소의 움직임을 시뮬레이션한다. 매 움직임이 끝날 때 마다 최대 영역을 갱신하도록 하고,
발이 겹치는지 여부도 확인해야 한다.

주요 알고리즘 : 구현, 시뮬레이션, 기하학

출처 : USACO 2013O B1번
*/

char buff[8];
int foot[4][2] = { {1, 0}, {1, 1}, {0, 0}, {0, 1} }; //FL, FR, RL, RR
int dxy[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("ballet.in", "r");
        fo = fopen("ballet.out", "w");
    }

    int n, d = 0, m = 0, xl = 0, xh = 1, yl = 0, yh = 1, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        //발 확인
        if (buff[0] == 'F' && buff[1] == 'L') m = 0;
        else if (buff[0] == 'F' && buff[1] == 'R') m = 1;
        else if (buff[0] == 'R' && buff[1] == 'L') m = 2;
        else if (buff[0] == 'R' && buff[1] == 'R') m = 3;
        else return 1;

        //발의 움직임 추적
        if (buff[2] == 'F') {
            foot[m][0] += dxy[d][0];
            foot[m][1] += dxy[d][1];
        }
        else if (buff[2] == 'R') {
            foot[m][0] += dxy[(d + 1) & 3][0];
            foot[m][1] += dxy[(d + 1) & 3][1];
        }
        else if (buff[2] == 'B') {
            foot[m][0] += dxy[(d + 2) & 3][0];
            foot[m][1] += dxy[(d + 2) & 3][1];
        }
        else if (buff[2] == 'L') {
            foot[m][0] += dxy[(d + 3) & 3][0];
            foot[m][1] += dxy[(d + 3) & 3][1];
        }
        else if (buff[2] == 'P') {
            //회전시
            for (int j = 0; j < 4; j++) {
                t = foot[j][0];
                foot[j][0] = (foot[m][1] - foot[j][1]) + foot[m][0];
                foot[j][1] = (t - foot[m][0]) + foot[m][1];
            }
            d = ((d + 1) & 3); //방향 변경
        }
        else return 3;

        /*
        for (int j = 0; j < 4; j++) {
            printf("%d,%d ", foot[j][0], foot[j][1]);
        }
        printf("%c", '\n');
        */

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                if (foot[j][0] == foot[k][0] && foot[j][1] == foot[k][1]) {
                    //같은 칸에 발을 디딘 경우
                    printf("%d", -1);
                    return 0;
                }
            }
            if (foot[j][0] < xl) xl = foot[j][0];
            else if (foot[j][0] > xh) xh = foot[j][0];
            if (foot[j][1] < yl) yl = foot[j][1];
            else if (foot[j][1] > yh) yh = foot[j][1];
            //최댓값 갱신
        }
        
    }
    printf("%d", (xh - xl + 1) * (yh - yl + 1));
    return 0;
}