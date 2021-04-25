#include <stdio.h>

/*
문제 : 1, 2, 2, 3, 3, 3... 으로 이어지는 수열이 있을 때, 이 수열의 A번째에서 B번째 까지 수의 합을 구한다.(A, B <= 1000)

해결 방법 : A와 B의 범위가 작으므로 수현을 구현하고 직접 합을 구해 해결할 수 있다.

주요 알고리즘 : 수학, 구현
*/

int m[1024];

int main(void) {
	int a, b, c = 1, d = 0, r = 0;
	scanf("%d %d", &a, &b);
	for(int i = 1; i <= b; i++) {
		m[i] = c;
		d++;
		if(c == d) {
			c++;
			d = 0;
		}
	}
	for(int i = a; i <= b; i++) r += m[i];
	printf("%d", r);
	return 0;
}
