#include <stdio.h>
#include <tuple>
#include <vector>
using namespace std;

/*
문제 : K(K <= 66) 이하의 자연수로 이루어진 길이 N(N <= 10^18)의 배열 가운데
인접한 두 수가 모두 서로소인 것의 개수를 구한다.

해결 방법 : 점화식이 선형이므로 작은 값(백 단위)에 대해 답을 구해둔 다음 벌래캠프-매시를 이용할 수 있다.

주요 알고리즘 : DP, 벌래캠프-매시

출처 : CTU 2021 S번
*/

const int mod = 1000000007;
int ans[1024], mem[1024][128];

int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

using lint = long long;
lint ipow(lint x, lint p) {
	lint ret = 1, piv = x;
	while (p) {
		if (p & 1) ret = ret * piv % mod;
		piv = piv * piv % mod;
		p >>= 1;
	}
	return ret;
}
vector<int> berlekamp_massey(vector<int> x) {
	vector<int> ls, cur;
	int lf, ld;
	for (int i = 0; i < x.size(); i++) {
		lint t = 0;
		for (int j = 0; j < cur.size(); j++) {
			t = (t + 1ll * x[i - j - 1] * cur[j]) % mod;
		}
		if ((t - x[i]) % mod == 0) continue;
		if (cur.empty()) {
			cur.resize(i + 1);
			lf = i;
			ld = (t - x[i]) % mod;
			continue;
		}
		lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
		vector<int> c(i - lf - 1);
		c.push_back(k);
		for (auto& j : ls) c.push_back(-j * k % mod);
		if (c.size() < cur.size()) c.resize(cur.size());
		for (int j = 0; j < cur.size(); j++) {
			c[j] = (c[j] + cur[j]) % mod;
		}
		if (i - lf + (int)ls.size() >= (int)cur.size()) {
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
		}
		cur = c;
	}
	for (auto& i : cur) i = (i % mod + mod) % mod;
	return cur;
}
int get_nth(vector<int> rec, vector<int> dp, lint n) {
	int m = rec.size();
	vector<int> s(m), t(m);
	s[0] = 1;
	if (m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](vector<int> v, vector<int> w) {
		int m = v.size();
		vector<int> t(2 * m);
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				t[j + k] += 1ll * v[j] * w[k] % mod;
				if (t[j + k] >= mod) t[j + k] -= mod;
			}
		}
		for (int j = 2 * m - 1; j >= m; j--) {
			for (int k = 1; k <= m; k++) {
				t[j - k] += 1ll * t[j] * rec[k - 1] % mod;
				if (t[j - k] >= mod) t[j - k] -= mod;
			}
		}
		t.resize(m);
		return t;
	};
	while (n) {
		if (n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	lint ret = 0;
	for (int i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % mod;
	return ret % mod;
}
int guess_nth_term(vector<int> x, lint n) {
	if (n < x.size()) return x[n];
	vector<int> v = berlekamp_massey(x);
	if (v.empty()) return 0;
	return get_nth(v, x, n);
}

int main(void) {
	int k, r;
	vector<int> v;
	long long n;
	scanf("%d %lld", &k, &n);
	mem[0][1] = 1;
	ans[0] = mem[0][1];
	for (int i = 1; i < 1000; i++) {
		for (int x = 1; x <= k; x++) {
			for (int y = 1; y <= k; y++) {
				if (gcd(x, y) > 1) continue;
				mem[i][x] = (mem[i][x] + mem[i - 1][y]) % mod;
			}
			ans[i] = (ans[i] + mem[i][x]) % mod;
		}
		if (i < 500) v.push_back(ans[i]);
	}

	for (int i = 500; i < 1000; i++) {
		r = guess_nth_term(v, i - 1LL);
		//printf("%d %s %d\n", ans[i], ans[i] == r ? "=" : "!=", r);
		if (ans[i] != r) return 1;
	}

	printf("%d", guess_nth_term(v, n - 1LL));

	return 0;
}