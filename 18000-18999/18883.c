#include <stdio.h>

/*
���� : N * M ũ��� ������ ����Ѵ�.

�ذ� ��� : 2�� for ���� ����ϸ� �ȴ�. ���鿡 �����Ѵ�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", i * m + j + 1);
            if (j < m - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}