#include <stdio.h>
#include <stdlib.h>

/*
문제 : 1번 지점부터 N(N <= 2000)번 지점까지 차례로 움직이며 박스를 배송한다. 한번에 최대 C(C <= 10000)개 까지만
배송 가능하다면 배송 가능한 최대 개수를 구한다. 역방향으로 움직일 수는 없고, 각 배송은 정방향으로만 이루어진다.

해결 방법 : 배송의 끝 지점을 기준으로 정렬하는 것이 최적임을 알 수 있다. 각 배송마다 가능한 최대한의 박스를
배송하고 그때의 박스 개수를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 정올 2013 초2번
*/

int cap[10240], box[10240][3];

int big(int a, int b) {
	return a > b ? a : b;
}

int small(int a, int b) {
	return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
	int ai = *((int*)a + 1);
	int bi = *((int*)b + 1);
	if(ai != bi) return ai > bi ? 1 : -1;
	ai = *(int*)a;
	bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main() {
	int n, c, m, r = 0, x, t;
	scanf("%d %d %d", &n, &c, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &box[i][0], &box[i][1], &box[i][2]);
	}
	qsort(box, m, sizeof(int) * 3, cmp1);
	for (int i = 0; i < m; i++) {
		x = 0;
		for (int j = box[i][0]; j < box[i][1]; j++) x = big(x, cap[j]);
		t = small(box[i][2], c - x);
		for (int j = box[i][0]; j < box[i][1]; j++) cap[j] += t;
		r += t;
	}
	printf("%d", r);
}