#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
���� : ���� 2���� 500���� �丣���� �������� �����ϴ� �ռ��� N(N <= 10^15)�� ã�´�.

�ذ� ��� : ���� ���� ���μ��� 500���� ū ī����Ŭ ���� ã���� �ȴ�. �̴� http://oeis.org/A135720 ���� �����Ϳ��� ã�� �� �ִ�.
�Ǵ� ���Ʈ ������ ���� �ռ����̸鼭 �丣���� �������� �����ϴ� �ռ����� ã�� ����� �ִ�.
�� ����� �� ������ �Ҽ� ������ ������ �ϱ� ���� �з�-��� ���� ����ϰ�, �ŵ������� ������ �ϱ� ���� ���� ������ �Ѵ�.
�̶�, ���ΰ� ũ�� ������ ���� �������� �Ϻ� ��Ʈ���� ���� �� �ִٴ� ���� �����Ѵ�.

�ֿ� �˰��� : ����, ���Ʈ ����, �з�-���, ��ó��, ������

��ó : ������ 2016 I��
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
