#include <stdio.h>

/*
문제 : 문자열에서 패턴으로 ?를 넣으면 해당 칸에 어떠한 글자든 올 수 있고, 다른 글자가 있는 경우 해당 글자만 올 수 있다.
문자열 N개(N <= 50)가 주어질 때 해당 문자열들에 전부 해당하는 패턴 가운데 가장 ? 갯수가 적은 것을 구한다.

해결 방법 : 모든 문자열에서 해당 칸에 들어가는 문자가 같다면 해당 글자를 출력하고, 같지 않은 문자가 하나라도 있다면 ?를 출력한다.

주요 알고리즘 : 문자열
*/

char name[64][64];

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", name[i]);
	}
	for(int i = 0; name[0][i]; i++) {
		int r = 1;
		for(int j = 1; j < n; j++) if(name[j][i] != name[j - 1][i]) r = 0;
		if(r) printf("%c", name[0][i]);
		else printf("?");
	}
	return 0;
}
