#include <stdio.h>

/*
���� : N * N(N <= 20) ũ���� ���簢���� �׵θ��� �� �밢���� "*"�� ǥ���� �׸��� ����Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. 1�� ���� ���ܿ� �����Ѵ�.

�ֿ� �˰��� : ����

��ó : �泲�� 5ȸ A��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("*");
        return 0;
    }
    for (int i = 0; i < n; i++) printf("*");
    printf("\n");
    for (int i = 0; i < n - 2; i++) {
        printf("*");
        for (int j = 0; j < n - 2; j++) {
            if (i == j || i + j == n - 3) printf("*");
            else printf(" ");
        }
        printf("*");
        printf("\n");
    }
    for (int i = 0; i < n; i++) printf("*");
    return 0;
}