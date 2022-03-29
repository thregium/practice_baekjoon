#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N(N <= 200000)���� �������� �̷���� Ʈ���� �� ������ ���ڵ��� ���� �ִ�.
�̶�, Q(Q <= 200000)���� ������ �����Ѵ�.
A���� B�� ���� �ִ� ��ο� ���� ���ڵ��� �̾���� ���� M(M <= 10^9)���� ���� �������� ���Ѵ�.

�ذ� ��� : LCA�� ���� ���� ���� �� �ִ�. ���ڵ��� �������� 2^i�� �̾���� ���� m���� ���� ��������
�Ʒ������� �̾���� ���� ������, �ڽ��� 2^i��° �θ� �������� ������ ����,
LCA�� ���ϴ� ���ÿ� ������ ���ڵ��� ����� ������. �׸��� ���������� LCA�� ������ ����
���̴� ���ÿ� ���� ������ �̾�θ� ���� �ȴ�. �ڼ��� ������ �ڵ带 �����Ѵ�.

�ֿ� �˰��� : ����, ������, Ʈ��, LCA

��ó : MidAtl 2021 K�� // NCNA 2021 B��
*/

int digit[204800], depth[204800], b10[1048576], par[20][204800], conup[20][204800], condn[20][204800];
vector<int> ed[204800];

void maketree(int x, int p, int d) {
    depth[x] = d;
    par[0][x] = p;
    for (int i : ed[x]) {
        if (i == p) continue;
        maketree(i, x, d + 1);
    }
}

int query(int a, int b, int m) {
    int up = 0, down = 0, da = 0, db = 0;
    for (int i = 19; i >= 0; i--) {
        if (depth[a] - depth[b] > 0 && (((depth[a] - depth[b]) >> i) & 1)) {
            up = ((long long)up * b10[1 << i] + conup[i][a]) % m;
            a = par[i][a];
            da += (1 << i);
        }
        else if (depth[b] - depth[a] > 0 && (((depth[b] - depth[a]) >> i) & 1)) {
            down = (down + (long long)b10[db] * condn[i][b]) % m;
            b = par[i][b];
            db += (1 << i);
        }
    }
    for (int i = 19; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            up = ((long long)up * b10[1 << i] + conup[i][a]) % m;
            a = par[i][a];
            da += (1 << i);
            down = (down + (long long)b10[db] * condn[i][b]) % m;
            b = par[i][b];
            db += (1 << i);
        }
    }
    if (a != b) {
        up = (up * 10LL + conup[0][a]) % m;
        a = par[0][a];
        da++;
        down = (down + (long long)b10[db] * condn[0][b]) % m;
        b = par[0][b];
        db++;
    }
    return ((long long)up * b10[db + 1] + (long long)digit[a] * b10[db] + down) % m;
}

int main(void) {
    int n, m, q, a, b;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    maketree(1, -1, 0);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (par[i - 1][j] < 0) par[i][j] = -1;
            else par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    b10[0] = 1;
    for(int i = 1; i < 1048576; i++) b10[i] = (b10[i - 1] * 10LL) % m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &digit[i]);
        conup[0][i] = digit[i];
        condn[0][i] = digit[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (par[i][j] < 0) continue;
            conup[i][j] = ((long long)conup[i - 1][j] * b10[1 << (i - 1)] +
                conup[i - 1][par[i - 1][j]]) % m;
            condn[i][j] = (condn[i - 1][j] + (long long)condn[i - 1][par[i - 1][j]] *
                b10[1 << (i - 1)]) % m;
        }
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a, b, m));
    }
    return 0;
}