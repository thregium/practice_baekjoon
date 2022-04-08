#include <stdio.h>
#include <math.h>

/*
���� : ���� N(N <= 200000)������ �־��� ��, ù ��° ������ ���� �׾� ���̸� ��Ȯ�� �������� ������
������ �ݴ� ������ ���Ѵ�. ��� ���� ������ 10^7 ������ ���� ���̴�.

�ذ� ��� : �̺� Ž���� ���� �ݴ� ������ ���� ���� ã�� �� �� ���� ��ġ�� ���ϸ� �ȴ�.
���� ������ �̺� Ž������ ã�⿡�� ���е� ������ ����� ������ Ǯ�� ��ƴ�.

�ֿ� �˰��� : ������, ����

��ó : PacNW 2021 L/Y�� // SCUSA 2021D1 D / 2021D2 D�� // MidC 2021 D�� // NENA 2021 D��
*/

int pos[204800][2];
long double dsum[204800];
long double px = 0.0, py = 0.0;

long double getdist(long long x1, long long y1, long long x2, long long y2) {
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

long double getarea(int n, long double cir) {
    long double res = 0.0, llen;
    int foundpos = 0;
    px = pos[0][0], py = pos[0][1];
    for (int i = 1; i <= n; i++) {
        if (dsum[i] > cir || i == n) {
            llen = dsum[i] - dsum[i - 1];
            px = pos[i - 1][0] + (pos[i][0] - pos[i - 1][0]) * (cir - dsum[i - 1]) / llen;
            py = pos[i - 1][1] + (pos[i][1] - pos[i - 1][1]) * (cir - dsum[i - 1]) / llen;
            res += px * pos[i - 1][1];
            res -= pos[i - 1][0] * py;
            foundpos = 1;
            break;
        }
        res += (long double)pos[i][0] * pos[i - 1][1];
        res -= (long double)pos[i - 1][0] * pos[i][1];
    }
    res += pos[0][0] * py;
    res -= px * pos[0][1];
    res = fabsl(res) / 2.0;
    return res;
}

int main(void) {
    int n, lo, mid, hi;
    long double fullarea = 0.0, area1, area2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    pos[n][0] = pos[0][0], pos[n][1] = pos[0][1];
    for (int i = 1; i <= n; i++) {
        dsum[i] = dsum[i - 1] + getdist(pos[i][0], pos[i][1], pos[i - 1][0], pos[i - 1][1]);
        if (dsum[i] < dsum[i - 1] + 0.9) return 1;
    }
    fullarea = getarea(n, dsum[n - 1]);

    lo = 1, hi = n - 2;
    while(lo < hi) {
        mid = (lo + hi + 1) / 2;
        if (getarea(n, dsum[mid]) * 2.0 <= fullarea) lo = mid;
        else hi = mid - 1;
    }
    area1 = getarea(n, dsum[lo]);
    area2 = getarea(n, dsum[lo + 1]);
    px = pos[lo][0] + (pos[lo + 1][0] - pos[lo][0]) * (fullarea / 2.0 - area1) / (area2 - area1);
    py = pos[lo][1] + (pos[lo + 1][1] - pos[lo][1]) * (fullarea / 2.0 - area1) / (area2 - area1);
    printf("%.9f %.9f", (double)px, (double)py);
    return 0;
}