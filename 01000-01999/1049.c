#include <stdio.h>
#include <stdlib.h>

/*
문제 : 기타줄을 N개 사야 한다. M개의 브랜드에서 기타줄을 6개 들이 묶음과 낱개로 파는 가격이 나올 때,
기타줄을 사는데 필요한 최소 비용을 구한다. (N <= 100, M <= 50)

해결 방법 : 우선, 같은 갯수로 파는 기타줄 가운데에는 가장 싼 것을 사는 것이 좋으므로
정렬을 통해 6개 묶음과 낱개에서 각각 가장 싼 것을 찾는다. 찾은 이후에는 6개 단위로 필요한 기타줄의 수와
단가를 확인해가며 유리한 쪽으로 계속 구매한다.

주요 알고리즘 : 그리디 알고리즘, 수학, 정렬
*/

int a[64], b[64];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
	int n, m, r = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	qsort(a, m, sizeof(int), cmp1); //묶음을 가장 싼 순으로 정렬
	qsort(b, m, sizeof(int), cmp1); //낱개를 가장 싼 순으로 정렬
	while(n > 0) {
		if(n > 6) {
			if(a[0] < b[0] * 6) r += a[0]; //묶음이 더 싼 경우
			else r += b[0] * 6; //낱개 6개가 더 싼 경우
			n -= 6;
		}
		else {
			if(a[0] < b[0] * n) r += a[0]; //묶음이 더 싼 경우
			else r += b[0] * n; //낱개 남은 수만큼이 더 싼 경우
			n = 0;
		}
	}
	printf("%d", r);
	return 0;
}
