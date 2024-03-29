#include <stdio.h>

/*
문제 : 1부터 N(N <= 300000)까지의 수로 이루어진 순열에서 각 수들을 맨 앞으로 빼내는 것이 가능하다면
이 순열을 정렬하기 위해 빼내야 하는 횟수를 구한다.

해결 방법 : 뒤에서부터 규칙에 맞지 않는 것을 빼내는 것이 최적이다. 이는 뒤에서부터 역순으로 보았을 때,
N부터 1씩 내려가는 가장 긴 부분 수열의 길이와 같다.

주요 알고리즘 : 그리디 알고리즘

출처 : COCI 10/11#2 4번
*/

int a[327680];

int main(void) {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	x = n;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] == x) x--;
	}
	printf("%d", x);
	return 0;
}