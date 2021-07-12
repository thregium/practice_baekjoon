#include <stdio.h>

/*
���� : ������ ��÷ ��ȣ�� �� ������ ��ȣ, �� �ݾ��� �־��� ��, ���� �� �ִ� �ݾ��� ���Ѵ�. (���� ����)

�ذ� ��� : ���ؿ� �°� ������ ��÷���� Ȯ���Ѵ�.

�ֿ� �˰��� : ����, ��Ģ����, ����

��ó : Brasil 2005 A��
*/

int main(void) {
    double v;
    int n, m;
    while (1) {
        scanf("%lf %d %d", &v, &n, &m);
        if (v < 0.005) break;
        if (n % 10000 == m % 10000) printf("%.2f\n", v * 3000);
        else if (n % 1000 == m % 1000) printf("%.2f\n", v * 500);
        else if (n % 100 == m % 100) printf("%.2f\n", v * 50);
        else if ((n + 99) % 100 / 4 == (m + 99) % 100 / 4) printf("%.2f\n", v * 16);
        else printf("0.00\n");
    }
    return 0;
}