#include <stdio.h>

/*
���� : N(N <= 10)�� �־��� ��, �� �� �Ǵ� �� ������ ��Ÿ���� ����� �������� ���Ѵ�.
��, �� ������ ��Ÿ���� ��� ������ �ٸ� ���� ���� ����̴�.

�ذ� ��� : N�� ������ �����Ƿ� ���� 1���� 10���� ��Ÿ���� ����� �� ����.
���� 1, 2, 2, 3, 3, 3, 2, 2, 1, 1�����̴�.

�ֿ� �˰��� : ����, ���̽� ��ũ, ��ó��

��ó : CCC 2010 J1��
*/

int main(void) {
    int n;
    scanf("%d", &n);
    switch (n) {
    case 1:
    case 9:
    case 10:
        printf("1");
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        printf("2");
        break;
    case 4:
    case 5:
    case 6:
        printf("3");
        break;
    default:
        return 1;
    }
    return 0;
}