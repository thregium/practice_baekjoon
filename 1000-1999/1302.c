#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 문자열이 주어질 때, 가장 많이 등장한 문자열을 찾는다.

해결 방법 : 모든 문자열을 입력받은 후, 정렬한다.
그 다음 정렬한 문자열을 살펴보며 다음 문자열이 등장하기 전까지 등장한 횟수를 찾고, 그 중 가장 많은 것을 출력한다.

주요 알고리즘 : 문자열, 정렬
*/

char b[1024][64];

int main(void) {
	int n, c = 0, best = 0, r = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	qsort(b, n, sizeof(char) * 64, strcmp);
	for(int i = 0; i < n; i++) {
		if(i == 0 || strcmp(b[i], b[i - 1])) {
			if(c > best) {
				best = c;
				r = i - 1;
			}
			c = 1;
		}
		else c++;
	}
	if(c > best) {
		best = c;
		r = n - 1;
	}
	printf("%s", b[r]);
	return 0;
}
