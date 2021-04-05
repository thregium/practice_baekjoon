#include <stdio.h>

/*
문제 : N명의 사람들이 토너먼트 형식으로 서로 인접한 사람들끼리 순서대로 붙는다. 이때 마지막 한 명이 남는 경우 부전승 처리한다.
두 사람의 번호가 주어질 때, 계속 이긴다면 몇 라운드에서 이기게 되는지 출력한다.

해결 방법 : 매 라운드마다 진출시 새로 얻게 되는 번호는 (현재 번호 + 1) / 2이다.
또한, 토너먼트이기 때문에 둘은 언젠간 반드시 만나게 된다. 따라서, 둘이 같은 수가 될 때 까지 해당 연산을 반복하면 된다.

주요 알고리즘 : 수학
*/

int main(void) {
	int n, l, k, r = 0;
	scanf("%d %d %d", &n, &l, &k);
	for(; l != k; r++) {
		l = (l + 1) / 2;
		k = (k + 1) / 2;
	}
	printf("%d", r);
	return 0;
}
