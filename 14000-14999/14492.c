#include <stdio.h>

/*
���� : ������ �־��� ������ N * N(N <= 300) ũ���� �� �ο���Ŀ� ���� ��İ��� ���Ѵ�.

�ذ� ��� : ������ �־������ �����ϸ� �ȴ�. ��Ʈ ������ ����Ѵ�.

�ֿ� �˰��� : ����

��ó : ���� 2017 F��
*/

int mata[384][384], matb[384][384], matc[384][384];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mata[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matb[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                matc[i][j] |= (mata[i][k] & matb[k][j]);
            }
            r += matc[i][j];
        }
    }
    printf("%d", r);
    return 0;
}