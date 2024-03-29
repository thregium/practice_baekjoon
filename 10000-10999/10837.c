#include <stdio.h>

/*
문제 : 두 명이 K(K <= 1000)라운드동안 동전 던지기를 한다. 매 라운드마다 선공과 후공이 차례로 동전을 던지고,
앞면이 나오면 1점을 얻는다. 상대가 반드시 지게 되는 순간 게임이 끝난다면,
주어진 두 명의 점수(K <= 100000)가 끝날 때 나올 수 있는 점수인지 구한다.

해결 방법 : 두 명의 점수를 비교해서 어느 쪽이 더 큰지에 따라 경우를 나누어 처리한다.

주요 알고리즘 : 수학

출처 : 정올 2015 중1/고1번
*/

int main(void) {
	int k, c, m, n;
	scanf("%d %d", &k, &c);
	for (int i = 1; i <= c; i++) {
		scanf("%d %d", &m, &n);
		if (m > n) printf("%d\n", m - n <= k - m + 2);
		else printf("%d\n", n - m <= k - n + 1);
	}
}