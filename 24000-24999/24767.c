#include <stdio.h>
#include <math.h>

/*
���� : ��ǥ���� N(N <= 100)���� ���� �־��� ��, ���� ����� ������ �Ÿ��� D(D <= 1000) ������
���� ������ ���Ѵ�. �� ���� ��ǥ�� ���� 1000 ���ϴ�.

�ذ� ��� : N�� �����Ƿ� ��� �� �� ���� �Ÿ��� Ȯ���� �����鼭 �Ÿ��� D �̳��� ���� ��� üũ�ϰ�
�ϳ��� ���ԵǴ� ���� ������ ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : VTH 2014 C��
*/

double pos[128][2];
int sour[128];

double getdist(int a, int b) {
    return sqrt(pow(pos[a][0] - pos[b][0], 2) + pow(pos[a][1] - pos[b][1], 2));
}

int main(void) {
    int n, sw, su;
    double d;
    while (1) {
        scanf("%lf %d", &d, &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &pos[i][0], &pos[i][1]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (getdist(i, j) < d) {
                    sour[i] = 1;
                    sour[j] = 1;
                }
            }
        }
        sw = 0, su = 0;
        for (int i = 0; i < n; i++) {
            if (sour[i]) su++;
            else sw++;
            sour[i] = 0;
        }
        printf("%d sour, %d sweet\n", su, sw);
    }
    return 0;
}
