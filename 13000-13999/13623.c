#include <stdio.h>

/*
���� : �� ���� 0 �Ǵ� 1�� �־��� ��, �ٸ� �ϳ��� ���Ѵ�. ������ *�� ����Ѵ�.

�ذ� ��� : �� �� �ϳ��� �������� �ٸ��ٸ� �װ��� ����ϰ�, �׷��� ���� ���ٸ� *�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : Brasil 2013 A��
*/

int main(void) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a != b && a != c) printf("A");
    else if (b != a && b != c) printf("B");
    else if (c != a && c != b) printf("C");
    else printf("*");
    return 0;
}