#include <stdio.h>
//1에서 N까지의 제곱ㄴㄴ수 : N - N / (소수^2) + N / (서로 다른 두 소수의 곱^2) - N / (서로 다른 세 소수의 곱^2) + N / (서로 다른 네 소수의 곱^2) - ...

long long int primes[65536];
long long int comodd[65536];
long long int oddi = 0;
long long int comeven[65536];
long long int eveni = 0;
long long int maxes[16] = { 0, };

long long int chkprime[16];
long long int chki = 0;

int max(int a, int b) {
	a > b ? a : b;
}

int makeprime(long long int max) {
	int x, qp = 0, c = 0;
	long long int t;
	for (long long int i = 2; i * i < max; i++) {
		x = 1;
		for (long long int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				x = 0;
				break;
			}
		}
		if (x) {
			primes[qp] = i;
			qp++;
		}
	}
	return qp;
}

//n개의 소수들 가운데 곱이 max 미만인 r개를 뽑음. t는 현재 뽑은 갯수, m은 현재까지의 곱
void track(int n, int r, int t, long long int m, long long int max) {
	if (primes[0] != 2) {
		return;
	}
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
		if ((m * primes[i]) * (m * primes[i]) >= max || m * primes[i] > 2147483647) break;
		chkprime[chki] = primes[i];
		chki++;
		track(n, r, t + 1, m * primes[i], max);
		chki--;
	}
}

void makecom(int n, long long int max) {
	for (int i = 1; i <= 8; i++) {
		track(n, i, 0, 1, max);
		//printf("prime(%d) : %d\n", i, i % 2 ? oddi : eveni);
	}
}

long long int nopower(long long int n) {
	long long int x = n;
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
	int primec = makeprime(30000000000);
	makecom(primec, 30000000000);
	//printf("%d %d", eveni, oddi);
	long long int n;
	long long int lo = 0, hi = 100000000000;
	scanf("%lld", &n);
	while (hi - lo > 1) {
		if ((lo + hi) / 2 - nopower((lo + hi) / 2) >= n) {
			hi = (lo + hi) / 2;
		}
		else {
			lo = (lo + hi) / 2;
		}
	}
	printf("%lld", hi);
	return 0;
}