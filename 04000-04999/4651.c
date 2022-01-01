#include <stdio.h>

/*
문제 : (X, Y)위치를 중심으로 하는 반지름 R의 반원과 N(N <= 150)개의 점들이 주어질 때, 반원 안에 있을 수 있는
점의 개수 가운데 최댓값을 구한다. 각 좌표는 정수이며 +- 1000 이하다.

해결 방법 : 우선 반원의 중심에서 R보다 멀리 떨어진 점들을 지운다. 그 다음, 각 점들에 대해 해당 점을 기준으로
나뉘는 두 반원 안에 있는 점의 개수를 센다. 이는 CCW로 가능하다. 각 반원들 중 안에 있는 점의 수가 가장 많은 것을 고르면 된다.

주요 알고리즘 : 브루트 포스, 기하학, CCW

출처 : MidC 2001 A번
*/

int point[256][2];

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int main(void) {
    int n, x, y, px, py, res, ppt, a, b, c;
    double r;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2001\\transmit\\transmit.in", "r", stdin);
    while (1) {
        scanf("%d %d %lf", &x, &y, &r);
        if (r < 0) break;
        scanf("%d", &n);
        ppt = 0, res = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &px, &py);
            if ((x - px) * (x - px) + (y - py) * (y - py) > r * r) continue;
            point[ppt][0] = px, point[ppt][1] = py;
            ppt++;
        }

        for (int i = 0; i < ppt; i++) {
            a = 0, b = 0, c = 0;
            for (int j = 0; j < ppt; j++) {
                if (ccw(point[i][0], point[i][1], x, y, point[j][0], point[j][1]) < 0) a++;
                else if (ccw(point[i][0], point[i][1], x, y, point[j][0], point[j][1]) == 0) b++;
                else c++;
            }
            if (a + b >= res) res = a + b;
            if (b + c >= res) res = b + c;
        }
        printf("%d\n", res);
    }
    return 0;
}