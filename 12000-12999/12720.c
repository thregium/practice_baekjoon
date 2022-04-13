#include <stdio.h>

/*
���� : [A, B](1 <= A <= B <= 10^12, B - A <= 10^6) �������� P(P <= B) �̻��� ���μ��� ����
������ ���� �ϳ��� �׷����� ���� ��, [A, B]�� ������ �� ���� �׷��� �Ǵ� �� ���Ѵ�.

�ذ� ��� : �����佺�׳׽��� ü�� �̿��� 10^6 ������ �Ҽ����� ��ó�����ش�.
�� ����, P �̻� B - A ������ �Ҽ��鿡 ���� �׷���� �����ش�. �̴� ���Ͽ�-���ε带 ����
������ ���ľ� �Ѵ�. Ȯ���ϴ� �������� ceil(A / X) + X�̰�, ������ B�̸�,
�� �׷���� ceil(A / X)�� �׷�� ��ġ�� �ȴ�. �� ��, �׷��� ���� ���� ���� ����Ѵ�.

�ֿ� �˰��� : ����, ������, �����佺�׳׽�, ���Ͽ�-���ε�

��ó : GCJ 2008B B2��
*/

char sieve[1048576];
int prime[103000], g[1048576];
int pp = 0;

int find(int x) {
    if (g[x] < 0) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int t, p;
    long long a, b, stt, res;
    for (int i = 2; i <= 1000001; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i;
        for (int j = i * 2; j <= 1000001; j += i) sieve[j] = 1;
    }

    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld %lld %d", &a, &b, &p);
        for (long long i = 0; i <= b - a; i++) g[i] = -1;

        res = b - a + 1;
        for (int i = 0; i < pp; i++) {
            if (prime[i] > b - a) break;
            else if (prime[i] < p) continue;
            stt = a / prime[i] * prime[i];
            if (stt < a) stt += prime[i];
            for (long long j = stt + prime[i]; j <= b; j += prime[i]) {
                if (find(stt - a) != find(j - a)) {
                    res--;
                    uni(stt - a, j - a);
                }
            }
        }
        printf("Case #%d: %lld\n", tt, res);

    }
    return 0;
}