#include <stdio.h>
#include <tuple>
#include <vector>
using namespace std;

/*
문제 : (3 + sqrt(5))^N(N <= 2 * 10^9)의 소수점 위 마지막 3자리를 구한다.

해결 방법 : a = (3 + sqrt(5)), b = (3 - sqrt(5))라고 하면 a와 b는 x^2 - 6x + 4의 해가 된다.
이를 통해 정수인 a^n + b^n를 행렬식(6 -4\n1 0)^n을 통해 계산 가능하고, b^n은 0에 수렴하므로 앞의 값에서 1을 빼주면 된다.

주요 알고리즘 : 수학, 선형대수학, 분할 거듭제곱

출처 : GCJ 2008_1A C2번
*/

vector<int> start = { 2, 6, 28, 144, 752, 3936 };

const int mod = 1000000007;
const int mod2 = 1000;
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
				t[j + k] += 1ll * v[j] * w[k] % mod2;
				if (t[j + k] >= mod2) t[j + k] -= mod2;
			}
		}
		for (int j = 2 * m - 1; j >= m; j--) {
			for (int k = 1; k <= m; k++) {
				t[j - k] += 1ll * t[j] * rec[k - 1] % mod2;
				if (t[j - k] >= mod2) t[j - k] -= mod2;
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
	for (int i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % mod2;
	return ret % mod2;
}

int guess_nth_term(vector<int> x, lint n) {
	if (n < x.size()) return x[n];
	vector<int> v = berlekamp_massey(x);
	if (v.empty()) return 0;
	return get_nth(v, x, n);
}

int main(void) {
	int t, n, r;
	vector<int> v = berlekamp_massey(start);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] * 2 > mod) {
			v[i] -= mod;
			v[i] += mod2;
		}
	}
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		r = get_nth(v, start, n);
		printf("Case #%d: %03d\n", tt, (r + 999) % 1000);
	}
	return 0;
}