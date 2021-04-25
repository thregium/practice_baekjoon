#include <stdio.h>

/*
문제 : N(N <= 20)개의 정수로 이루어진 수열이 있을 때, 모든 원소가 이 수열에 포함되고,
원소의 합이 S가 되는 부분집합의 수를 구한다.

해결 방법 : S의 제한이 작으므로 모든 부분집합을 살펴보며 합이 S가 되는지 구한다.

주요 알고리즘 : 브루트 포스
*/

int a[32], f[32];
int n, s, r = 0;

void track(int c, int x, int l) {
	if(c == x) {
		int a = 0;
		for(int i = 0; i < c; i++) a += f[i];
		if(a == s) r++;
		return;
	}
	
	for(int i = l + 1; i < n; i++) {
		f[x] = a[i];
		track(c, x + 1, i);
	}
}

int main(void) {
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) track(i, 0, -1);
	printf("%d", r);
	return 0;
}
