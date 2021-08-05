#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 14)���� ������ ���� ���̰� ��Ȯ�� L(L <= 10^15)�� ���ǿ� ��ȸ�� �ִ��� Ȯ���Ѵ�.

�ذ� ��� : N!�� �ſ� ũ�� ������ �ð� ���� ������ ��ƴ�. ����, L�� �ѷ� ������ ���� �������� �� �������� �̵��ϴ� �Ÿ���,
�� �������� ���� �������� �̵��ϴ� �Ÿ����� ���� �����Ѵ�. �̶�, ��ġ�� ���� �� ��ΰ� ��ġ�� �ʾƾ� �ϱ� ������
��ε� �����ؾ� �Ѵ�. ������ ����� ������ �ʿ����� �ʰ� ���İ� �����鸸 ������ �ȴ�.
���İ� �������� ��Ʈ����ŷ�� ���� ������ �θ� �ȴ�. ���⼭ ���� ������ �ݴ��� �� ������ ��ġ�� ���� �����Ѵ�.

���� �� ����� �Ÿ��� ��ģ��. �� ������ ������ ��ΰ� ���� �ݴ��� ��������� ���� Ȯ���ϸ� �� �� ���� ���� ��Ȯ�� L�� �Ǵ�
��ΰ� �ִ��� Ȯ���Ѵ�. ���� �׷��� ���� �ִٸ� ��Ȯ�� L�� ��ȸ�� �ִ� ���̰�, ���ٸ� �׷� ��ȸ�� ���� ���̴�.

�ֿ� �˰��� : �׷��� �̷�, ����� Ž��, �� �� �� �̵�

��ó : NWERC 2014 I��
*/

long long dists[16][16];

vector<int> check;
vector<long long> upper[16][16384], lower[16][16384];

int checknum(int n) {
    int r = 0;
    for (int i = 0; i < n; i++) r += check[i] << i;
    return r;
}

void tracku(int n, int u, int r, int x, long long l) {
    if (r == u) {
        upper[x][checknum(n)].push_back(l);
        return;
    }
    for (int i = 1; i < n; i++) {
        if (check[i]) continue;
        check[i] = 1;
        tracku(n, u, r + 1, i, l + dists[x][i]);
        check[i] = 0;
    }
}

void trackd(int n, int d, int r, int x, int s, long long l) {
    if (r == d) {
        check[0] = 0;
        lower[s][checknum(n)].push_back(l + dists[x][0]);
        check[0] = 1;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (!check[i] || i == s) continue;
        check[i] = 0;
        trackd(n, d, r + 1, i, s, l + dists[x][i]);
        check[i] = 1;
    }
}

int main(void) {
    int n, u, r = 0;
    long long l;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2014\\indoorienteering\\data\\secret\\16-small-impossible.in", "r", stdin);
    scanf("%d %lld", &n, &l);
    u = (n >> 1);
    for (int i = 0; i < n; i++) {
        check.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &dists[i][j]);
        }
    }
    tracku(n, u, 0, 0, 0);
    for (int i = 0; i < n; i++) check[i] = 1;
    for (int i = 1; i < n; i++) trackd(n, n - u - 1, 0, i, i, 0);
    for (int i = 1; i < n; i++) {
        for (int u1 = 0; u1 < (1 << n); u1++) {
            for (long long u2 : upper[i][u1]) {
                for (long long d2 : lower[i][u1]) {
                    if (u2 + d2 == l) r = 1;
                }
            }
        }
    }
    if (r) printf("possible");
    else printf("impossible");
    return 0;
}