#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : 알파벳 대문자로 이루어진 단어들이 주어질 때, 각 글자를 서로 다른 문자로 치환하는 경우
얻을 수 있는 최대 합을 구한다.

해결 방법 : 각 자릿수들을 위치별로 10^x로 저장해 더한 다음, 큰 값부터 순서대로 정렬한다.
그 다음, 순서대로 9, 8, 7 ... 순으로 숫자들을 할당하고 각 수에 곱해서 더하면 최댓값을 얻을 수 있다.

주요 알고리즘 : 그리디 알고리즘, 수학
*/

char s[16];
int a[26];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
	int n, x, r = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", s);
		x = 1;
		for(int j = strlen(s) - 1; j >= 0; j--) {
			a[s[j] - 'A'] += x;
			x*= 10;
		}
	}
	qsort(a, 26, sizeof(int), cmp1);
	for(int i = 0; i < 10; i++) {
		r += a[i] * (9 - i);
	}
	printf("%d", r);
	return 0;
}
