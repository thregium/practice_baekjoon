#include <stdio.h>

/*
문제 : 길이 100 이하의 괄호 문자열 + 숫자로 이루어진 문자열에서 가장 점수가 높은 숫자의 점수를 구한다.
점수는 둘러싼 괄호에 따라 달라지는데 소괄호인 경우 1점, 중괄호인 경우 2점, 대괄호인 경우 3점이고, 중첩되면 합쳐진다.

해결 방법 : 현재의 점수를 확인해 나가면서 숫자가 나올 때의 점수가 가장 높은 것을 구하면 된다.

주요 알고리즘 : 구현

출처 : 경찰대 2019 E번
*/

char s[128];

int big(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int r = 0, t = 0;
	scanf("%s", s);

	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') t += 1;
		else if (s[i] == '{') t += 2;
		else if (s[i] == '[') t += 3;
		else if (s[i] == ')') t -= 1;
		else if (s[i] == '}') t -= 2;
		else if (s[i] == ']') t -= 3;
		else r = big(r, t);
	}
	printf("%d", r);

	return 0;
}