#include <stdio.h>

/*
���� : @�� �̷���� �ݽð�������� 90�� ���ư� �� ���¸� N(N <= 100)�� �� ����� ����Ѵ�.

�ذ� ��� : �� �ٸ��� ��츦 ������. ù ��° ���� 3ĭ @ �� 1ĭ ����, �ٽ� 1ĭ @�̴�. 2 ~ 4��° ���� @�� ������ ����� ���´�.
������ ���� @ 1ĭ �� 1ĭ ����, �ٽ� 3ĭ @�̴�. �̸� N * N���Ͽ� �ݺ��ϸ� ���ϴ� ����� ��� �����ϴ�.

�ֿ� �˰��� : ����
*/

void printshape(int n, char c) {
    for (int i = 0; i < n; i++) printf("%c", c);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printshape(n * 3, '@');
        printshape(n, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n * 3; i++) {
        printshape(n, '@');
        printshape(n, ' ');
        printshape(n, '@');
        printshape(n, ' ');
        printshape(n, '@');
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printshape(n, '@');
        printshape(n, ' ');
        printshape(n * 3, '@');
        printf("\n");
    }
    return 0;
}