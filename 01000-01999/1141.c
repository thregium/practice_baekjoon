#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : N(N <= 50)개의 소문자로 이루어진 50자 이하의 문자열이 주어질 때, 각 문자열끼리 접두사인 관계가
없는 가장 큰 집합의 크기를 구한다.

해결 방법 : 각 문자열을 정렬하면 서로 접두사인 관계인 집합은 서로 인접하게 된다는 점을 이용한다.
문자열을 정렬한 다음, 처음에는 N을 집합의 크기로 둔다. 인접한 집합에서 접두사 관계가 나올 때 마다 집합의 크기를
1씩 빼나가서 나온 집합의 크기가 답이 된다.

주요 알고리즘 : 문자열, 정렬
*/

char s[64][64];

int main(void) {
	int n, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}

	qsort(s, n, sizeof(char) * 64, strcmp);
	r = n;
	for (int i = 0; i < n - 1; i++) {
		if (strstr(s[i + 1], s[i]) == s[i + 1]) r--;
	}
	printf("%d", r);

	return 0;
}