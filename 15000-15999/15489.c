#include <stdio.h>

/*
문제 : 파스칼의 삼각형의 R행 C열에서 W(R + W, C + W <= 30) 칸 크기의 삼각형 안에 있는 수들의 합을 구한다.

해결 방법 : 직접 파스칼의 삼각형을 구하고 삼각형 안의 수들을 더하면 된다.

주요 알고리즘 : 수학, 조합론, DP

출처 : koi4u 2008_05 A번
*/

long long mem[32][32];

int main(void) {
	int r, c, w;
	long long res = 0;
	mem[0][0] = 1;
	for (int i = 1; i <= 30; i++) {
		mem[i][0] = 1;
		for (int j = 1; j <= 30; j++) {
			mem[i][j] = mem[i - 1][j] + mem[i - 1][j - 1];
		}
	}
	scanf("%d %d %d", &r, &c, &w);
	r--, c--;

	for (int i = 0; i < w; i++) {
		for (int j = 0; j <= i; j++) res += mem[i + r][j + c];
	}
	printf("%lld", res);
}