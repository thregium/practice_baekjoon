#include <stdio.h>

/*
���� : kg, lb, l, g(����)�� �� ��ü�� ���� �Ǵ� ���ǰ� �־��� ��, �ٸ� ������ �ٲپ� ����Ѵ�. (����ǥ ����)

�ذ� ��� : ��ü�� ������ ���ڿ��� ���� ���� ���ڿ��� ���캸�� � �������� Ȯ���ϰ� ��쿡 ���� �ٲٸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����, ���ڿ�

��ó : GNY 2007 B��
*/

char buff[8];

int main(void) {
    int t;
    double x;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lf %s", &x, buff);
        if (buff[0] == 'k') printf("%.4f lb\n", x * 2.2046);
        else if (buff[0] == 'l' && buff[1] == 'b') printf("%.4f kg\n", x * 0.4536);
        else if (buff[0] == 'l') printf("%.4f g\n", x * 0.2642);
        else printf("%.4f l\n", x * 3.7854);
    }
    return 0;
}