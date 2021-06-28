#include <stdio.h>
#include <math.h>

/*
���� : �� 4���� ������ ���� ���� �ٲٴ� �۾��� �ݺ��� ��, �� ȸ �ݺ��ؾ� ��� ���� ���������� ���Ѵ�.
��, ��� ���� log(N) * 3ȸ �ȿ� �������ٴ� ���� ���� �����ϴ�.

�ذ� ��� : �ſ� ���� �ð� ���� �������� ���� Ȯ�εǾ��� ������ ���� �ùķ��̼��� ���� �ذ��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ����

��ó : SEUSA 2011 D��
*/

int main(void) {
    long long a, b, c, d, t = 0, z;
    while (1) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        if (a == 0 && b == 0 && c == 0 && d == 0) break;
        t = 0;
        while (!(a == b && a == c && a == d)) {
            z = llabs(a - d);
            a = llabs(a - b);
            b = llabs(b - c);
            c = llabs(c - d);
            d = z;
            t++;
        }
        printf("%lld\n", t);
    }
    return 0;
}