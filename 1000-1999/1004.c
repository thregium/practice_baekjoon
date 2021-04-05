#include <stdio.h>

/*
문제 : 출발점(x1, y1)과 도착점(x2, y2)이 주어지고, 원들의 정보(cx, cy, r)가 주어질 때,
출발점에서 도착점까지 이동하려면 원의 둘레를 최소 몇 회 지나야 하는지를 출력한다.

해결 방법 : 출발점과 도착점이 같은 원 안에 있다면 해당 원의 둘레를 지날 필요가 없다.
하지만, 출발점이나 도착점 중 하나만 원 안에 있는 경우에는 반드시 해당 원의 둘레를 지나야 한다.
따라서, 하나만 원 안에 있는 원의 수를 전부 구하면 된다.

주요 알고리즘 : 기하학
*/

int main(void) {
	int t, x1, y1, x2, y2, n, cx, cy, r, a, res;
	scanf("%d", &t);
	for(int tt = 0; tt < t; tt++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);
		res = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d %d %d", &cx, &cy, &r);
			a = 0;
			if((y1 - cy) * (y1 - cy) + (x1 - cx) * (x1 - cx) < r * r) a++; //출발점이 원 안에 있는 경우
			if((y2 - cy) * (y2 - cy) + (x2 - cx) * (x2 - cx) < r * r) a++; //도착점이 원 안에 있는 경우
			res += a % 2; //a가 1인 경우에만 결괏값에 추가됨
		}
		printf("%d\n", res);
	}
	return 0;
}
