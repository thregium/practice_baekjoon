#include <stdio.h>

/*
���� : �־��� @�� �̷���� ���ڸ� N(N <= 100)���� ����� ����Ѵ�.

�ذ� ��� : ��, ���, �Ʒ��� ���� ������ ����Ѵ�. ��� �κ��� �߾� 3 * Nĭ�� ����, �������� @�� ä���,
������ �κ��� ���� @�� N * 5ĭ�� ä��� �ȴ�.

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
        for (int j = 0; j < n * 3; j++) printf(" ");
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    return 0;
}