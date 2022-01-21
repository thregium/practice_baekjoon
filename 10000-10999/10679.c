#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 1000)���� ������ 10^9 ������ ���� �Ǵ� 'x'�� �̷���� �迭�� �־�����.
'x'�� ���� ���� ���� ������ �ٲپ� ��� Ȧ����° ������ ������ �������� ũ��, ��� ¦����° ������
������ �������� �۵��� �� �� �ִ� ���� �������� ���ϰ� �����ϴٸ� �� ���� ����Ѵ�.
�����̶�� "ambigious"��, ���ٸ� "none"�� ����Ѵ�.

�ذ� ��� : x�� ������ -���Ѵ뿡�� +���Ѵ���� ������ ����������. 'x'�� Ȧ����°�� ���
�� �� �� �� ���� �� - 1�� �ִ񰪰� ���Ͽ� ������, ¦����°�� ��� �� �� �� �� ū �� + 1��
�ּڰ��� ���Ͽ� ������. �̸� �ݺ��Ͽ� ���� ������ ũ�� 1�� ��� �� ���� ����ϰ�,
2 �̻��̸� ambigious, 0�̸� none�� ����ϸ� �ȴ�. ��, 'x'�� ���̾� �ְų� �̹� ������ �� 2����
��Ģ�� ���� �ִٸ� none�� ����ؾ� �Ѵ�. 'x'�� ���� ���� 10^9�� �Ѿ �� ������ �����Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ���̽� ��ũ

��ó : JAG 2013P A��
*/

int a[1024], b[1024];
char buff[16];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, hi, lo;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2013P\\regional-2013-data\\regional-2013-data\\A.in", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2013P\\regional-2013-data\\regional-2013-data\\A_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        a[0] = INF;
        for (int i = 1; i <= n; i++) {
            scanf("%s", buff);
            if (buff[0] == 'x') b[i] = 1;
            else a[i] = strtoll(buff, NULL, 10);
        }
        a[n + 1] = (n & 1 ? INF : -INF);
        lo = -INF, hi = INF;
        for (int i = 1; i <= n; i++) {
            if (!b[i]) {
                if (i & 1) {
                    if ((!b[i - 1] && a[i] >= a[i - 1]) || (!b[i + 1] && a[i] >= a[i + 1])) lo = INF + 1;
                }
                else {
                    if ((!b[i - 1] && a[i] <= a[i - 1]) || (!b[i + 1] && a[i] <= a[i + 1])) hi = -INF - 1;
                }
                continue;
            }
            if (i & 1) hi = small(hi, small(a[i - 1], a[i + 1]) - 1);
            else lo = big(lo, big(a[i - 1], a[i + 1]) + 1);
            if (b[i - 1] || b[i + 1]) {
                lo = INF + 1;
                hi = -INF - 1;
            }
        }

        if (lo > hi) printf("none\n");
        else if (lo != hi) printf("ambiguous\n");
        else printf("%d\n", lo);

        for (int i = 1; i <= n; i++) {
            a[i] = 0, b[i] = 0;
        }
    }
    return 0;
}