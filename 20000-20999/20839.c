#include <stdio.h>

/*
���� : �� ������ ������ �°� ����� �з��Ѵ�.

�ذ� ��� : �з���� ����� ������ �ȴ�.

�ֿ� �˰��� : ����

��ó : SwOI 2019OQ A��
*/

int main(void) {
    int a, b, c, x, y, z;
    scanf("%d %d %d%d %d %d", &a, &b, &c, &x, &y, &z);
    if (y * 2 < b) printf("E");
    else if (y < b) printf("D");
    else if (x * 2 < a) printf("C");
    else if (x < a) printf("B");
    else printf("A");
    return 0;
}