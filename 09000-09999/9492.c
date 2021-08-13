#include <stdio.h>

/*
���� : N(N <= 1000)���� ī�带 ���� ����� ����Ѵ�. ī�带 �� ����� ������ ���� ����� Ȧ����°,
���� ����� ¦����°�� ���� ������ �ȴ�.

�ذ� ��� : �־������ �����Ѵ�.

�ֿ� �˰��� : ����

��ó : SEUSA 2013D2 H��
*/

char cards[1024][128];

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < (n + 1) >> 1; i++) {
            scanf("%s", cards[i << 1]);
        }
        for (int i = 0; i < n >> 1; i++) {
            scanf("%s", cards[(i << 1) + 1]);
        }
        for (int i = 0; i < n; i++) {
            printf("%s\n", cards[i]);
        }
    }
    return 0;
}