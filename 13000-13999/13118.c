#include <stdio.h>

/*
���� : X�� ���� �� 4���� �� �ϳ��� �־��� ��, ���� �������� ��� �Ǵ� ���� ���Ѵ�.
��, �������� ��� ��� ���߰�, �� �� ��ο� ���� ���� ���� �ִ�.

�ذ� ��� : ���� �߽ɰ� ���� X��ǥ�� ���� ���� ��� �ȴ�.

�ֿ� �˰��� : ����, ������?

��ó : CoderH 2016R2 A��
*/

int main(void) {
    int p1, p2, p3, p4, x, y, r;
    scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
    scanf("%d %d %d", &x, &y, &r);
    if (x == p1) printf("1");
    else if (x == p2) printf("2");
    else if (x == p3) printf("3");
    else if (x == p4) printf("4");
    else printf("0");
    return 0;
}