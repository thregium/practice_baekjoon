#include <stdio.h>
#define INF 1012345678

/*
���� : N!(N <= 10^6)�� B(B <= 1000)�������� ��Ÿ������ �� �� �ڿ� �ٴ� 0�� ���� T(T <= 1000)ȸ �ݺ��Ͽ� ���Ѵ�.

�ذ� ��� : ���� 1000 ������ ��� ���μ����� �̸� �����ش�. �� ����, N�� B�� �־����� N!�� B�� ���� ���μ����� ���� ���Ѵ�.
�� ���� N�� f(B)(f(B)�� B�� ���μ�)�� ��� ������ ���� N / f(B)�� ���� �հ� ����. ���� �� ������ g(B)(g(B)�� f(B)�� ����)
�� ������ �� ���� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ������, �Ҽ� ����

��ó : TUD 2006S 1��
*/

int sieve[1024], divi[1024][8], divic[1024][8], cnt[8];

int main(void) {
    int t, b, n, r;
    for (int i = 2; i <= 1000; i++) {
        if (sieve[i]) continue;
        for (int j = i; j <= 1000; j += i) {
            sieve[j] = 1;
            divi[j][++divi[j][0]] = i;
        }
    }
    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= divi[i][0]; j++) {
            for (int x = i; !(x % divi[i][j]); x /= divi[i][j]) divic[i][j]++;
        }
    }

    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &b, &n);
        r = INF;
        for (int j = 1; j <= divi[b][0]; j++) {
            for (int x = n; x; x /= divi[b][j]) cnt[j] += x / divi[b][j];
        }
        for (int i = 1; i <= divi[b][0]; i++) {
            if (cnt[i] / divic[b][i] < r) r = cnt[i] / divic[b][i];
            cnt[i] = 0;
        }
        printf("Scenario #%d:\n", tt);
        printf("%d\n\n", r);
    }
    return 0;
}