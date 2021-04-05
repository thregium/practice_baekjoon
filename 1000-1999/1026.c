#include <stdio.h>
#include <stdlib.h>

/*
문제 : 정수 배열 A와 B가 있을 때, 배열 A를 재배치해서 Ai * Bi의 합을 최소로 할 때의 값을 구한다, (Ai, Bi >= 0)

해결 방법 : A만 재배치하더라도 A와 B를 재배치할 때의 모든 대응관계를 만들 수 있다.
따라서, A와 B를 유리한 순서대로 배치하면 된다. 그 방법은 A는 오름차순, B는 내림차순으로 정렬하는 것이다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

int a[64], b[64];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
	int n, s = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	qsort(a, n, sizeof(int), cmp1);
	qsort(b, n, sizeof(int), cmp2);
	for(int i = 0; i < n; i++) s += a[i] * b[i];
	printf("%d", s);
	return 0;
}
