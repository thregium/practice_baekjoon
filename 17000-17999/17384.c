#include <stdio.h>

/*
문제 : N(N <= 10^6) 크기의 대진표를 공정하게 만드는 방법 가운데 오름차순으로 마지막 순서에 있는 대진표를 출력한다.
공정한 대진표는 모든 사람의 경기 수가 많아야 1 차이 나는 경우이다.

해결 방법 : 우선 대진표의 크기를 정한다. N 이상이며 가장 작은 2의 거듭제곱 꼴이 되면 된다.
각 대진표에서는 먼저 오른쪽 대진의 절반을 채워넣을 수 있는지 확인한다. 가능하다면 그렇게 하고,
나머지 팀들은 왼쪽에 배정한다. 불가능한 경우에는 왼쪽 대진을 채우고 오른쪽 대진에 나머지를 배정하면 된다.

주요 알고리즘 : 분할 정복, 재귀, 구성적

출처 : UCPC 2019 L번
*/

void rec(int s, int e, int rem) {
	if (s == e) {
		printf("%c", rem ? '#' : '.');
		return;
	}
	int l = e - s + 1, m = (s + e) >> 1, t = 1;
	if (rem <= (l >> 1)) {
		rec(s, m, rem); rec(m + 1, e, 0);
	}
	else {
		while (t * 2 <= rem - t * 2 && t * 2 <= e - m) t <<= 1;
		if (rem - t > m - s + 1) t = rem - (m - s + 1);
		rec(s, m, rem - t); rec(m + 1, e, t);
	}
}

int main(void) {
	int n, e = 1;
	scanf("%d", &n);
	while (e < n) e <<= 1;
	rec(1, e, n);
}
