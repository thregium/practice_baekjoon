#include <stdio.h>

/*
���� : N * N(N <= 1000) ũ���� �����ǿ��� ���� �Ʒ����� ������׷� �簢���� Ŀ���� �������� �����δٸ�
������ �� ĭ�� �� ��°�� �����ϴ��� ���Ѵ�.

�ذ� ��� : ���� ���簢���� ������ ������ ���� ���簢���� ���� �� �Ǵ� ������ �Ʒ��� ���µ� N - 1���� ���,
�װ����� ���� ���簢���� ������ ���� ���µ� N - 1���� ���. ����, ���� ������ (N - 1) * 2�� ���� ����
���� ���� �ȴ�. ù ���� 1�� ������ �ȴ�.

�ֿ� �˰����� : ����

��ó : Arab 2006 D��
*/

int a[1024];

int main(void) {
    int n;
    a[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        a[i] = a[i - 1] + (i - 1) * 2;
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d => %d\n", n, a[n]);
    }
    return 0;
}