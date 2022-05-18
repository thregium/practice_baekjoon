#include <stdio.h>

/*
���� : �� �޷��� �ִ�. �� �޷��� �� �� ���� ������, �� ���� ���� N, M(N, M <= 10^6)�̴�.
����, �� ���� �� ���� �ִ� 1000���̴�.
�̶�, Z(Z <= 100000)���� ������ �����Ѵ�. �� ������ ���� ��, 'A' �Ǵ� 'B'�� �־��� ��,
�ش� �޷��� ���� �ٸ� �޷����� �ٲٴ� ���̴�.

�ذ� ��� : �� �޷��� �޸��� ��¥�� ������ ���� ����Ѵ�. �� ���� ������ �־��� �� ����,
�� ���� �������� �ش� ������ �� ���� ����� ����, �ݴ��� �迭���� �̺� Ž���� ����
�ݴ��� �޷��� ���� ������ ��ȯ�ϸ� �ȴ�.

�ֿ� �˰��� : ���� ��, �̺� Ž��

��ó : JPOI 2009 2-2��
*/

int a[1048576], b[1048576];

int main(void) {
    int n, m, z, di, mi, dt, lo, hi, mid;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        b[i] += b[i - 1];
    }

    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        scanf("%d %d %c", &di, &mi, &c);
        if (c == 'A') {
            dt = a[mi - 1] + di;
            lo = 0, hi = m - 1;
            while (lo < hi) {
                mid = (lo + hi + 1) >> 1;
                if (b[mid] < dt) lo = mid;
                else hi = mid - 1;
            }
            printf("%d %d\n", dt - b[lo], lo + 1);
        }
        else {
            dt = b[mi - 1] + di;
            lo = 0, hi = n - 1;
            while (lo < hi) {
                mid = (lo + hi + 1) >> 1;
                if (a[mid] < dt) lo = mid;
                else hi = mid - 1;
            }
            printf("%d %d\n", dt - a[lo], lo + 1);
        }
    }
    return 0;
}