#include <stdio.h>

/*
���� : N(N <= 100) ũ���� ���� �� X���·� ���� ����Ѵ�.

�ذ� ��� : ���� �ش� ���·� ����ϸ� �ȴ�. ���鿡 �����Ѵ�.

�ֿ� �˰��� : ����
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) printf("*");
    for (int i = 3; i < n * 2; i++) printf(" ");
    for (int i = 0; i < n; i++) printf("*");
    printf("\n");
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j < i; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        for (int j = 2 * i + 3; j < n * 2; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        printf("\n");
    }
    for (int i = 1; i < n; i++) printf(" ");
    printf("*");
    for (int i = 2; i < n; i++) printf(" ");
    printf("*");
    for (int i = 2; i < n; i++) printf(" ");
    printf("*\n");
    for (int i = n - 2; i > 0; i--) {
        for (int j = 0; j < i; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        for (int j = 2 * i + 3; j < n * 2; j++) printf(" ");
        printf("*");
        for (int j = 2; j < n; j++) printf(" ");
        printf("*");
        printf("\n");
    }
    for (int i = 0; i < n; i++) printf("*");
    for (int i = 3; i < n * 2; i++) printf(" ");
    for (int i = 0; i < n; i++) printf("*");
    return 0;
}