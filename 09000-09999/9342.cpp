#include <stdio.h>
#include <regex>
#include <string>
using namespace std;

/*
���� : ���� 200 ������ ���ڿ��� �־��� ��, �� ���ڿ��� ������ �����ϴ��� Ȯ���Ѵ�.

�ذ� ��� : ���� ǥ������ �̿��Ѵ�.

�ֿ� �˰��� : ���ڿ�, ���� ǥ����

��ó : TNPC 2013 D��
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