#include <stdio.h>
#include <vector>
#include <tuple>
using namespace std;

/*
문제 : N^M(N, M <= 10^9)의 모든 약수의 합을 구한다.

해결 방법 : 충분히 큰 K까지의 N^K의 약수의 합을 구하고 벌래캠프-매시를 통해 N^M의 약수의 합을 구할 수 있다.
또는 소수의 제곱끼리의 약수의 합의 곱이 두 수의 곱의 약수의 합과 같음을 이용하면 N^3까지의 합만으로도 구할 수 있다.

주요 알고리즘 : 수학, 벌래캠프-매시
*/

//vector<int> v = { 1, 18, 217, 2340, 24211, 246078, 2480437, 24902280 };
//vector<int> v = { 1, 12, 91, 600, 3751, 22932, 138811, 836400 };
vector<int> v;
const int mod = 1000000007;
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
	int n, m, x, z, r = 1;
	long long y;
	vector<int> ve;
	scanf("%d %d", &n, &m);

	for (int i = 2; i * i <= n; i++) {
		x = 1;
		z = 0;
		while (n % i == 0) {
			x = i;
			z++;
			n /= i;
		}
		if (z) {
			v.clear();
			v.push_back(1);
			y = x;
			for (int j = 1; j < 4; j++) {
				v.push_back((v[v.size() - 1] + y) % mod);
				y = (y * x) % mod;
			}
			r = (long long)r * guess_nth_term(v, (long long)m * z) % mod;
		}
	}
	if (n > 1) {
		v.clear();
		v.push_back(1);
		y = n;
		for (int j = 1; j < 4; j++) {
			v.push_back((v[v.size() - 1] + y) % mod);
			y = (y * n) % mod;
		}
		r = (long long)r * guess_nth_term(v, m) % mod;
	}
	printf("%d", r);
	return 0;
}