#include <stdio.h>

/*
���� : 5 * 5 ũ���� ���ڿ� 0�� 1�� �ִ�. �̶�, 1�θ� �̷���� ���� ���̰� ���� ���簢���� ���̸� ���Ѵ�.

�ذ� ��� : ������ ũ�Ⱑ �����Ƿ� ������ ��� ������ ���캸�� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JDC 2001 A��
*/

int grid[8][8];

int main(void) {
    int m, t, b;
    scanf("%d", &m);
    for (int mm = 0; mm < m; mm++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        b = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = i; k < 5; k++) {
                    for (int l = j; l < 5; l++) {
                        t = 1;
                        for (int x = i; x <= k; x++) {
                            for (int y = j; y <= l; y++) {
                                if (!grid[x][y]) t = 0;
                            }
                        }
                        if (t == 1 && (k - i + 1) * (l - j + 1) > b) b = (k - i + 1) * (l - j + 1);
                    }
                }
            }
        }
        printf("%d\n", b);
    }
    return 0;
}