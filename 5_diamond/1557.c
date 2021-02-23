#include <stdio.h>
/*
문제 : 10억 이하의 자연수 N이 주어질 때 어떠한 제곱 수로도 나누어 떨어지지 않는(제곱ㄴㄴ수) N번째 자연수를 출력한다.

해결 방법 :
1에서 N까지의 제곱ㄴㄴ수가 N - N / (소수^2) + N / (서로 다른 두 소수의 곱^2) - N / (서로 다른 세 소수의 곱^2) + N / (서로 다른 네 소수의 곱^2) - ... 임을 이용한다.
먼저, 10억번째 제곱ㄴㄴ수가 20억보다 작음을 이용해 제곱해서 20억보다 작은 소수들을 전부 구한다.
다음으로는 백트래킹을 이용해 서로 다른 소수들을 곱해서 20억보다 작은 수가 나오는 모든 수들을 곱한 소수의 갯수의 홀짝 여부에 따라 나누어 따로 저장한다.
저장한 수들을 첫 줄의 식을 통해 1에서 N(N <= 10^9)까지의 제곱ㄴㄴ 수의 갯수를 구할 수 있다.

이 제곱ㄴㄴ수의 갯수를 0과 20억을 기준점으로 하여 갯수가 N보다 작은지 여부로 이분 탐색을 하면 N번째 제곱ㄴㄴ수를 구할 수 있다.

주요 알고리즘 : 수학, 에라토스테네스의 체, 포함 배제의 원리, 백트래킹, 이분 탐색
*/

int primes[8192];
int comodd[16384];
int oddi = 0;
int comeven[16384];
int eveni = 0;
int maxes[16] = { 0, };

int chkprime[16];
int chkp = 0;
int chki = 0;

int max(int a, int b) {
	a > b ? a : b;
}

int makeprime(int max) {
	int x, qp = 0, c = 0;
	long long int t;
	for (int i = 2; i * i < max; i++) {
		x = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				x = 0;
				break;
			}
		}
		if (x) {
			primes[qp] = (long long int)i;
			qp++;
		}
	}
	return qp;
}

//n개의 소수들 가운데 곱이 max 미만인 r개를 뽑음. t는 현재 뽑은 갯수, m은 현재까지의 곱
void track(int n, int r, int t, long long int m, int max) {
	if (r == t) {
		if (r % 2) {
			comodd[oddi] = m;
			oddi++;
		}
		else {
			comeven[eveni] = m;
			eveni++;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (primes[i] <= chkprime[chki - 1]) continue;
		if ((m * primes[i]) * (m * primes[i]) >= max) break;
		chkprime[chki] = primes[i];
		chki++;
		track(n, r, t + 1, m * primes[i], max);
		chki--;
	}
}

void makecom(int n, int max) {
	for (int i = 1; i <= 6; i++) {
		track(n, i, 0, 1, max);
		//printf("prime(%d) : %d\n", i, i % 2 ? oddi : eveni);
	}
}

int nopower(int n) {
	int x = n;
	for (int i = 0; i < oddi; i++) {
		if (n >= (comodd[i] * comodd[i])) {
			x -= n / (comodd[i] * comodd[i]);
			//printf("- %d * %d\n", comodd[i], comodd[i]);
		}
	}
	for (int i = 0; i < eveni; i++) {
		if (n >= (comeven[i] * comeven[i])) {
			x += n / (comeven[i] * comeven[i]);
			//printf("+ %d * %d(%d)\n", comeven[i], comeven[i], i);
		}
	}
	return x;
}

int main(void) {
	int primes = makeprime(2000000000);
	makecom(primes, 2000000000);
	//printf("%d %d", eveni, oddi);
	int n;
	long long int lo = 0, hi = 2000000000;
     scanf("%d", &n);
	while (hi - lo > 1) {
		if (nopower((lo + hi) / 2) >= n) {
			hi = (lo + hi) / 2;
		}
		else {
			lo = (lo + hi) / 2;
		}
	}
	printf("%d", hi);
     return 0;
}