#include <stdio.h>
#define FOUT 0
#define INF 0x7A35090F
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : N(N <= 50000)개의 점이 좌표평면상에 있다. 이 점들 가운데 1개를 제거하여 만들 수 있는 모든 점들을 포함하며
좌표축에 평행한 가장 작은 직사각형의 크기 가운데 가장 작은 것을 구한다.

해결 방법 : 각 점들을 포함하여 좌표축에 평행한 가장 작은 직사각형의 크기는 모든 점들 가운데
(가장 큰 X좌표) - (가장 작은 X좌표) * (가장 큰 Y좌표) - (가장 작은 Y좌표)이다. 그런데 한 개의 점을 제거하여 이 좌표가
될 수 있는 후보는 가장 큰/작은 값과 두 번째로 큰/작은 값 둘 뿐이다. 따라서, 이 값들을 전부 저장한 다음,
N개의 점 각각에 대해 가장 해당하는 점이 가장 큰 값 또는 가장 작은 값에 해당하는지 확인하고,
해당한다면 해당 값은 두 번째로 작은 값으로 바꾸며 해당하지 않는 값은 가장 큰 값으로 계산하여 직사각형의 크기를 구한다.
이 직사각형의 크기 가운데 최솟값을 구하면 답이 된다.

주요 알고리즘 : 기하학, 수학

출처 : USACO 2016O B3번
*/

int pos[51200][2];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("reduce.in", "r");
        fo = fopen("reduce.out", "w");
    }

    int n, xh1 = 0, xh2 = 0, xl1 = INF, xl2 = INF, yh1 = 0, yh2 = 0, yl1 = INF, yl2 = INF, r = INF, xh, xl, yh, yl;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        if (pos[i][0] > xh1) {
            xh2 = xh1;
            xh1 = pos[i][0];
        }
        else if (pos[i][0] > xh2) xh2 = pos[i][0];
        if (pos[i][0] < xl1) {
            xl2 = xl1;
            xl1 = pos[i][0];
        }
        else if (pos[i][0] < xl2) xl2 = pos[i][0];
        if (pos[i][1] > yh1) {
            yh2 = yh1;
            yh1 = pos[i][1];
        }
        else if (pos[i][1] > yh2) yh2 = pos[i][1];
        if (pos[i][1] < yl1) {
            yl2 = yl1;
            yl1 = pos[i][1];
        }
        else if (pos[i][1] < yl2) yl2 = pos[i][1];
    }
    for (int i = 0; i < n; i++) {
        if (pos[i][0] == xh1) xh = xh2;
        else xh = xh1;
        if (pos[i][0] == xl1) xl = xl2;
        else xl = xl1;
        if (pos[i][1] == yh1) yh = yh2;
        else yh = yh1;
        if (pos[i][1] == yl1) yl = yl2;
        else yl = yl1;

        if ((xh - xl) * (yh - yl) < r) r = (xh - xl) * (yh - yl);
    }
    printf("%d", r);
    return 0;
}