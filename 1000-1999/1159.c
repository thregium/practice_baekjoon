#include <stdio.h>

/*
문제 : 문자열 N(N <= 150)개가 주어질 때, 5개 이상의 문자열에서 맨 앞 글자인 문자가 있는지 확인하고,
있으면 해당하는 문자를 전부 출력한다.

해결 방법 : 모든 문자에 시작하는 문자의 갯수를 센 후, 문자들을 순서대로 지나가며 5 이상이 저장된 경우를 전부 출력한다.

주요 알고리즘 : 문자열

출처 : COCI 2013-2014 #1 1번
*/

char p[32], a[32];

int main(void) {
	int n, c = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", p);
		a[p[0] - 'a']++;
	}
	for(int i = 0; i < 26; i++) {
		if(a[i] >= 5) {
			printf("%c", i + 'a');
			c++;
		}
	}
	if(!c) printf("PREDAJA");
	return 0;
}
