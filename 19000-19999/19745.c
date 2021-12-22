#include <stdio.h>
#include <string.h>

/*
���� : �ڿ��� N(N <= 10^18)�� �־��� ��, N���� ū �ڿ��� ��� ������ ���� ���ڰ� ���� ���� ���� �ڿ����� ���Ѵ�.

�ذ� ��� : �� �� �ڸ����� ���캸�� ���� �տ��� ������ ���� ���ڰ� �ִٸ� �ش� ���� 0���� ����� ������ ����.
�ش� �ڸ��� ������ ���� ������ ��� �ش� �ڸ��� 1�� ������Ű�� �ٽ� �ش� �ڸ��� ���캻��.
�� ���� ���� �� �ڸ��� ����. �̸� �ݺ��Ͽ� �� �ڿ��� �� �ڸ��� ���� �Ǹ� ������ ���� ���� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ��Ʈ��ŷ

��ó : ROI 2017H E��
*/

char path[256], s[32];

int main(void) {
    unsigned long long n, d = 1, l;
    int r, p = 0;
    for (int tt = 1; tt <= 1; tt++) {
        d = 1, p = 0;
        //sprintf(path, "E:\\PS\\Olympiad\\Russia\\2017H\\ru-olymp-team-spb-2017-archive\\diffdigits\\tests\\%02d", tt);
        //freopen(path, "r", stdin);
        scanf("%lld", &n);
        n++;
        while (d > 0) {
            sprintf(s, "%llu", n);
            l = strlen(s);
            r = -1;
            for (int i = 1; i < l - p - 1; i++) {
                if (s[i] == s[i - 1]) r = 1;
            }
            if (p + 1LL < l && s[l - p - 1] == s[l - p - 2]) {
                n += d;
                r = 0;
            }
            if (r > 0) {
                n -= d * ((n / d) % 10);
                d *= 10;
            }
            else if (r < 0) d /= 10;
            p += r;
        }
        //sprintf(path, "E:\\PS\\Olympiad\\Russia\\2017H\\ru-olymp-team-spb-2017-archive\\diffdigits\\tests\\%02d.a", tt);
        //freopen(path, "r", stdin);
        //scanf("%llu", &d);
        //printf("%llu : %llu -> %d\n", n, d, (n == d));
        printf("%llu", n);
    }
    return 0;
}