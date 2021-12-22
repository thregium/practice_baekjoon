#include <stdio.h>

/*
���� : N���� ���� ���� �ֻ����� M(4 <= N, M <= 20)���� ���� ���� �ֻ����� ���ÿ� ���� ��, �� �ֻ��� ���� ������
���� ���ɼ��� ���� ���� ���� ������������ ���� ����Ѵ�. ��� ���� ���� Ȯ���� ����.

�ذ� ��� : N > M�̶�� �� ��, M + 1���� N + 1������ ���� ���� ���ɼ��� ũ��.

�ֿ� �˰����� : ����, ���շ�

��ó : SWERC 2015 D��
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n < m) swap(&n, &m);
    for (int i = m + 1; i <= n + 1; i++) {
        printf("%d\n", i);
    }
    return 0;
}