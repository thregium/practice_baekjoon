#include <stdio.h>
#include <vector>
#include <tuple>
using namespace std;

/*
문제 : N(N <= 50000)개의 음이 아닌 정수(<= 98765431)가 주어진다. 이 정수들 각각에 대해 다른 정수들의 합으로
해당 정수를 대체하는 연산을 T(T <= 15 * 10^8)회 반복한 후 나오는 각 수들을 구한다.

해결 방법 : 이 연산을 자세히 보면 홀수번째 연산 후에는 원래의 모든 정수 합 * X(X는 정수)에서 원래의 정수를 뺀 값이고,
짝수번째 연산 후에는 원래의 정수를 더한 값임을 알 수 있다.
여기서 X의 값을 찾으면 홀수번째에는 이전 X에서 (N - 1)을 곱한 값에 1을 더한 값이고, 짝수번째에는 (N - 1)을 곱한 값에
1을 뺀 값임을 알 수 있다. 이러한 값은 행렬곱 형태이므로 벌래캠프-매시 알고리즘을 사용해
T번째의 합 * X를 빠르게 구할 수 있다. 이 값을 구한 다음, 홀수면 원래 정수를 빼고, 짝수면 원래 정수를 더한 값을 출력하면 된다.

주요 알고리즘 : 수학, 정수론, 벌래캠프-매시

출처 : USACO 2007C G1번
*/

int c[51200];
vector<int> v;

const int mod = 98765431;
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
    int n, t, s = 0, r = 0;
	//freopen("E:\\PS\\Olympiad\\USA\\3_Gold\\2007_09\\chn07\\testdata\\allchn07\\sumsums.10.in", "r", stdin);
	//freopen("E:\\PS\\Olympiad\\USA\\3_Gold\\2007_09\\chn07\\testdata\\allchn07\\sumsums.10_t.out", "w", stdout);
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
		s = (s + c[i]) % mod;
    }
	v.push_back(0);
	for (int i = 1; i < 20; i++) {
		v.push_back(((long long)v[v.size() - 1] * (n - 1) + ((i & 1) ? s : -s)) % mod);
	}
	r = guess_nth_term(v, t);
	if (t & 1) {
		for (int i = 0; i < n; i++) {
			printf("%d\n", ((mod - c[i]) + r) % mod);
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			printf("%d\n", (c[i] + r) % mod);
		}
	}
    return 0;
}