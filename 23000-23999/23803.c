#include <stdio.h>

/*
���� : �־��� @�� �̷���� ���� ����� N(N <= 100)���� ����� ����Ѵ�.

�ذ� ��� : ���� �κ�(N * 4) * N ũ���� @ ���簢���� �Ʒ��� �κ� N * (N * 5) ũ���� @ ���簢���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * 4; i++) {
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    return 0;
}