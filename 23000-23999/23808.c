#include <stdio.h>

/*
���� : @�� �̷���� '��'�ڸ� N(N <= 100)���� ���¸� ����Ѵ�.

�ذ� ��� : �� �κ��� ������ ����ϸ� �ȴ�. ���μ� ��� �κ��� @   @�� N * N���� �����̰�,
���μ� ��� �κ��� @�� N * (N * 5)�� �� �����̴�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < n; j++) printf("@");
        for (int j = 0; j < n * 3; j++) printf(" ");
        for (int j = 0; j < n; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n * 5; j++) printf("@");
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
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