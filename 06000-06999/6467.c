#include <stdio.h>

/*
���� : �� �ڿ��� N�� C(N, C <= 1000)�� �־��� ��, 1000 ������ �Ҽ� �� ������� �������� C���� ���ʷ� ����Ѵ�.
�̶�, 1�� �Ҽ��� ����ϰ�, ������ �Ѿ�� ��� ���� ���� �Ҽ��� ����Ѵ�.

�ذ� ��� : ���� 1000 �̳��� �Ҽ��� ���� ���� ����, ��츦 ������ �Ҽ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����, �Ҽ� ����

��ó : SCUSA 1996 1��
*/

int sieve[1024], prime[256];
int pp = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, c, p, m;
    //freopen("E:\\PS\\ICPC\\North America\\South Central\\1996\\cuts.in", "r", stdin);
    prime[pp++] = 1;
    for (int i = 2; i <= 1024; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 1024; j += i) sieve[j] = 1;
    }
    while (scanf("%d %d", &n, &c) != EOF) {
        for (p = 0; prime[p] <= n; p++);
        m = (p - 1) >> 1;
        printf("%d %d: ", n, c);
        for (int i = big(0, m - c + 1); i < p && ((p & 1) ? i < m + c : i <= m + c); i++) {
            printf("%d ", prime[i]);
        }
        printf("\n\n");
    }
    return 0;
}