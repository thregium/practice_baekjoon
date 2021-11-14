#include <stdio.h>

/*
문제 : N(N <= 256)명이 참가하는 토너먼트에서 순서를 유지하며 대진별 순위 차이가 최소가 되도록 하는 대진의
순위 차이 합을 구한다. 순위는 1 이상 N 이하고 동순위는 없다.

해결 방법 : 순위가 낮은 사람부터 인접한 위치의 순위가 더 낮은 사람과 대진을 붙인다.
그리고 그 사람을 배열에서 제거하고 이를 1명이 될 때 까지 반복하면 된다.

주요 알고리즘 : 그리디 알고리즘
*/

int rnk[256];

int big(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n, r = 0, worst;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &rnk[i]);
	}

	while (n > 1) { 
		worst = -1;
		for (int i = 0; i < n; i++) {
			if (rnk[i] == n) worst = i;
		}
		if (worst < 0) return 1;

		if (worst == n - 1) r += rnk[worst] - rnk[worst - 1];
		else if (worst == 0) r += rnk[worst] - rnk[worst + 1];
		else r += rnk[worst] - big(rnk[worst - 1], rnk[worst + 1]);

		for (int i = worst; i < n; i++) {
			rnk[i] = rnk[i + 1];
		}
		n--;
	}

	printf("%d", r);
}