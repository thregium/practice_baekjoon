#include <stdio.h>

/*
���� : ��Ģ������ �켱������ ���ٰ� ������ ��, ������ 2���� ���� �����ʺ��� ����� ����� ���ʺ��� ����� ��� ��
���� �ͺ��� ���ʴ�� ����Ѵ�.

�ذ� ��� : ��츦 ������ ���� �ΰ��� ��츦 ����� �� ���� ���� ����, ū ���� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : �泲�� 2ȸ A��
*/

int main(void) {
    int k1, k2, k3, a, b;
    char o1, o2;
    scanf("%d %c %d %c %d", &k1, &o1, &k2, &o2, &k3);
    if (o1 == '+') a = k1 + k2;
    else if (o1 == '-') a = k1 - k2;
    else if (o1 == '*') a = k1 * k2;
    else a = k1 / k2;
    if (o2 == '+') a = a + k3;
    else if (o2 == '-') a = a - k3;
    else if (o2 == '*') a = a * k3;
    else a = a / k3;

    if (o2 == '+') b = k2 + k3;
    else if (o2 == '-') b = k2 - k3;
    else if (o2 == '*') b = k2 * k3;
    else b = k2 / k3;
    if (o1 == '+') b = b + k1;
    else if (o1 == '-') b = k1 - b;
    else if (o1 == '*') b = b * k1;
    else b = k1 / b;

    if (a < b) printf("%d\n%d", a, b);
    else printf("%d\n%d", b, a);
    return 0;
}