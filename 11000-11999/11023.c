#include <stdio.h>

/*
���� : ������ ������ŭ ������ ���� ����� ���Ѵ�.

�ذ� ��� : EOF�� �̿��Ѵ�.

�ֿ� �˰��� : ����?
*/

int main(void) {
    int sum = 0, x;
    while (scanf("%d", &x) != EOF) sum += x;
    printf("%d", sum);
    return 0;
}