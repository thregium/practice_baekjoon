#include <stdio.h>

/*
���� : 1�� p(n) - 1���� ���� p(n)���� ���� �������� ���Ѵ�. n�� 1000 ������ ���� �ƴ� �����̰�,
p(n)�� 2^2^2^...^2���� 2�� n�� �ִ� ������ ū ���� ���� �Ҽ��̴�.

�ذ� ��� : 1�� p(n) - 1���� ���� 9�� ���ϸ� 10^(p(n) - 1)�� �ȴ�. �׷���, p(n)�� �Ҽ��̹Ƿ�,
p(n)�� 2, 3, 5�� �ƴ� ��� �丣���� �������� ���� ���� 0�� �ȴ�. n�� 3 �̻��� ���
p(n)�� 5���� ũ�� ������ ���� 0�̴�. n�� 0, 1, 2�� ����� ���� ���� ���غ��� ���� 1, 2, 1���� �� �� �ִ�.

�ֿ� �˰����� : ����, ������, �丣���� ������

��ó : JAG 2013S3 D��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", n > 2 ? 0 : n == 1 ? 2 : 1);
    return 0;
}