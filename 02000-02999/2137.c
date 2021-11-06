#include <stdio.h>
#include <stdlib.h>

/*
���� : �и�� ���ڰ� ��� 32767 ������ �ڿ����̰� ���ڰ� �и𺸴� ���� �м��� �־�����. �Է°��� ������ ������Ű�鼭
���� �м��� ���� ����� �м��� ����Ѵ�. ��, ���� �м��� ���� ���̾�� �� �Ǹ�, ���� ����� �м��� ���� ���� ���
���� ���� �м��� ����ؾ� �Ѵ�.

�ذ� ��� : �и�� ������ ������ �о ���� Ž�����δ� �ð� ���� Ž���ϱ� ������� �Ű� ���� Ž�����δ�
�ð� ���� Ž���� �� �ִ�. 2���� 32767������ �и� ���� ���� ���� �м��� �ش� �и𿡼� �ִ� ������ ���Ѵ�.
�� ����, �ش� ������ �հ� �ڿ� �ִ� �ڿ����� ���ڷ� �Ͽ� ������� �м��� ��� ���� ����� �м��� ã���� �ȴ�.
�м��鳢�� ���� ������ ����� ���� ���� �� �ִ�.

�ֿ� �˰��� : ����, �Ķ��Ʈ��

��ó : USACO 2005O S1��
*/

typedef struct frac {
    long long n;
    long long d;
} frac;

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

frac minusf(frac a, frac b) {
    //�м� A���� �м� B�� �� ���� ���м� ���·� ��Ÿ�� ���� ����Ѵ�.
    long long newd = a.d * b.d;
    long long newn = a.n * b.d - b.n * a.d;
    long long gcdf = gcd(abs(newd), abs(newn));
    frac r;
    r.d = newd / gcdf;
    r.n = newn / gcdf;
    return r;
}

frac absf(frac a) {
    //�м� A�� ������ ���Ѵ�.
    if (a.n < 0) a.n = -a.n;
    return a;
}

int main(void) {
    int l, h;
    frac forig, fres, ftest, fret;
    scanf("%lld %lld", &forig.n, &forig.d);
    fres.n = 2;
    fres.d = 1;
    for (int i = 2; i < 32768; i++) {
        l = 0, h = i;
        ftest.d = i;
        while (l + 1 < h) {
            //�и� i�� �� ���� �м��� ���Ե� ������ ������ ã�´�.
            ftest.n = ((l + h) >> 1);
            fret = minusf(forig, ftest);
            if (fret.n < 0) h = ((l + h) >> 1);
            else l = ((l + h) >> 1);
        }
        if (l > 0) {
            ftest.n = l; //������ ���� ��
            if (minusf(forig, ftest).n != 0) {
                if (minusf(absf(minusf(forig, ftest)), absf(minusf(forig, fres))).n < 0) fres = ftest;
            }
        }
        if (l + 1 < i) {
            ftest.n = l + 1; //������ ���� ��
            if (minusf(forig, ftest).n != 0) {
                if (minusf(absf(minusf(forig, ftest)), absf(minusf(forig, fres))).n < 0) fres = ftest;
            }
        }
    }
    printf("%lld %lld", fres.n, fres.d);
    return 0;
}