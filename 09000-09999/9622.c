#include <stdio.h>

/*
���� : ������ ũ��� ���԰� �־����� ���ǿ� �´� �������� Ȯ���Ѵ�. (���� ����)

�ذ� ��� : ������ Ȯ���� �� �Ǵ��ϸ� �ȴ�.

�ֿ� �˰��� : ����?

��ó : Phuket 2013 I��
*/

int main(void) {
    int t, r = 0;
    double l, d, h, w;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lf %lf %lf %lf", &l, &d, &h, &w);
        if (((l > 56.005 || d > 45.005 || h > 25.005) && (l + d + h) > 125.005) || w > 7.005) printf("0\n");
        else {
            printf("1\n");
            r++;
        }
    }
    printf("%d", r);
    return 0;
}