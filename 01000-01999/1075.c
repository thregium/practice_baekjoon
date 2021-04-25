#include <stdio.h>

/*
문제 : 정수 N의 마지막 두 자리를 바꿔서 F로 나누어 떨어지는 가장 작은 수를 출력한다.

해결 방법 : 정수 N의 마지막 두 자리를 0으로 만든 다음, 0부터 99까지 바꿔가며 F로 나누어 떨어지는지 확인하고, 가장 작은 값을 출력한다.

주요 알고리즘 : 브루트 포스
*/

int main(void) {
	int n, f;
	scanf("%d %d", &n, &f);
	n -= n % 100;
	for(int i = 0; i < 100; i++) {
		if((n + i) % f == 0) {
			printf("%02d", i);
			break;
		}
	}
	return 0;
}
