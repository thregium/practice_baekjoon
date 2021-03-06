#include <stdio.h>
/*
庚薦 : 10常 戚馬税 切尻呪 N戚 爽嬢霜 凶 嬢彊廃 薦咽 呪稽亀 蟹刊嬢 恭嬢走走 省澗(薦咽いい呪) N腰属 切尻呪研 窒径廃陥.

背衣 号狛 :
1拭辞 N猿走税 薦咽いい呪亜 N - N / (社呪^2) + N / (辞稽 陥献 砧 社呪税 咽^2) - N / (辞稽 陥献 室 社呪税 咽^2) + N / (辞稽 陥献 革 社呪税 咽^2) - ... 績聖 戚遂廃陥.
胡煽, 10常腰属 薦咽いい呪亜 20常左陥 拙製聖 戚遂背 薦咽背辞 20常左陥 拙精 社呪級聖 穿採 姥廃陥.
陥製生稽澗 拷闘掘天聖 戚遂背 辞稽 陥献 社呪級聖 咽背辞 20常左陥 拙精 呪亜 蟹神澗 乞窮 呪級聖 咽廃 社呪税 姐呪税 筈側 食採拭 魚虞 蟹刊嬢 魚稽 煽舌廃陥.
煽舌廃 呪級聖 湛 匝税 縦聖 搭背 1拭辞 N(N <= 10^9)猿走税 薦咽いい 呪税 姐呪研 姥拝 呪 赤陥.

戚 薦咽いい呪税 姐呪研 0引 20常聖 奄層繊生稽 馬食 姐呪亜 N左陥 拙精走 食採稽 戚歳 貼事聖 馬檎 N腰属 薦咽いい呪研 姥拝 呪 赤陥.

爽推 硝壱軒葬 : 呪俳, 拭虞塘什砺革什税 端, 匂敗 壕薦税 据軒, 拷闘掘天, 戚歳 貼事
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

//n鯵税 社呪級 亜錘汽 咽戚 max 耕幻昔 r鯵研 嗣製. t澗 薄仙 嗣精 姐呪, m精 薄仙猿走税 咽
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