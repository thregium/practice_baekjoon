#include <stdio.h>

/*
���� : N * N(N <= 10) ũ���� �迭�� 1���� N * N������ ���� 1���� �����ִ�.
���� ���ʿ��� ������ �տ������� �����ϴ� ���鸸 �� ��, ���� ���� ������ �� �ٸ��� ���Ѵ�.

�ذ� ��� : ��������� �ִ񰪰� ������ Ȯ���ϸ鼭 ����س����� �ȴ�.

�ֿ� �˰��� : ����

��ó : INC 2020 A��
*/

int a[16][16];

int main(void) {
    int n, h, r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        r = 0, h = -1;
        for (int j = 0; j < n; j++) {
            if (a[j][i] > h) {
                r++;
                h = a[j][i];
            }
        }
        printf("%d ", r);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        r = 0, h = -1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] > h) {
                r++;
                h = a[i][j];
            }
        }
        printf("%d\n", r);
    }
    return 0;
}