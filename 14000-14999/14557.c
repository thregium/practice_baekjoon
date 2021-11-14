#include <stdio.h>

/*
문제 : 짝맞추기 게임에서 카드가 R * C(R, C <= 10)장 있다면 카드를 최소, 최대 몇 번 뒤집어야 하는지 구한다.

해결 방법 : 최소는 R * C / 2이고, 최대는 최솟값에 따라 식을 통해 구할 수 있다.

주요 알고리즘 : 수학

출처 : KAIST 2017S G번
*/

int main(void) {
	int r, c, lo, hi;
	scanf("%d %d", &r, &c);
	lo = r * c / 2;
	hi = (lo > 2) ? (lo - 2) * 4 : 0;
	hi += ((lo >= 2) ? 2 : 1) * 3;
	hi /= 2;

	printf("%d %d", lo, hi);

	return 0;
}