#include <stdio.h>

/*
���� : �� ������ �� ������ ��ǥ�� �־��� �� �� ������ �����ϴ��� ���θ� ����Ѵ�. (��, �� ������ �ٸ� ���п��� �����ϴ� ���� ����.)

�ذ� ��� : �� ������ �� ������ �ٸ� ���п� ���� �ݴ��ʿ� �ְ�, �ٸ� ������ �� ������ �� ���п� ���� �ݴ��ʿ� �ִ� ��� �� ������ �����Ѵ�.
-|������ �������� �ʴ� ��찡 �ֱ⿡ �� ������ ��� ���� �Ѵ�.

�ֿ� �˰��� : ������, ������ ���� ����
*/

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
     long long int tri = x1 * y2 + x2 * y3 + x3 * y1 - (x2 * y1 + x3 * y2 + x1 * y3);
     if (tri > 0) return 1;
     else if (tri == 0) return 0;
     else return -1;
}

int main(void) {
     int x1, y1, x2, y2, x3, y3, x4, y4, tri;
     scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
     scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
     if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) < 0 && ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) < 0) printf("1");
     else printf("0");
     return 0;
}