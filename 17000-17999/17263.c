#include <stdio.h>

/*
���� : N(N <= 500000)���� 0 �̻� 10^9 ������ ������ ������������ �������� ��, �������� ���� ���� ���Ѵ�.

�ذ� ��� : N���� ���� ��� �ִ��� ���ϸ� �ȴ�.

�ֿ� �˰����� : ����

��ó : ���ϴ� 2019 A��
*/

int main(void) {
    int n, a, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a > r) r = a;
    }
    printf("%d", r);
    return 0;
}