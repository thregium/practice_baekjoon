#include <stdio.h>

/*
���� : �� ���� A, B(-100 <= A, B <= 100)�� �־��� ��, A + B�� A - B �� ū ���� ù° �ٿ�, ���� ���� ��° �ٿ� ����Ѵ�.

�ذ� ��� : A + B�� A - B�� ���� ���� �� �� �� �� ū ���� ã�� ��츦 ������ �� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : JOI 2021��1 3-1��
*/

int main(void) {
    int a, b, apb, amb;
    scanf("%d %d", &a, &b);
    apb = a + b, amb = a - b;
    if (apb < amb) printf("%d\n%d", amb, apb);
    else printf("%d\n%d", apb, amb);
    return 0;
}