#include <stdio.h>

/*
���� : ���� N(N <= 50)�� �־��� ���ǿ� �´� ������ ���Ѵ�.
��� ���� ���� ������ ū 1000 ������ �ڿ������� �ϸ�, 2��° ���� 2���� �ϰ�, ������ ���� �Ҽ����� �Ѵ�.

�ذ� ��� : ������ �� �������� ���� 1���� ���ʷ� ����ϸ� �ȴ�. ������ ���� 50 �̻��� �ƹ� �Ҽ��� ����Ѵ�.

�ֿ� �˰����� : ����
*/

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 1; i < n; i++) {
        printf("%d ", i);
    }
    printf("397");
    return 0;
}