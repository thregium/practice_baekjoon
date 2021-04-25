#include <stdio.h>

/*
문제 : N(N <= 100)명의 사람들이 순서대로 원하는 자리에 앉으려 할 때, 자리에 사람이 없다면 자리에 앉히고
있다면 돌려보낸다. 돌려보내야 하는 사람의 수를 구한다.

해결 방법 : 문제에서 말한 대로 구현한다.

주요 알고리즘 : 구현
*/

int arr[128];

int main(void) {
	int n, x, r = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &x);
		if(!arr[x]) {
			arr[x] = 1;
		}
        else r++;
	}
	printf("%d", r);
	return 0;
}
