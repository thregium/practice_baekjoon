#include <stdio.h>

/*
���� : �־��� @�� �̷���� ���ڸ� N(N <= 100)���� ����� ����Ѵ�.

�ذ� ��� : ����, �Ʒ���, ����� ���� �и��Ͽ� ��, �Ʒ����� N * (N * 5) ũ���� ���簢����,
����� (N * 3) * N ũ���� ���簢���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n * 3; i++) {
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    return 0;
}