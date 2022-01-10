#include <stdio.h>
#include <math.h>

/*
문제 : 좌표평면상의 N(N <= 300)개의 점에 대해 반지름 1인 원이 포함할 수 있는 가장 많은 점의 개수를 구한다.
각 점들은 (0, 0)에서 (10, 10) 사이의 실수 범위에 주어지며 실수 오차에 의해 답이 달라지는 입력은 주어지지 않는다.

해결 방법 : 답이 1이 아니라면 거리가 2 이하인 모든 두 점의 쌍에 대해 해당 두 점이 테두리에 있는 원을 조사하면
그 값들 가운데 답이 나오게 된다. 따라서, 두 점의 쌍에 대해 양쪽 점에서 거리가 1인 두 점을 찾고,
다시 모든 점에 대해 찾은 점에서 거리가 1 이하인지 확인한다. 그러한 점의 개수 중 가장 큰 것이이 답이 된다.
찾은 점이 1개도 없는 경우의 답은 1이다.

주요 알고리즘 : 기하학, 브루트 포스?

출처 : JDC 2004 D번
*/

double point[384][2];

double getdist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main(void) {
    int n, best, cnt;
    double t, d, dx, dy, cx, cy;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2004\\INPUT\\D4.txt", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2004\\OUTPUT\\D4_t.txt", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &point[i][0], &point[i][1]);
        }
        best = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (getdist(point[i][0], point[i][1], point[j][0], point[j][1]) > 2) continue;
                if (point[i][0] == point[j][0]) t = 103000.0 * 103000.0;
                else t = (point[i][1] - point[j][1]) / (point[i][0] - point[j][0]);
                if (t == 0) t = 103000.0 * 103000.0;
                else t = -1 / t;
                d = sqrt(1 - pow(getdist(point[i][0], point[i][1], point[j][0], point[j][1]) / 2, 2));

                dx = sqrt(d * d / (1 + t * t));
                dy = dx * t;
                cx = (point[i][0] + point[j][0]) / 2 + dx;
                cy = (point[i][1] + point[j][1]) / 2 + dy;
                cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (getdist(cx, cy, point[k][0], point[k][1]) <= 1.000001) cnt++;
                }
                if (cnt > best) best = cnt;
                cx = (point[i][0] + point[j][0]) / 2 - dx;
                cy = (point[i][1] + point[j][1]) / 2 - dy;
                cnt = 0;
                for (int k = 0; k < n; k++) {
                    if (getdist(cx, cy, point[k][0], point[k][1]) <= 1.000001) cnt++;
                }
                if (cnt > best) best = cnt;
            }
        }
        printf("%d\n", best);
    }
    return 0;
}