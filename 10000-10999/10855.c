#include <stdio.h>

/*
문제 : 주어진 길이 N(N <= 1024)의 배열이 정렬된 상태인지 확인한다.

해결 방법 : 매번 이전 값과 비교해 이전 값보다 작은 경우가 있는지 확인한다. 그러한 경우가 있다면 정렬된 상태가 아니고,
없다면 정렬된 상태이다.

주요 알고리즘 : 구현

출처 : GCPC 2015 G번
*/

int main(void) {
	int n, a, l = -1, r = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (a < l) r = 0;
		l = a;
	}
	printf("%s", r ? "yes" : "no");
	return 0;
}
