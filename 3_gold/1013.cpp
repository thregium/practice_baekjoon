#include <stdio.h>
#include <string>
#include <regex>
using namespace std;

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