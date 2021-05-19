#include <stdio.h>
#include <tuple>
#include <vector>
using namespace std;

/*
문제 : Ai = F(i) * i^k이고, F(1) = 1, F(2) = 2, F(x) = F(x - 2) + F(x - 1)이라고 한다.
이때, N(N <= 10^17)과 K(K <= 40)가 주어질 때, A1 + A2 + ... + An의 값을 구한다.

해결 방법 : 점화식이 행렬 형태로 표현 가능하기 때문에 벌래캠프-매시를 통해 답을 구할 수 있다.
-증명 - 미완성

주요 알고리즘 : 수학, DP, 벌래캠프-매시
*/

const int mod = 1000000007;
int ans[1024];
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
    long long n;
    int k, m, r;
    vector<int> v, fibo, an;
    scanf("%lld %d", &n, &k);
    fibo.push_back(1);
    fibo.push_back(2);
    for (int i = 2; i < 600; i++) {
        fibo.push_back((fibo[i - 2] + fibo[i - 1]) % mod);
    }
    for (int i = 0; i < 600; i++) {
        m = fibo[i];
        for (int j = 0; j < k; j++) m = ((long long)m * (i + 1)) % mod;
        an.push_back(m);
        if (i == 0) v.push_back(m);
        else if (i < 300) v.push_back((m + ans[i - 1]) % mod);
		if (i == 0) ans[i] = m;
		else ans[i] = (m + ans[i - 1]) % mod;
    }

	/*
    for (int i = 300; i < 600; i++) {
		r = guess_nth_term(v, i);
		printf("%d %s %d\n", ans[i], ans[i] == r ? "=" : "!=", r);
    }
	*/
	printf("%d", guess_nth_term(v, n - 1));

    return 0;
}