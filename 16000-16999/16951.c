#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 1000)개의 탑의 높이(<= 1000)가 주어질 때, 인접한 두 탑의 높이 차이를 K(K <= 1000)으로 만들기 위해
높이를 바꿔야 하는 탑의 개수를 구한다. 단, 높이는 반드시 1 이상이어야 한다.

해결 방법 : 2중 for문을 사용하여 기준점과 그 기준점에서 바꿔야 하는 탑의 수를 계산하고, 그 중 가장 작은 값을 구한다.

주요 알고리즘 : 브루트 포스
*/

int a[1024];

int main(void) {
	int n, k, r = INF, t, f;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		t = a[i] - k * i, f = 0;
		if (t < 1) continue;
		for (int j = 0; j < n; j++) {
			if (a[j] != t) f++;
			t += k;
		}
		if (f < r) r = f;
	}
	printf("%d", r);
	return 0;
}