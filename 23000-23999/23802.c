#include <stdio.h>

/*
���� : �ڿ��� N(N <= 100)�� �־��� ��, ���� ũ���� N��� ������ ���ڷ� @�� ����Ѵ�.

�ذ� ��� : ���� ���� N * (N * 5) ũ��� @�� ����ϰ� �� �Ʒ��� (N * 4) * N ũ��� @�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n * 4; i++) {
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    return 0;
}