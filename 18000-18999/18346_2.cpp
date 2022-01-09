#include <stdio.h>
#include <vector>
#define MOD 1000000007
using namespace std;

/*
���� : N(N <= 100000)���� ������ M(M <= 200000)���� �������� �̷���� �׷����� �ִ�.
�� �׷����� �� ������ ��� �Ǵ� ���������� ĥ���� �ִ�. �̶�, ��� ���� �������δ� ���� ���� ���� ������ ����� ������ ���
�� ������ ����� ������ ���� ���ÿ� �ٲ� �� �ְ�, ���� �������δ� �� �� �ϳ��� ���� �ٲ� �� �ִ�.
�̶�, ���� �׷������� ��� ���� �������� ���� �� �ִ� �׷����� ���� �������� ���� �� �ִ� �׷����� ������ ���Ѵ�.

�ذ� ��� : �׷����� �̺� �׷��� ���·� �ٲ� ��(�̺� �׷����� ���� �ʴ� ������ �״�� ��),
�̺� �׷����� ���� ������ ���� �ٲٸ� ���� �ٸ� ���� ������ ���� �ٲٴ� ������ �ȴ�.
�̸� �� �̿��ϸ� ��� ���ο����� �̺� �׷����� ��� N_C_K(K�� ���� �ٲ� �� ����� ����)������ �ٲ� �� ������ �� �� �ְ�,
�� ���� ��쿡�� 2^(N - 1)������ �ٲ� �� �ִ�.
��� ���� �������δ� ������ 3 �̻��� ������ �ִ� ���� ���� ��찡 ������ �ȴ�.
�� ��쿡�� �̺� �׷��� ���ο� ����Ŭ ���ε��� �������� Ǯ�̸� �ϸ� �ȴ�.
���� ��Ұ� ���� ���� ��� ���� ���ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, ���̽� ��ũ, �̺� �׷���, ���շ�

��ó : ��1 ���ð� 5��
*/

int vis[103000], fact[103000];
char color[103000];
vector<int> ed[103000];

long long mult(long long x, long long y) {
    //X^Y�� ��ȯ�Ѵ�.
    if (y == 0) return 1;
    else if (y == 1) return x;
    else {
        long long z = mult(x, y >> 1);
        if (y & 1) return (((z * z) % MOD) * x) % MOD;
        else return (z * z) % MOD;
    }
}

void unvis(int x) {
    //X�� �����ҿ� ���� �湮�� �ʱ�ȭ�Ѵ�.
    vis[x] = 0;
    for (int i : ed[x]) {
        if (vis[i]) unvis(i);
    }
}

int bip(int x, int c) {
    //X�� �����Ұ� �̺� �׷������� ����(��ȣ)�� ���� ����� ũ��(��)�� ��ȯ�Ѵ�.
    int r = 1, t;
    vis[x] = c;
    for (int i : ed[x]) {
        if (vis[i] == c && r > 0) r *= -1;
        else if (!vis[i]) {
            t = bip(i, (!(c - 1)) + 1);
            if ((t > 0 && r > 0) || (t < 0 && r < 0)) r += t;
            else if (r > 0) {
                r *= -1;
                r += t;
            }
            else r -= t;
        }
    }
    return r;
}

int getcntw(int x) {
    //���� �ٲ� �� ��� ������ ������ ��ȯ�Ѵ�.
    int r = 0;
    if ((vis[x] == 1 && color[x - 1] == '0') || (vis[x] == 2 && color[x - 1] == '1')) r++;
    vis[x] = 3;
    for (int i : ed[x]) {
        if (vis[i] < 3) r += getcntw(i);
    }
    return r;
}

int getcntt(int x) {
    //������ 3 �̻��� ������ ������ ��ȯ�Ѵ�.
    int r = (ed[x].size() >= 3);
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) r += getcntt(i);
    }
    return r;
}

int isbi(int x) {
    //��� ������ ���� ���� �� ���θ� ��ȯ�Ѵ�.
    int r = 3;
    if (color[x - 1] == '0') r ^= 1;
    else r ^= 2;
    vis[x] = 3;
    for (int i : ed[x]) {
        if (vis[i] < 3) r &= isbi(i);
    }
    return r;
}

int iscycle(int x, int l) {
    //����Ŭ���� ���θ� ��ȯ�Ѵ�.
    int r = 0;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (i == l) continue;
        if (vis[i]) r = 1;
        else r != iscycle(i, x);
    }
    return r;
}

int samecount(int x, int l) {
    //���� ���� ������ ���� * 2�� ��ȯ�Ѵ�.
    int r = 0;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (color[x - 1] == color[i - 1]) r++;
        if (i == l) continue;
        if (!vis[i]) r += samecount(i, x);
    }
    return r;
}

long long comb(long long n, long long k) {
    //N_C_K�� ���� ��ȯ�Ѵ�.
    return ((long long)fact[n] * mult(((long long)fact[k] * fact[n - k]) % MOD, MOD - 2)) % MOD;
}

int main(void) {
    int n, m, a, b, c, d, wo = 0, eo = 0, w = 1, e = 1;
    fact[0] = 1;
    for (long long i = 1; i <= 100000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    scanf("%d %d", &n, &m);
    //if (n > 21) return 1;
    scanf("%s", color);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            a = getcntt(i);
            unvis(i);
            b = bip(i, 1);
            //��� ���ν�
            if (b < 0) {
                //�̺� �׷����� �ƴ� ���
                b *= -1;
                c = 1;
                for (int j = 1; j < b; j++) c = (c * 2) % MOD;
                w = ((long long)w * c) % MOD;
            }
            else {
                //�̺� �׷����� ���
                c = getcntw(i);
                w = ((long long)w * comb(b, c)) % MOD;
            }

            unvis(i);
            b = bip(i, 1);
            //���ν�
            if (a) {
                //3�� �̻��� ������ �ִ� ���
                if (b > 0 && (c == b || c == 0)) continue; //���̻� ������ �� ���� ��
                else {
                    if (b < 0) b *= -1;
                    c = 1; //�� ���� ��� ���
                    for (int j = 0; j < b; j++) c = (c * 2) % MOD;
                    if (isbi(i)) e = ((long long)e * (c + MOD - 1)) % MOD;
                    else e = ((long long)e * (c + MOD - 2)) % MOD;
                }
            }
            else {
                //3�� �̻��� ������ ���� ���
                unvis(i);
                a = iscycle(i, -1);
                unvis(i);
                c = samecount(i, -1);
                if (b < 0) b *= -1;
                c >>= 1;
                if (a) {
                    //����Ŭ
                    d = 0;
                    if (b & 1) {
                        //���̰� Ȧ��
                        for (int i = 0; i * 2 + 1 <= c; i++) {
                            d = (d + 2LL * comb(b, i * 2 + 1)) % MOD;
                        }
                    }
                    else {
                        //���̰� ¦��
                        for (int i = 0; i * 2 <= c; i++) {
                            d = (d + 2LL * comb(b, i * 2)) % MOD;
                        }
                    }
                    if (c == 0 || c == b) d = (d + MOD - 1) % MOD;
                }
                else {
                    //�ܼ� ���
                    c++;
                    d = comb(b - 1, c - 1);
                    for (int i = 0; i < c - 1; i++) {
                        d = (d + 2LL * comb(b - 1, i)) % MOD;
                    }
                }
                e = ((long long)e * d) % MOD;
            }
        }
    }

    printf("%d %d\n", w, e);
    return 0;
}