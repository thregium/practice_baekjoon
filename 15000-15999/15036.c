#include <stdio.h>

/*
���� : N(N <= 2000)���� ��ǥ ������ �־��� ��, ��ü ��ǥ�� ���̸� ���Ѵ�.

�ذ� ��� : �� ��ǥ�� ���̸� Ȯ���ϰ� ���� ���� �� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : UKIEPC 2017 J��
*/

int main(void) {
    int n, x;
    double r = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        switch (x) {
        case 0:
            r += 1.0;
        case 1:
            r += 0.5;
        case 2:
            r += 0.25;
        case 4:
            r += 0.125;
        case 8:
            r += 0.0625;
        case 16:
            r += 0.0625;
            break;
        default:
            return 1;
        }
    }
    printf("%.9f", r);
    return 0;
}