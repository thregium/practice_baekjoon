#include <stdio.h>

/*
���� : N * M(N, M <= 10) ũ���� �迭�� �¿�� ������ ����� ����Ѵ�.

�ذ� ��� : �迭�� �Է¹��� �� �� ������ �����´�.

�ֿ� �˰��� : ����

��ó : ����� 2016 D��
*/

char shape[16][16];

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", shape[i]);
        for (int j = 0, k = m - 1; j < k; j++, k--) {
            swap(&shape[i][j], &shape[i][k]);
        }
        printf("%s\n", shape[i]);
    }
    return 0;
}