#include <stdio.h>

/*
���� : ���� N * N ũ���� �ﰢ�� ���·� ����Ѵ�.

�ذ� ��� : ����Ѵ�.

�ֿ� �˰��� : ����

��ó : NZPC 2008 A��
*/

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) printf("*");
            printf("\n");
        }
    }
    return 0;
}