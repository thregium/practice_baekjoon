#include <stdio.h>
#include <string.h>
#include <math.h>

/*
문제 : 두 문자열이 주어질 때, 두 문자열의 앞뒤로 아무 문자나 넣을 수 있다면
두 문자열 사이에 서로 다른 문자의 갯수를 최소 몇 개로 만들 수 있는지 출력한다.

해결 방법 : 두 문자열의 앞뒤로 같은 문자를 넣으면 서도 다른 문자의 갯수가 최소가 된다.
더 짧은 문자열을 더 긴 문자열의 앞뒤로 움직여가며 다른 문자의 갯수가 가장 적을 때의 값을 출력한다.

주요 알고리즘 : 브루트 포스, 문자열
*/

char x[64], y[64];

int main(void) {
	int s, b = 64;
	scanf("%s %s", x, y);
	int l1 = strlen(x), l2 = strlen(y);
	for(int i = 0; i <= abs(l1 - l2); i++) {
		s = 0;
		if(l1 < l2) {
			for(int j = 0; j < l1; j++) {
				if(x[j] != y[i + j]) s++;
			}
		}
		else {
			for(int j = 0; j < l2; j++) {
				if(y[j] != x[i + j]) s++;
			}
		}
		if(s < b) b = s;
	}
	printf("%d", b);
	return 0;
}
