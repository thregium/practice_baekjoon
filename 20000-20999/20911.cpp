#include <stdio.h>
#include <set>
#include <map>
using namespace std;

/*
문제 : 좌표평면 상에 M개의 비석과 C(M, C <= 1000)개의 교회가 있다. 같은 X축 또는 Y축에 비석이 2개 이상 있는 경우 교회가
강화된다고 한다. 이때, 새로 비석 하나를 지었을 때, 강화된 교회를 가장 많이 만들 수 있는 비석의 좌표를 구한다.
비석은 다른 비석이나 교회와 겹칠 수 있다.

해결 방법 : 각 X축과 Y축별로 비석의 수를 구한다. 그 다음으로 같은 방법으로 교회의 수를 구하되, 이미 강화된 교회는 제외한다.
그 다음으로는 강화되지 않은 교회가 가장 많은 X축과 Y축을 찾아 그 좌표에서 강화된 교회의 수를 구하면 된다.
이때, 교차점에 있는 교회를 두 번 세지 않도록 주의한다.

주요 알고리즘 : 브루트 포스?

출처 : GCPC 2020 K번
*/

map<int, int> mx, my, cx, cy;
set<pair<int, int>> cs;

int main() {
	int m, c, x, y, bx = 0, by = 0, r = 0, cur;
	scanf("%d %d", &m, &c);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		mx[x]++;
		my[y]++;
	}

	for (int i = 0; i < c; i++) {
		scanf("%d %d", &x, &y);
		if (mx[x] <= 1 && my[y] <= 1) {
			cx[x]++;
			cy[y]++;
			cs.emplace(x, y);
		}
	}

	for (auto [xc, a] : cx) for (auto [yc, b] : cy) {
		cur = (mx[xc] == 1) * a + (my[yc] == 1) * b;
		if (mx[xc] == 1 && my[yc] == 1) cur -= cs.count({ xc, yc });
		if (cur > r) r = cur, bx = xc, by = yc;
	}
	printf("%d %d\n%d", bx, by, r);
}
