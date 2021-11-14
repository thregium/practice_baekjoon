#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 10000)개의 정수(-1000 <=, <= 1000)가 주어질 때, 정수 2개 또는 3개의 곱으로 가능한 가장 큰 수를 구한다.

해결 방법 : 정수 2개에서 가능한 경우는 음수 * 음수, 양수 * 양수이고, 3개에서는 음수 * 음수 * 양수, 양수 * 양수 * 양수이다.
수를 정렬한 다음 이러한 경우들을 전부 찾아서 가장 큰 것을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 케이스 워크

출처 : Daejeon 2017I H번
*/

int a[10240];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
	int n, r = -INF;
	scanf("%d", &n);
	if (n < 3) return 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp1);
	if (r < a[0] * a[n - 1] * a[n - 2]) r = a[0] * a[n - 1] * a[n - 2];
	if (r < a[0] * a[1] * a[2]) r = a[0] * a[1] * a[2];
	if (r < a[0] * a[1]) r = a[0] * a[1];
	if (r < a[n - 1] * a[n - 2]) r = a[n - 1] * a[n - 2];
	printf("%d", r);
}