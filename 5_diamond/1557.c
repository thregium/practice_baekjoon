#include <stdio.h>
/*
���� : 10�� ������ �ڿ��� N�� �־��� �� ��� ���� ���ε� ������ �������� �ʴ�(����������) N��° �ڿ����� ����Ѵ�.

�ذ� ��� :
1���� N������ ������������ N - N / (�Ҽ�^2) + N / (���� �ٸ� �� �Ҽ��� ��^2) - N / (���� �ٸ� �� �Ҽ��� ��^2) + N / (���� �ٸ� �� �Ҽ��� ��^2) - ... ���� �̿��Ѵ�.
����, 10���° ������������ 20�ﺸ�� ������ �̿��� �����ؼ� 20�ﺸ�� ���� �Ҽ����� ���� ���Ѵ�.
�������δ� ��Ʈ��ŷ�� �̿��� ���� �ٸ� �Ҽ����� ���ؼ� 20�ﺸ�� ���� ���� ������ ��� ������ ���� �Ҽ��� ������ Ȧ¦ ���ο� ���� ������ ���� �����Ѵ�.
������ ������ ù ���� ���� ���� 1���� N(N <= 10^9)������ �������� ���� ������ ���� �� �ִ�.

�� ������������ ������ 0�� 20���� ���������� �Ͽ� ������ N���� ������ ���η� �̺� Ž���� �ϸ� N��° ������������ ���� �� �ִ�.

�ֿ� �˰��� : ����, �����佺�׳׽��� ü, ���� ������ ����, ��Ʈ��ŷ, �̺� Ž��
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

//n���� �Ҽ��� ��� ���� max �̸��� r���� ����. t�� ���� ���� ����, m�� ��������� ��
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