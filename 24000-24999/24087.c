#include <stdio.h>

/*
���� : ���� A(A <= 100)�� ���̽�ũ���� ��µ� 250���� ���, �� ���̽�ũ����
���� B(B <= 100)��ŭ�� �߰��ϴ� �� 100���� ���. �̶�, ���� S(S <= 100) �̻��� ���̽�ũ���� ��� ���ؼ���
�ּ� �� ���� ��� �� ���Ѵ�.

�ذ� ��� : S�� A���� �۴ٸ� ���̸� �߰����� �ʰ� ��� �ǹǷ� 250���� ���.
A �̻��̶�� ceil((S - A) / B)�� ���̸� �߰��ؾ� �ϰ�, �̸� ���� ������ ���� (S - A + B - 1) / B���� �ȴ�.
�� ���� �߰����� 100���� ���, ���̽�ũ���� ��� �� 250�� ��Ƿ� 250�� ���� �� * 100�� �� ����ŭ�� �ʿ��ϴ�.

�ֿ� �˰����� : ����

��ó : JOI 2022�� 3-2��
*/

int main(void) {
    int s, a, b;
    scanf("%d%d%d", &s, &a, &b);
    if (s < a) printf("250");
    else printf("%d", 250 + (s - a + b - 1) / b * 100);
    return 0;
}