#include <stdio.h>

/*
���� : �ֻ��� 2���� ���� ���� N�� �Ǵ� ���� ���� ���Ѵ�. ������ �ٸ� ���� ���� ������ ����.

�ذ� ��� : i <= j�� 1 ~ 6 ���� ���� ���� Ȯ���� ���� N�� �Ǵ� ���� ��� ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ����

��ó : UVa 2013 C��
*/

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        printf("Case %d:\n", tt);
        for (int i = 1; i <= 6; i++) {
            for (int j = i; j <= 6; j++) {
                if (i + j == n) {
                    printf("(%d,%d)\n", i, j);
                }
            }
        }
    }
    return 0;
}