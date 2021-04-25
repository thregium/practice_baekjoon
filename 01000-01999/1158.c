#include <stdio.h>

/*
문제 : N과 K가 주어질 때 <N, K> 요세푸스 순열을 출력한다. (N, K <= 1000)

해결 방법 : 배열을 한 칸씩 살펴보며 아직 제거하지 않은 수를 만나면 카운트를 1씩 증가시키다
K번째 원소가 나오면 해당 원소를 제거시키고 카운트를 0으로 돌린다. 이 행동을 계속 반복하며
제거한 순서대로 순열을 출력한다.

주요 알고리즘 : 구현
*/

int kk[5120], m[5120];

int main(void) {
	int n, k, t = 0, p = 0;
	scanf("%d %d", &n, &k);
	for(int i = 0; p < n; i = (i + 1) % n) {
		if(kk[i]) continue;
		t++;
		if(t == k) {
			t = 0;
			kk[i] = 1;
			m[p++] = i + 1;
		}
	}
	
	printf("<");
	for(int i = 0; i < n - 1; i++) printf("%d, ", m[i]);
	printf("%d>", m[n - 1]);
	return 0;
}
