#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ���� ������ �ִ�. �� ���� ��ġ�� ���� 10^6 ������ �������̰�,
�ڿ��� ����ġ p_i(<= 10^6)�� ������. ���ϴ� ������ �������� ��� �������� ����ư �Ÿ� / p_i��
�ִ��� �ּҷ� �� ���� �ش� ���� ���Ѵ�.

�ذ� ��� : ����ư �Ÿ��� �� 3���� �밢������ 4���� ���⿡ ���ؼ� ���������� ����ϰ�,
�� �� �ִ��� ���ϴ� ������ ���� ��� �������� �� �� �ִ�.
�� ���⿡ ���� ��� Ž���� ���� �ּ� �Ÿ��� ���� ���� �� �� �ִ��� ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, ��� Ž��

��ó : GCJ 2008_2 C2��
*/

int point[1024][4], od[1024][2];
double resd[4];
int dir[4][3] = { {1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1} };

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

double getdist(int n, double pos) {
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        if (fabs(pos - od[i][0]) / od[i][1] > res) res = fabs(pos - od[i][0]) / od[i][1];
    }
    return res;
}

int main(void) {
    int t, n;
    double lo, hi, midl, midh, res;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &point[i][j]);
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < n; j++) {
                od[j][0] = 0;
                od[j][1] = point[j][3];
                for (int k = 0; k < 3; k++) {
                    od[j][0] += point[j][k] * dir[i][k];
                }
            }
            qsort(od, n, sizeof(int) * 2, cmp1);

            lo = od[0][0], hi = od[n - 1][0];
            for (int k = 0; k < 123; k++) {
                midl = (lo * 2 + hi) / 3;
                midh = (lo + hi * 2) / 3;
                if (getdist(n, midl) < getdist(n, midh)) hi = midh;
                else lo = midl;
            }

            resd[i] = getdist(n, lo);
        }

        res = 0.0;
        for (int i = 0; i < 4; i++) {
            if (resd[i] > res) res = resd[i];
        }
        printf("Case #%d: %.9f\n", tt, res);
    }
    return 0;
}