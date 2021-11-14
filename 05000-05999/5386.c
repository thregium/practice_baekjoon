#include <stdio.h>

/*
문제 : S(S <= 10^9)개의 금화가 있고, 한번에 K(K <= 100)의 거듭제곱만큼 금화를 가져올 수 있다면
선공이 이길 수 있는 방법(가져가는 금화의 수)의 최솟값을 찾는다.

해결 방법 : 추가 예정

주요 알고리즘 : 수학, 게임 이론

출처 : BAPC 2011 G번
*/

int main(void) {
	int t, s, k;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%d %d", &s, &k);
		if (k & 1) printf("%d\n", s & 1);
		else {
			if (s % (k + 1) == k) printf("%d\n", k);
			else printf("%d\n", (s % (k + 1)) & 1);
		}
	}
	return 0;
}
