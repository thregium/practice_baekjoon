#include <stdio.h>
#include <math.h>

/*
문제 : 0~9 사이의 숫자 가운데 일부가 없는 상태에서 숫자 버튼과 +, - 버튼만으로
채널 100번에서 N(N <= 500000)번으로 이동하기 위해 필요한 최소한의 버튼 누름 횟수를 출력한다.

해결 방법 : N의 제한이 크지 않으므로 N * 2 이하의 가능한 모든 조합에 대해 버튼을 누르는 횟수를 확인해서
그 중 가장 적은 것을 출력하면 된다.

주요 알고리즘 : 브루트 포스
*/

int broken[10], ch[8];
int n, m, s;

int small(int a, int b) {
	return a < b ? a : b;
}

void track(int p, int r) {
	//리모컨으로 만들 수 있는 모든 조합을 확인, p : 누를 버튼 수, r : 누른 버튼 수
	if(p == r) {
		int res = 0;
		for(int i = 0; i < r; i++) res = res * 10 + ch[i]; 
		s = small(s, abs(res - n) + r); //결괏값을 확인 후 더 작은지 확인
		return;
	}
	for(int i = 0; i < 10; i++) {
		if(broken[i]) continue;
		ch[r] = i;
		track(p, r + 1);
	}
}

int main(void) {
	int x;
	scanf("%d%d", &n, &m);
	s = n > 100 ? n - 100 : 100 - n;
	for(int i = 0; i < m; i++) {
		scanf("%d", &x);
		broken[x] = 1;
	}
	for(int i = 1; i <= 6; i++) track(i, 0);
	printf("%d", s);
	return 0;
}
