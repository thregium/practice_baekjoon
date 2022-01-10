#include <stdio.h>
#include <math.h>

/*
���� : ��ǥ������ N(N <= 300)���� ���� ���� ������ 1�� ���� ������ �� �ִ� ���� ���� ���� ������ ���Ѵ�.
�� ������ (0, 0)���� (10, 10) ������ �Ǽ� ������ �־����� �Ǽ� ������ ���� ���� �޶����� �Է��� �־����� �ʴ´�.

�ذ� ��� : ���� 1�� �ƴ϶�� �Ÿ��� 2 ������ ��� �� ���� �ֿ� ���� �ش� �� ���� �׵θ��� �ִ� ���� �����ϸ�
�� ���� ��� ���� ������ �ȴ�. ����, �� ���� �ֿ� ���� ���� ������ �Ÿ��� 1�� �� ���� ã��,
�ٽ� ��� ���� ���� ã�� ������ �Ÿ��� 1 �������� Ȯ���Ѵ�. �׷��� ���� ���� �� ���� ū ������ ���� �ȴ�.
ã�� ���� 1���� ���� ����� ���� 1�̴�.

�ֿ� �˰��� : ������, ���Ʈ ����?

��ó : JDC 2004 D��
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