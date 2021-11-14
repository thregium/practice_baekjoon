#include <stdio.h>
#include <regex>
#include <string>
using namespace std;

/*
문제 : 길이 200 이하의 문자열이 주어질 때, 이 문자열이 조건을 만족하는지 확인한다.

해결 방법 : 정규 표현식을 이용한다.

주요 알고리즘 : 문자열, 정규 표현식

출처 : TNPC 2013 D번
*/

char s[256];

int main(void) {
	int t;
	scanf("%d", &t);
	regex rgx("(^[A-F]?A+F+C+[A-F]?$)");
	string str;
	for (int tt = 0; tt < t; tt++) {
		scanf("%s", s);
		str.assign(s);
		if (regex_match(str, rgx)) printf("Infected!\n");
		else printf("Good\n");
	}
}