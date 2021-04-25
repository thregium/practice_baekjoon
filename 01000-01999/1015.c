#include <stdio.h>

/*
문제 : 수열 A가 주어질 때 A를 비내림차순으로 만드는 순열 가운데 번호를 사전 순으로 했을 때 가장 앞서는 것을 찾는다.

해결 방법 : A를 작은 순으로 선택한다. 같은 것이 있다면 앞에 있는 것을 먼저 선택한다.
이후 선택한 순서대로 번호를 매긴다.

주요 알고리즘 : 그리디 알고리즘
*/

int a[64], b[64], c[64];

int main(void) {
	int n, s, t;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++) {
		s = 1234; //최댓값보다 큰 값
		t = -1;
		for(int j = 0; j < n; j++) {
			if(c[j]) continue;
			if(a[j] < s) {
				t = j; //가장 작은 값의 번호
				s = a[j];
			}
		}
		if(t < 0) return 1; //에러 확인용
		b[t] = i;
		c[t] = 1;
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
	return 0;
}
