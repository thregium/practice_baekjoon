#include <stdio.h>

/*
���� : N���� ������ ��Ʈ X �Ǵ� Y���� ���� ����� �Ѵ�. ��Ʈ X�� Y�� ���� ���� ������ ���� �־��� ��,
�ʿ��� �ּ� �ݾ��� ���Ѵ�. ��, �־����� ��� ���� 1000 ������ �����̴�.

�ذ� ��� : ������ ��µ� �ʿ��� ��Ʈ�� ���� ���������� �ø��� ���� ��� �����ϴ�. �̿� �� ��Ʈ�� ������ ���ϸ�
�� ��Ʈ�� ������ ��µ� �ʿ��� �ݾ��� �ǰ�, �� �� �� �� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰����� : ����, ��Ģ����

��ó : JOI 2018P 1��
*/

int main(void) {
    int n, a, b, c, d, x, y;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
    x = (n + a - 1) / a * b;
    y = (n + c - 1) / c * d;
    if (x < y) printf("%d", x);
    else printf("%d", y);
    return 0;
}