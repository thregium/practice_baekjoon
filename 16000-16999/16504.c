#include <stdio.h>

/*
���� : N * N ũ���� �����̸� ���� ���� �� ���� ���� �� ���� ���� ���� ���� �ݺ��� ���� �ϳ��� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �ణ �����غ��� ��� ĭ�� �ѹ����� ������ ������ �ϳ��� ���� ���� ���� ��� ���� �հ� ������ �� �� �ִ�.

�ֿ� �˰����� : ����?

��ó : �泲�� 2ȸ B��
*/

int main(void) {
    int n, x;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &x);
        r += x;
    }
    printf("%lld", r);
    return 0;
}