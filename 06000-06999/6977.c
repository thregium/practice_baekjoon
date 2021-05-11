#include <stdio.h>

/*
���� : N(N <= 30)�� ���̸� ���� ��Ʈ ���ڿ� ��� 1�� K(K <= 8, K <= N)�� �ִ� ���� ������������ ����Ѵ�.

�ذ� ��� : ��Ʈ��ŷ�� ���� ������ Ǭ��.

�ֿ� �˰��� : ��Ʈ��ŷ

��ó : CCC 1996 3��
*/

char pattern[32];

void track(int n, int k, int m, int l) {
    if (n == m) {
        for (int i = 0; i < n; i++) {
            printf("%c", pattern[i]);
        }
        printf("\n");
        return;
    }
    pattern[m] = '1';
    if (k > l) track(n, k, m + 1, l + 1);
    pattern[m] = '0';
    if (k < l + (n - m)) track(n, k, m + 1, l);
}

int main(void) {
    int t, n, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        printf("The bit patterns are\n");
        track(n, k, 0, 0);
        printf("\n");
    }
    return 0;
}