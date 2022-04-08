#include <stdio.h>
#include <vector>
#define MOD 998244353LL
using namespace std;

/*
���� : N(N <= 10000)���� ������ ���� Ʈ���� �ִ�. �� �������� �̵��ؾ� �ϴ� Ƚ��(<= 200, ¦��)�� �־��� ��,
1�� �������� ����ؼ� ��� �������� ��Ȯ�� �ش� Ƚ����ŭ �̵��ϰ� ���ƿ��� ����� �������� ���Ѵ�.

�ذ� ��� : Ʈ���� ����� DP�� ���� ���Ѵ�. �� �������� ����ϰ� ���ƿ��� ����� ������ �����ϰ�
����� ������. �켱, �� �������� ��� �ڽ� ������ ��� ������ ���� ����Ѵ�.
�� ����, (���� �ڽ� �������� ����� ������ ��)C(���� �ڽ� �������� ����� ����)�� ����Ͽ� ���� ���Ѵ�.
�̴� �� �ڽ� �������� �湮�ϴ� ������ ����ϱ� �����̴�. ���� ����� ����� ������ ������ �ϱ� ����
�丣���� �������� ���� ����� �Ѵ�.
����������, �� �ڽ� ������ ���� �� ������ �ڽ� ������� �湮�ϴ� ������ ���ϱ� ���� �ߺ������� �����
�� ���� �����ش�. �̴� (�ڽ� ������ ��� �ڽ� ������ �� + �ڽ� ���������� �� - 1)C(�ڽ� ������
��� �ڽ� ������ ��)�� ����.
�� ���� ��������� ����� 1�� ���������� ���� ���� �� ����ϸ� �ȴ�.

�ֿ� �˰��� : DP, Ʈ��DP, ���շ�

��ó : INC 2020 G��
*/

int mem[10240], fact[1048576], csum[10240];
vector<pair<int, int>> ed[10240], chd[10240];

long long powe(long long x, long long y, long long m) {
    if (y == 0) return 1;
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

long long comb(long long n, long long k) {
    return fact[n] * powe(fact[k] * (long long)fact[n - k] % MOD, MOD - 2, MOD) % MOD;
}

void mktree(int x, int p) {
    mem[x] = -1;
    for (auto& i : ed[x]) {
        if (i.first == p) continue;
        chd[x].push_back(i);
        csum[x] += i.second;
        mktree(i.first, x);
    }
}

int dp(int x) {
    if (mem[x] >= 0) return mem[x];
    long long r = 1, sum = 0;
    for (auto& i : chd[x]) {
        r = (r * dp(i.first)) % MOD;
        r = (r * comb(i.second + csum[i.first] - 1, csum[i.first])) % MOD;
        sum += i.second;
    }
    for (auto& i : chd[x]) {
        r = (r * comb(sum, i.second)) % MOD;
        sum -= i.second;
    }
    return r;
}

int main(void) {
    int n, a, b, c;
    fact[0] = 1;
    for (long long i = 1; i < 1048576; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (c & 1) return 1;
        c >>= 1;
        ed[a].push_back({ b, c });
        ed[b].push_back({ a, c });
    }
    mktree(1, -1);
    printf("%d", dp(1));
    return 0;
}