#include <stdio.h>

/*
���� : N * N(N <= 10) ũ���� '.'�� '#'���� �̷���� ���ڿ��� '.'���� �̷���� ���� ū ���簢����
�� ���� ���̸� ���Ѵ�.

�ذ� ��� : N�� �۱� ������ ������ ��� ���簢���� ���� '.'���� �̷���� ���� ū ���簢���� ã��,
�� �� ���� ���̸� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : INC 2009 F��
*/

char land[16][16];

int main(void) {
    int t, n, r = 0, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", land[i]);
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; i + k < n && j + k < n; k++) {
                    cnt = 0;
                    for (int ii = i; ii <= i + k; ii++) {
                        for (int jj = j; jj <= j + k; jj++) {
                            if (land[ii][jj] == '#') cnt++;
                        }
                    }

                    if (cnt == 0) {
                        if (k + 1 > r) r = k + 1;
                    }
                }
            }
        }

        printf("%d\n", r);
    }
    return 0;
}