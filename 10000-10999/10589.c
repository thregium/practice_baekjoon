#include <stdio.h>

/*
���� : N * M(N, M <= 50) ũ���� ü���ǿ��� ���簢���� ������ ������ �ּҷ� ����Ͽ� ��� ĭ�� ���� ������ �ϴ� ����� ���Ѵ�.

�ذ� ��� : ¦�� ��° ���, ¦�� ��° ���� �������� �ȴ�.

�ֿ� �˰��� : �ֵ� Ȥ, ������

��ó : NEERC 2014 A��
*/

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", (n >> 1) + (m >> 1));
    for (int i = 2; i <= n; i += 2) {
        printf("%d %d %d %d\n", i, 1, i, m);
    }
    for (int i = 2; i <= m; i += 2) {
        printf("%d %d %d %d\n", 1, i, n, i);
    }
    return 0;
}