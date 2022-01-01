#include <stdio.h>

/*
���� : (X, Y)��ġ�� �߽����� �ϴ� ������ R�� �ݿ��� N(N <= 150)���� ������ �־��� ��, �ݿ� �ȿ� ���� �� �ִ�
���� ���� ��� �ִ��� ���Ѵ�. �� ��ǥ�� �����̸� +- 1000 ���ϴ�.

�ذ� ��� : �켱 �ݿ��� �߽ɿ��� R���� �ָ� ������ ������ �����. �� ����, �� ���鿡 ���� �ش� ���� ��������
������ �� �ݿ� �ȿ� �ִ� ���� ������ ����. �̴� CCW�� �����ϴ�. �� �ݿ��� �� �ȿ� �ִ� ���� ���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������, CCW

��ó : MidC 2001 A��
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