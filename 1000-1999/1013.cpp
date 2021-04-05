#include <stdio.h>
#include <string>
#include <regex>
using namespace std;

/*
문제 : 주어진 문자열이 "(100+1+|01)+" 라는 정규 표현식을 만족하는지 여부를 출력한다.

해결 방법 : 정규 표현식 모듈을 통해 그대로 구현한다.

주요 알고리즘 : 정규 표현식
*/

char s[256];

int main(void) {
	int t;
	regex re("(100+1+|01)+");
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		scanf("%s", s);
		printf("%s\n", regex_match(s, re) ? "YES" : "NO");
	}
}