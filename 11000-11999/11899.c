#include <stdio.h>

/*
문제 : N(N <= 50) 길이의 '('와 ')'로 이루어진 문자열이 주어질 때, 이 문자열을 괄호 문자열로 만들기 위해
추가해야 할 문자의 최소 개수를 구한다.

해결 방법 : 괄호 문자열을 이루는 문자들을 빼면 그 문자들에서 짝을 지어주는 방식으로 풀 수 있다.
괄호 문자열은 스택을 이용해 찾으면 된다.

주요 알고리즘 : 자료 구조, 스택

출처 : GA6 1번
*/

char s[64], st[128];
int top = 0;

int main(void) {
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		if (top == 0) st[top++] = s[i];
		else if (st[top - 1] != s[i]) {
			if (st[top - 1] == '(') top--;
			else st[top++] = s[i];
		}
		else st[top++] = s[i];
	}
	printf("%d", top);
}