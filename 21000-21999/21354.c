#include <stdio.h>

/*
���� : A * 7�� P * 13 �� �� ū ���� �������� ���Ѵ�.

�ذ� ��� : ������ ���δ�� �����Ѵ�.

�ֿ� �˰��� : ����?

��ó : SwOI 2021Q A��
*/

int main(void) {
    int a, p;
    scanf("%d %d", &a, &p);
    if (a * 7 < p * 13) printf("Petra");
    else if (a * 7 == p * 13) printf("lika");
    else printf("Axel");
    return 0;
}