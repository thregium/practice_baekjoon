#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100)���� ���� ��(|| <= 100)�� �־�����. �� ������ ���ʷ� �̵��� ��, �ɸ��� ����ư �Ÿ��� ���� ���Ѵ�.

�ذ� ��� : ������ ���� �����ذ��� ������ ������ ���̸� ����� ����ư �Ÿ��� ���س����� �ȴ�.

�ֿ� �˰��� : ������, ����

��ó : Petro 2021S1 A��
*/

int main(void) {
    int n, x, y, lx, ly, r = 0;
    scanf("%d%d %d", &n, &lx, &ly);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        r += abs(lx - x) + abs(ly - y);
        lx = x;
        ly = y;
    }
    printf("%d", r);
    return 0;
}