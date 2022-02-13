#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : H * W(H, W <= 25) ũ���� ���� ���� ���ο��� �� ��� �� ���� �������� �Ϸ��� �Ѵ�.
�� ���������� A_ij(<= 1000)���� ����� ���. �̶�, ��� ����� �������ο����� ����ư �Ÿ� ����
�ּҰ� �ǵ��� �������θ� ������ ��, �� ���� �ּڰ��� ���Ѵ�.

�ذ� ��� : H�� W�� �����Ƿ� �������θ� �����ϴ� ��� ��츦 �غ��� ����ư �Ÿ� ���� �ּڰ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JOI 2018�� 3��
*/

int a[32][32];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int h, w, c, r = INF;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            c = 0;
            for (int ii = 0; ii < h; ii++) {
                for (int jj = 0; jj < w; jj++) {
                    c += a[ii][jj] * small(abs(ii - i), abs(jj - j));
                }
            }
            if (c < r) r = c;
        }
    }
    printf("%d\n", r);
    return 0;
}