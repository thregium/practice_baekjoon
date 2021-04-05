#include <stdio.h>
#include <string.h>

/*
문제 : 저항의 색깔이 주어질 때, 저항의 값을 구한다. 앞의 두 자리는 저항의 값, 마지막 자리는 곱할 숫자다.

해결 방법 : 각 색깔을 저장한 후, 입력받은 색깔을 확인해 저항의 값을 구한다.

주요 알고리즘 : 구현
*/

char* o[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
char s[16];

int main(void) {
	long long r = 0;
	for(int j = 0; j < 2; j++) {
		r *= 10;
		scanf("%s", s);
		for(int i = 0; i < 10; i++) {
			if(!strcmp(s, o[i])) r += i; //앞 두 자리의 값을 저장한다.
		}
	}
	scanf("%s", s);
	for(int i = 0; i < 10; i++) {
		if(!strcmp(s, o[i])) {
			for(int j = 0; j < i; j++) r *= 10; //마지막 자리에 대응하는 숫자만큼 10을 곱한다.
		}
	}
	printf("%lld", r);
	return 0;
}
