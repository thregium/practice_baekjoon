#include <stdio.h>
#include <math.h>

/*
���� : K(K <= 10000)�ʵ����� �ٶ����Ͱ� �־��� ��, ���������� ���������� ���Ѽӵ� �̳��� �����ϸ� ����� ���� �� �ִ��� ���ϰ�,
�����ϴٸ� �� �ʸ����� �������� ����Ѵ�.

�ذ� ��� : K�ʵ����� ��� �ٶ����͸� ���� ���� ���������� ���ش�. �� ����, �������� ������ ������ �Ÿ��� ���Ѽӵ� * K ��������
Ȯ���Ѵ�. �Ѵ� ��쿡�� �Ұ����ϰ�, ���� �ʴ� ��쿡�� �� �������� �������� ��� �̵��ϸ� �ȴ�.
���������� ������ ������������ ���͸� K�� ���� ���� �� �ʸ��� �ٶ����Ϳ� �����ָ� �� �ʸ��� �׷��� �̵��� ���� ��ǥ�� �ȴ�.

�ֿ� �˰��� : ������

��ó : NWRRC 2014 J��
*/

int winddiff[10240][3], windtime[10240][2];

long long getdist(long long sx, long long sy, long long fx, long long fy) {
    return (fx - sx) * (fx - sx) + (fy - sy) * (fy - sy);
}

int main(void) {
    int sx, sy, fx, fy, fpx, fpy, n, k, vm;
    double x, y, movex, movey;
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
    fpx = fx, fpy = fy;
    scanf("%d %d %d", &n, &k, &vm);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &winddiff[i][0], &winddiff[i][1], &winddiff[i][2]);
        if (i > 0) {
            for (int j = winddiff[i - 1][0]; j < winddiff[i][0]; j++) {
                windtime[j][0] = winddiff[i - 1][1];
                windtime[j][1] = winddiff[i - 1][2];
                fpx -= windtime[j][0];
                fpy -= windtime[j][1];
            }
        }
    }
    for (int j = winddiff[n - 1][0]; j < k; j++) {
        windtime[j][0] = winddiff[n - 1][1];
        windtime[j][1] = winddiff[n - 1][2];
        fpx -= windtime[j][0];
        fpy -= windtime[j][1];
    }
    if (getdist(sx, sy, fpx, fpy) > (long long)vm * k * vm * k) {
        printf("No");
        return 0;
    }
    printf("Yes\n");
    movex = ((double)fpx - sx) / k;
    movey = ((double)fpy - sy) / k;
    x = sx, y = sy;
    for (int i = 0; i < k; i++) {
        x += movex + windtime[i][0];
        y += movey + windtime[i][1];
        printf("%.9f %.9f\n", x, y);
    }
    return 0;
}