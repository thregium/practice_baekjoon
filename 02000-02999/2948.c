#include <stdio.h>

/*
���� : �ϰ� ���� �־��� ��, 2009�� �������� ���� �������� ���Ѵ�.

�ذ� ��� : �� ������ ������ ������ ���� �̸� �����ص� ��, �� ��° �������� Ȯ���Ѵ�. �� ����, �� ���� 7�� ���� �������� ����
������ �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : COCI 08/09#4 2��
*/

int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int main(void) {
    int d, m, d2;
    scanf("%d %d", &d, &m);
    d2 = d + days[m];
    switch (d2 % 7) {
    case 0:
        printf("Wednesday");
        break;
    case 1:
        printf("Thursday");
        break;
    case 2:
        printf("Friday");
        break;
    case 3:
        printf("Saturday");
        break;
    case 4:
        printf("Sunday");
        break;
    case 5:
        printf("Monday");
        break;
    case 6:
        printf("Tuesday");
        break;
    default:
        return 1;
        break;
    }
    return 0;
}