#include <stdio.h>

/*
���� : S * S(S <= 40) ũ���� �ǹ� ���� H(H <= 50)���� ���Ա��� �ִ�. ���Ա��� ��� �������� ������,
���Ա��� �ƴ� �������� ������ �Ŵ޾� ���� �� �ִ�. �� ������ ���󿡼� �������� �ʰ� ���� �� �ִ�
�� ��� ��� ���Ա��� ������ ���� ������ ���� X��ǥ -> Y��ǥ�� ���� ���� ���Ѵ�.
���ٸ� -1 -1�� ����Ѵ�.

�ذ� ��� : S�� ũ�Ⱑ �۱� ������ ���Ʈ ������ �ϸ� �ȴ�.
���� ���� �� �ִ� ��� ������ ���� ��� ���Ա��� ������ ���� �������� Ȯ���Ѵ�.
���� ���̴� ���� ����� �ǹ� ������ �׵θ������� �Ÿ��� ����,
�� �Ÿ��� ��Ÿ��� ������ �� ���Ա������� �Ÿ��� ���� ��� ��� ���� �Ÿ��� �� �������� ���Ǹ� �ȴ�.
�̶�, ���Ա��� ��ǥ�� ������ �� �ȴٴ� ���� �����Ѵ�.

�ֿ� �˰��� : ������, ���Ʈ ����

��ó : CPC 2007 C��
*/

int hole[64][2];

int small(int a, int b) {
    return a < b ? a : b;
}

int getlinelen(int s, int x, int y) {
    return small(small(x, y), small(s - x, s - y));
}

int getdist(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(void) {
    int t, s, h, x, y, l, tmp;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &s, &h);
        for (int i = 0; i < h; i++) {
            scanf("%d %d", &hole[i][0], &hole[i][1]);
        }
        x = -1, y = -1;
        for (int i = s - 1; i > 0; i--) {
            for (int j = s - 1; j > 0; j--) {
                l = getlinelen(s, i, j);
                tmp = 1;
                for (int k = 0; k < h; k++) {
                    if (getdist(hole[k][0], hole[k][1], i, j) > l * l) tmp = 0;
                    if (hole[k][0] == i && hole[k][1] == j) tmp = 0;
                }
                if (tmp) {
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d\n", x, y);
    }
    return 0;
}