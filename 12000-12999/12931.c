#include <stdio.h>

/*
문제 : N(N <= 50)개의 음이 아닌 정수(<= 1000)로 이루어진 수열이 있다. 모든 수가 0인 수열에서 이 수열을 다음 연산을
통해 만들 때, 가장 빨리 만들 때의 연산 횟수를 구한다.
1. 수열의 어떤 한 수에 1을 더한다.
2. 수열의 모든 수에 2를 곱한다.

해결 방법 : 역순으로 생각한다. 만약 각 수가 짝수인 경우 2로 나누고, 홀수인 경우 1을 빼고 2로 나눈다.
이를 모든 수가 0이 될 때 까지 반복하며 그동안 시행한 연산 횟수를 구한다.

주요 알고리즘 : 그리디 알고리즘
*/

int b[64];

int main(void) {
	int n, r = 0, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}
	while (1) {
		t = 1;
		for (int i = 0; i < n; i++) {
			if (b[i] & 1) r++;
			b[i] >>= 1;
			if (b[i]) t = 0;
		}
		if (!t) r++;
		else break;
	}
	printf("%d", r);
	return 0;
}