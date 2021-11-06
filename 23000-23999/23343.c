#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 6자리 이하의 두 수 A, B가 주어질 때, A - B의 값을 구한다. 단, A나 B에 숫자가 아닌 값이 있다면 NaN을 출력한다.

해결 방법 : 두 수를 문자열로 입력받은 뒤 isdigit()함수를 통해 숫자가 아닌 값은 없는지 확인한다.
숫자가 아닌 값이 있다면 NaN을 출력하고, 없다면 strtoll()함수를 통해 A - B의 값을 구하면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : TOPC 2021 J번
*/

char a[16], b[16];

int main(void) {
	int r = 1;
	scanf("%s %s", a, b);
	for(int i = 0; a[i]; i++) {
		if(!isdigit(a[i])) r = 0;
	}
	for(int i = 0; b[i]; i++) {
		if(!isdigit(b[i])) r = 0;
	}
	if(r == 0) {
		printf("NaN");
	}
	else printf("%lld", strtoll(a, NULL, 10) - strtoll(b, NULL, 10));
	return 0;
}
