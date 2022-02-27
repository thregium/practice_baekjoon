#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
#define SZ 131072

/*
���� : ���� N(N <= 100000)�� 1���� N������ �ڿ����� �̷���� ������ �־��� ��,
�� �������� ���� K(K <= 10)�� �����ϴ� �κ� ������ ������ ���Ѵ�.

�ذ� ��� : ���� x�� i���� �����ϴ� �����ϴ� �κ� ������ ������ ������ �ΰ�
���̳��� ���α׷����� �����ϸ� �ȴ�. �� ���� ���� ���̿����� ���� ��� ���� ������ ���� ������ ������
�κ� ������ ���� �հ� ����. �̴� ���׸�Ʈ Ʈ���� �̿��� ó���Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, DP?

��ó : ?
*/

int a[103000], mem[16][103000], seg[SZ * 2];

long long getsum(int x, int y, int s, int e, int p) {
    if (x > e || y < s) return 0;
    if (x <= s && y >= e) return seg[p];
    return (getsum(x, y, s, (s + e) >> 1, p << 1) + getsum(x, y, ((s + e) >> 1) + 1, e, (p << 1) + 1)) % MOD;
}

void upd(int a, int b) {
    seg[a + SZ] = (seg[a + SZ] + b) % MOD;
    for (int i = (a + SZ) >> 1; i > 0; i >>= 1) {
        seg[i] = (seg[i << 1] + seg[(i << 1) + 1]) % MOD;
    }
}

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        //a[i] = rand() % 100;
        scanf("%d", &a[i]);
        mem[1][i] = 1;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 0; j < SZ * 2; j++) seg[j] = 0;
        for (int j = 1; j <= n; j++) {
            mem[i][j] = getsum(0, a[j] - 1, 0, SZ - 1, 1);
            upd(a[j], mem[i - 1][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        r = (r + mem[k][i]) % MOD;
    }
    printf("%d", r);
    return 0;
}