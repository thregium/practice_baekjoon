#include <stdio.h>

/*
���� : N�� M�� �־��� ��, N * M ũ���� ü���� ����� ����Ѵ�.

�ذ� ��� : �������� �����Ѵ�� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : AIPO 2016F 1��
*/

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) printf("%c", ((i + j) & 1) ? '.' : '*'); //�� + �� ��ȣ�� ¦���� ��� *, Ȧ���� ��� .
        printf("\n");
    }
    return 0;
}