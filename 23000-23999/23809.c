#include <stdio.h>

/*
���� : @�� �̷���� 'K'�ڸ� N(N <= 100)���� ���¸� ����Ѵ�.

�ذ� ��� : �� �ٺ��� �� ĭ�� �´� ���ڵ��� �ݺ����� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����
*/

void printshape(int n, char c) {
    for (int i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n * 3, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n * 2, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n * 3, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n * 2, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n * 3, ' ');
        printshape(n, '@');
        printf("\n");
    }
    return 0;
}