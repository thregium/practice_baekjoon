#include <stdio.h>

/*
���� : N�� Ȧ���� ������ N ũ���� �־��� ���·� ���� ����ϰ�, ¦���� I LOVE CBNU�� ����Ѵ�.

�ذ� ��� : N�� ¦������ ���� Ȯ���ϰ� Ȧ���� ��� ���� N�� ����� ����, (N + 1) / 2�� ����
��Ī������ ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���ϴ� 2017 A��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if (n & 1) {
        for (int i = 0; i < n; i++) printf("*");
        printf("\n");
        for (int i = (n >> 1); i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == i || j == (n - i - 1)) printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
    else printf("I LOVE CBNU");
    return 0;
}