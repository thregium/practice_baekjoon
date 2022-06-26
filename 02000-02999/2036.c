#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 절댓값 10^6 이하 정수가 주어질 때, 수들을 1개 또는 2개씩 묶은 곱의 합이
될 수 있는 최댓값을 구한다.

해결 방법 : 0과 1을 중심으로 왼쪽과 오른쪽의 값들을 묶어나간 다음, 가운데 수들의 곱을 처리한다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 케이스 워크
*/

int a[103000];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
	int n, l = -1, r;
	long long res = 0;
	scanf("%d", &n);
	r = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp1);
	for (int i = 0; i < n - 1; i += 2) {
		if (a[i] <= 0 && a[i + 1] <= 0) res += (long long)a[i] * a[i + 1];
		else break;
		l = i + 1;
	}
	for (int i = n - 1; i > l + 1; i -= 2) {
		if (a[i] > 1 && a[i - 1] > 1) res += (long long)a[i] * a[i - 1];
		else break;
		r = i - 1;
	}
	for (int i = l + 1; i < r; i++) {
		res += a[i];
	}
	printf("%lld", res);
	return 0;
}
