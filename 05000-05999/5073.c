#include <stdio.h>

/*
���� : �־��� �� ���� ���̸� ���� �ﰢ���� ���� �� �ִ��� Ȯ���ϰ� �����ϴٸ�
���ﰢ������ �̵�ﰢ������ �ε�ﰢ������ ���Ѵ�.

�ذ� ��� : ����, �� ���� ���̰� �ٸ� �� ���� ���� �̻��̶�� �ﰢ���� ���� �� ����.
�׷��� �ʴٸ� ��� ���� �������� Ȯ���ϰ�(���ﰢ��), ���� ���� �ϳ��� �ִ���(�̵�ﰢ��) Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ������

��ó : NZPC 2012 B��
*/

int main(void) {
    int t, a, b, c;
    for (;;) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) break;
        if (a >= b + c || b >= a + c || c >= a + b) printf("Invalid\n");
        else if (a == b && a == c) printf("Equilateral\n");
        else if (a == b || a == c || b == c) printf("Isosceles\n");
        else printf("Scalene\n");
    }
    return 0;
}