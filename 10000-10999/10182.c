#include <stdio.h>
#include <math.h>

/*
���� : ���� �̿� �Ǵ� ����ȭ �̿��� �󵵰� �־��� ��, pH���� ���Ѵ�. �� �̿¿� ���� pH�� ���� ���� ���� ������ �־�����.

�ذ� ��� : ������ �־������ ��츦 ������ ���� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : PLU 2014A 2��
*/

char s[8];

int main(void) {
    int t;
    double v;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s = %lf", s, &v);
        if (s[0] == 'H') {
            printf("%.2lf\n", -log10(v));
        }
        else {
            printf("%.2lf\n", 14 + log10(v));
        }
    }
    return 0;
}