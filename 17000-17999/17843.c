#include <stdio.h>

/*
���� : 12�ð� �ð��� ��, ��, �ʰ� �־��� ��, �� ħ �� �� ħ�� �̷�� �� ��� ���� ���� ���� ���Ѵ�.

�ذ� ��� : ��, ��, �ʸ��� 12�ÿ� ���� ���� ���� ����, �� ��쿡 ���� ������ �̷�� ���� �ٽ� ���ؼ�
���� ���� ���� ã���� �ȴ�.

�ֿ� �˰��� : ������, ���Ʈ ����

��ó : UNIST 1ȸ F��
*/

double getangle(double x, double y) {
    double r = 0.0;
    if (x > y) {
        r = x - y;
        if (y + 360 - x < r) r = y + 360 - x;
        return r;
    }
    else {
        r = y - x;
        if (x + 360 - y < r) r = x + 360 - y;
        return r;
    }
}

int main(void) {
    int t, h, m, s;
    double a, b, c, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &h, &m, &s);
        c = s * 6.0;
        b = m * 6.0 + s * 0.1;
        a = h * 30.0 + m * 0.5 + s * 0.5 / 60.0;
        r = getangle(a, b);
        if (getangle(a, c) < r) r = getangle(a, c);
        if (getangle(b, c) < r) r = getangle(b, c);
        printf("%.9f\n", r);
    }
    return 0;
}