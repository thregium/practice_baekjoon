#include <stdio.h>

/*
���� : �� �ڿ��� N1 < N2(N2 <= 10000)�� �־��� ��, [N1, N2] ������ ��� �����ֿ� ����
2^(2^N)) + 1 ���� ���� �ִ������� ���� ���Ѵ�.

�ذ� ��� : ��� ��� �ִ������� 1�̴�. ����, �������� ������ ���ϸ� ���� �ȴ�.

�ֿ� �˰����� : ����, ������

��ó : SEERC 2013 J��
*/

int main(void) {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d", (n2 - n1) * (n2 - n1 + 1) / 2);
    return 0;
}