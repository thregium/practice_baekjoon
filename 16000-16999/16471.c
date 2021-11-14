#include <stdio.h>
#include <stdlib.h>

/*
문제 : 두 명이 N(N < 100000, 홀수)개의 음이 아닌 정수(<= 100000)가 적힌 카드를 갖고 있다.
이때, 매 라운드마다 서로 카드를 내서 더 작은 수가 나온 사람이 1점을 얻고, 더 많은 점수를 얻은 사람이 이기는 게임을 한다면
첫 번째 사람이 이길 수 있는지 구한다.

해결 방법 : 두 명의 카드를 정렬한 다음, 첫 사람의 카드를 큰 것부터 보면서 상대의 카드 가운데 더 큰 것이 있는지 살피고,
있다면 그 카드를 제외한 다음 카드를 보는 식으로 확인하며 첫 번째 사람의 카드가 더 작은 것이 N / 2개보다 많이 있는지
확인하면 된다. 그러한 경우 이길 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 투 포인터

출처 : 한양대 5회A D번
*/

int a[103000], b[103000];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}


int main() {
	int n, r = 0, ap, bp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	qsort(a, n, sizeof(int), cmp1);
	qsort(b, n, sizeof(int), cmp1);
	ap = n - 1, bp = n - 1;
	while (ap >= 0) {
		while (ap >= 0 && a[ap] >= b[bp]) ap--;
		if (ap >= 0) {
			ap--;
			bp--;
			r++;
		}
	}
	if (r >= (n + 1) >> 1) printf("YES");
	else printf("NO");
}