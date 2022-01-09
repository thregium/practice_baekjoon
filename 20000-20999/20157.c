#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� ��ǥ���� ���� ��, (0, 0)���� ���� �������� �ִ� �� ���� ���� ���� �� �ִ� �� ���Ѵ�.
��, ���� (0, 0)�� ������ (-10^6 <= X, Y <= 10^6)�� ���� ���� �����Ѵ�.

�ذ� ��� : ��� ������ ���� ���� ������ ����, �� ���� �����͸� ���������� ���� ������ �ִ� ���� ������ ����.
�� �� ���� ū ���� ���� �ȴ�.

�ֿ� �˰��� : ������, ����, �� ������

��ó : ���縯�� 2ȸ F��
*/

long long balloon[103000][2];

int cmp1(const void* a, const void* b) {
    long long ax = *(long long*)a;
    long long bx = *(long long*)b;
    long long ay = *((long long*)a + 1);
    long long by = *((long long*)b + 1);
    if ((ay < 0 || (ay == 0 && ax > 0)) && (by > 0 || (by == 0 && bx < 0))) return 1;
    else if ((ay > 0 || (ay == 0 && ax < 0)) && (by < 0 || (by == 0 && bx > 0))) return -1;
    else if (ay != 0 && by == 0) return 1;
    else if (ay == 0 && by != 0) return -1;
    else return (ax * by > bx * ay) ? 1 : (ax * by == bx * ay) ? 0 : -1;
}

long long ccw(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

long long cross(long long ax, long long ay, long long bx, long long by, long long cx, long long cy) {
    return ((bx - ax) * (cx - ax) + (by - ay) * (cy - ay));
}

int main(void) {
    int n, e = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &balloon[i][0], &balloon[i][1]);
    }
    qsort(balloon, n, sizeof(long long) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        while (e < n && ccw(0, 0, balloon[i][0], balloon[i][1], balloon[e][0], balloon[e][1]) == 0
            && cross(0, 0, balloon[i][0], balloon[i][1], balloon[e][0], balloon[e][1]) > 0) e++;
        if (e - i > r) r = e - i;
    }
    printf("%d", r);
    return 0;
}