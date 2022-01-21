#include <stdio.h>
#include <math.h>

/*
���� : N(N <= 20)���� ���� ��� M���� �̾� �� ���� �� ���� ���� �Ÿ� ���� ���� ū ���� ã������ �Ѵ�.
�׶��� ���� �Ÿ� ���� ���Ѵ�. �� ���� ���� ���� �Ÿ��� ������ ��Һ� ������ ������ �հ� ����.

�ذ� ��� : N�� �۱� ������ ���Ʈ ������ ���� ��� ������ �̴� ��쿡 ���� �õ��غ���.
�� ��츶�� ��� ���� �ֿ� ���� ���� �Ÿ��� ���ϰ� �� �� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JAG 2011S3 A��
*/

int picked[32];
double color[32][3];
double r = 0.0;

double getdist(double* x, double* y) {
    return pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2) + pow(x[2] - y[2], 2);
}

void track(int n, int m, int k, int l) {
    if (m == k) {
        double d = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                d += getdist(color[picked[i]], color[picked[j]]);
            }
        }
        if (d > r) r = d;
        return;
    }

    for (int i = l + 1; i < n; i++) {
        picked[k] = i;
        track(n, m, k + 1, i);
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &color[i][0], &color[i][1], &color[i][2]);
    }
    track(n, m, 0, -1);
    printf("%f", r);
    return 0;
}