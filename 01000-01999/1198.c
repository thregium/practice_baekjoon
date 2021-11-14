#include <stdio.h>
#include <stdlib.h>

/*
���� : ���� N(N <= 35)������ �������� ��ǥ�� �־��� ��, �� �������� ������ 3���� ���� �ﰢ������ �߶󳻴� ����
�ݺ��� ������� �ﰢ�� ��� ���� ū ���� ���Ѵ�.

�ذ� ��� : ��� �� ���� �����ϴ��� �� �� ���� ���� ����� �ﰢ���� �߶� �� ������ �� �� �ִ�.
����, ��� �� ���� ����� ����� �� ���� �غ��� �ﰢ���� ���̸� ���ؼ� ���� ū ���� ã���� �ȴ�.

�ֿ� �˰��� : ������, ���Ʈ ����
*/

int point[64][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int ccw(int ax, int ay, int bx, int by, int cx, int cy) {
    return (ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax);
}

int main(void) {
    int n, r = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                r = big(r, abs(ccw(point[i][0], point[i][1], point[j][0], point[j][1], point[k][0], point[k][1])));
            }
        }
    }
    printf("%d.%d", r / 2, r % 2 * 5);
    return 0;
}
