#include <stdio.h>

/*
���� : A + B = C ������ ���� �´��� �˻��Ѵ�. ��, A, B, C�� �� �ڸ� �ڿ����̴�.

�ذ� ��� : �ش� ���·� ���� �Է¹��� �� ���� �´��� ���Ѵ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó :PacNW 2016D2 R��
*/

int main(void) {
    int a, b, c;
    scanf("%d + %d = %d", &a, &b, &c);
    if (a + b == c) printf("YES");
    else printf("NO");
    return 0;
}