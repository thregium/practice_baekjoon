#include <stdio.h>

/*
���� : �� ���� ����(<= 10^9, ���� �ƴ� ����)�� �־��� ��, �׷��� ������ ����� ���� ���� ��� Ƚ���� ���� �¹��и� ���Ѵ�.
�̱�� ���� 3��, ���� ���� 1���̴�. �׷��� ������ �Ұ����� ��� -1�� ����Ѵ�.

�ذ� ��� : �� ���� ���� ������ �� ���� ������ ��� Ƚ���� ���� �ϱ� ���ؼ��� ���� ��츦 �ּ������� �ؾ� �Ѵ�.
����, ��� ���� �ݵ�� �� ���� ���� ������ ���� �ǰ�, �̱� ���� ������ 3�� ������ �ޱ� ������
�� ���� ������ 3���� ���� �������� ���� �ٸ��ٸ� �׷��� ����� ���� �� ����.
����� ���� �� �ִ� ��� �ּ��� ��� Ƚ���� �� �������� ����, ���ڰ� �̱� Ƚ���� ������ 3���� ���� ��� ����.

�ֿ� �˰����� : ����, �׸��� �˰�����

��ó : Inno 20-21Q1 A��
*/

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a % 3 == b % 3) printf("%d %d %d", a / 3, a % 3, b / 3);
    else printf("-1");
    return 0;
}