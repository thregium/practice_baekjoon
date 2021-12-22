#include <stdio.h>
#include <stdlib.h>

/*
���� : (0, 0)���� (A, B)(-10^9 <= A, B <= 10^9)�� C(C <= 2 * 10^9)�� �����¿� �̵��� ���� ���� �������� ���Ѵ�.

�ذ� ��� : ���� C�� (A, B)�� ���� �ִܰŸ�����(|A| + |B|) ���ٸ� ���� �Ұ����ϴ�. C�� �� �̻��� ��쿡��
A + B���� Ȧ¦���� ���� ��� ���� �����ϰ�, �ٸ��ٸ� ���� �Ұ����ϴ�.

�ֿ� �˰����� : ����

��ó : �����Ž� 1ȸ A��
*/

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (abs(a) + abs(b) > c) printf("NO");
    else printf("%s", (((a + b) & 1) ^ (c & 1)) ? "NO" : "YES");
    return 0;
}