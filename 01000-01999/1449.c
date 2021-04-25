#include <stdio.h>
#include <stdlib.h>

/*
문제 : N개의 구멍을 L 길이의 테이프로 막아야 한다고 할 때, 모든 구멍을 막기 위해 필요한 최소한의 테이프 수를 출력한다.

해결 방법 : 구멍의 위치를 정렬한 다음 막아야 하는 가장 왼쪽 구멍부터 순서대로 막으면 최적값이 나온다.

주요 알고리즘 : 그리디 알고리즘
*/

int a[1024];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
	int n, l, x, r = 1;
	scanf("%d %d", &n, &l);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp1);
	x = a[0];
	for(int i = 1; i < n; i++) {
		if(a[i] >= x + l) {
			r++;
			x = a[i];
		}
	}
	printf("%d", r);
	return 0;
}
