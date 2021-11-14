#include <stdio.h>

/*
문제 : 두 자연수 A, B가 있을 때 A^2 - B^2 = G인 자연수 G(G <= 100000)가 주어질 때, A로 가능한 것을 모두 구한다.

해결 방법 : 0부터 G까지의 모든 제곱수를 저장한 다음, 투 포인터 알고리즘을 이용하면 된다.

주요 알고리즘 : 수학, 투 포인터
*/

long long sq[103000];
int res[103000];

int main(void) {
	int g, p = 0;
	scanf("%d", &g);
	for (long long i = 0; i <= g; i++) {
		sq[i] = i * i;
	}
	int s = 1, e = 1;
	while (1) {
		if (e == g + 1) break;
		else if (sq[e] - sq[s] > g) s++;
		else if (sq[e] - sq[s] < g) e++;
		else if (sq[e] - sq[s] == g) {
			res[p++] = e;
			s++;
		}
	}
	if (p == 0) {
		printf("-1");
		return 0;
	}
	for (int i = 0; i < p; i++) {
		printf("%d\n", res[i]);
	}
}