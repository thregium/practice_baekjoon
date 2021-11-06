#include <stdio.h>
#include <math.h>

/*
���� : D, ���� �ػ�, ���� �ػ󵵰� ���� �־��� ��, ������ ���� DPI�� ���� ���Ѵ�. (���� �������� �־�����.)
ȭ�� ��� 16:9�� �����ٰ� �����Ѵ�.

�ذ� ��� : ������ �־��� �Ĵ�� ���� ���� ���� ����Ѵ�.

�ֿ� �˰��� : ����, ����

��ó : UVaH 2011 PB��
*/

int main(void) {
    int rh, rv;
    double d, w, h;
    while (1) {
        scanf("%lf %d %d", &d, &rh, &rv);
        if (rh == 0) break;
        w = 16 * d / sqrt(337);
        h = 9.0 / 16.0 * w;
        printf("Horizontal DPI: %.2f\n", rh / w);
        printf("Vertical DPI: %.2f\n", rv / h);
    }
    return 0;
}