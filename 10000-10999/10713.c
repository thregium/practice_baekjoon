#include <stdio.h>

/*
���� : �Ϸķ� �̷���� N(N <= 100000)���� ���ø� M(M <= 100000)�ϵ��� �̵��Ϸ��� �Ѵ�.
�� ���� �̵� ������ �� ������ ������ �־��� ��, ��ü ������ ������ ���Ѵ�.
�� ������ ������ ī�带 �� ���� Ƽ���� �� ���� ����������. ī�带 �� ���� ������ Ƽ���� ���Ӻ��� ������,
�� ������ ī�带 ���� ��� �Ѵ�. �� ������ ��� 100000 ������ �ڿ����̴�.

�ذ� ��� : �� ������ �̵��ϴ� Ƚ���� ���� ���� ���� ���� ����, �� �������� Ƽ�ϰ� ī�� ���
�� �� ���� ã�� ������ ���� ���� ���س����� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ���� ��

��ó : JOI 2015 1��
*/

int cnt[103000];

int big(int a, int b) {
    return a > b ? a : b;
}

long long small(long long a, long long b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, p, a, b, c, l = 0;
    long long r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p);
        if (i > 0) {
            cnt[big(p, l)]--;
            cnt[small(p, l)]++;
        }
        l = p;
    }
    for (int i = 1; i < n; i++) {
        cnt[i] += cnt[i - 1];
        scanf("%d %d %d", &a, &b, &c);
        r += small((long long)b * cnt[i] + c, (long long)a * cnt[i]);
    }
    printf("%lld\n", r);
    return 0;
}