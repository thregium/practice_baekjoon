#include <stdio.h>

/*
���� : N * N(N <= 10) ũ���� ��Ʈ���� ���μ��η� K(K <= 10)�辿 �ø� ����� ����Ѵ�.

�ذ� ��� : ���� �ݺ����� �̿��Ѵ�.

�ֿ� �˰��� : ����

��ó : �߾Ӵ� 2020 A��
*/

int btm[16][16];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &btm[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < k; ii++) {
            for (int j = 0; j < n; j++) {
                for (int jj = 0; jj < k; jj++) {
                    printf("%d ", btm[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}