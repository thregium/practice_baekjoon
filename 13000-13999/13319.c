#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
문제 : 밑이 2부터 500까지 페르마의 소정리를 만족하는 합성수 N(N <= 10^15)을 찾는다.

해결 방법 : 가장 작은 소인수가 500보다 큰 카마이클 수를 찾으면 된다. 이는 http://oeis.org/A135720 등의 데이터에서 찾을 수 있다.
또는 브루트 포스를 통해 합성수이면서 페르마의 소정리를 만족하는 합성수를 찾는 방법도 있다.
이 방법을 할 때에는 소수 판정을 빠르게 하기 위해 밀러-라빈 법을 사용하고, 거듭제곱을 빠르게 하기 위해 분할 정복을 한다.
이때, 모듈로가 크기 때문에 곱셈 과정에서 일부 비트씩만 곱할 수 있다는 점에 유의한다.

주요 알고리즘 : 수학, 브루트 포스, 밀러-라빈, 전처리, 구성적

출처 : 꼬마컵 2016 I번
*/

typedef long long ll;

int primes[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };

ll mul(ll n, ll m, ll M) {
	if (!m) return 0;
	if (m & 255) return (n * (m & 255) + mul((n << 8) % M, (m >> 8), M)) % M;
	else return mul((n << 8) % M, (m >> 8), M);
}

ll pw(ll n, ll m, ll M) {
	ll ans = 1;
	
	if (M <= 3000000000) {
		while (m) {
			if (m & 1) ans = (ans % M) * (n % M) % M;
			n = (n % M) * (n % M) % M; m >>= 1;
		}
	}
	else {
		
		while (m) {
			if (m & 1) ans = mul(ans, n, M);
			n = mul(n, n, M); m >>= 1;
		}
	}
	return ans;
}

int m_r(int p, ll n) {
	ll s = 0, d = n - 1;
	while (~d & 1) {
		s++;
		d >>= 1;
	}
	if (pw(p, d, n) == 1) return 1;
	for (int i = 0; i < s; i++) {
		if (pw(p, d << i, n) == n - 1) return 1;
	}
	return 0;
}

int main()
{
	ll n, m;
	int r;
	//smallest = 413138881
	//assert(scanf("%lld%lld", &n, &m) == 2);
	//assert(500 < n && n <= 1e15 && 2 <= m && m < n&& n% m == 0)
	/*
	for (ll tt = 501;; tt++) {
		r = 1;
		for (int i = 0; i < 9; i++) {
			if (!m_r(primes[i], tt)) {
				r = 0;
				break;
			}
		}
		if (r) continue;
		r = 1;
		for (int i = 2; i <= 500; i++) {
			if (pw(i, tt - 1, tt) != 1) {
				r = 0;
				break;
			}
		}
		if (r) {
			printf("%lld\n", tt);
		}
	}
	*/
	printf("103077311401 44101");
	return 0;
}
