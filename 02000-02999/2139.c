#include <stdio.h>

/*
���� : ������ ��¥�� �־��� ��, �� ���� �ش� ������ �� ��° ������ ���Ѵ�.

�ذ� ��� : �ش� ������ �������� Ȯ���� ����, �ش� �� ���������� ���� ��¥ ���� ���ϰ� �ش� �ϰ� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : NZPC 2005 C��
*/

int days[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

int isleap(int x) {
    if (x % 400 == 0) return 1;
    else if (x % 100 == 0) return 0;
    else if (x & 3) return 0;
    else return 1;
}

int main(void) {
    int d, m, y;
    while (1) {
        scanf("%d %d %d", &d, &m, &y);
        if (d == 0) break;
        if (m > 2 && isleap(y)) printf("%d\n", days[m] + d + 1);
        else printf("%d\n", days[m] + d);
    }
    return 0;
}