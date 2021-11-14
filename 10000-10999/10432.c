#include <stdio.h>

/*
문제 : 12개의 정수로 이루어진 배열에서 섬의 개수를 구한다.

해결 방법 : 각 구간이 섬인지 매번 확인해 보면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : GNY 2014 B번
*/

int seq[16], lev[16];

int main(void) {
	int t, n, ind, level, prev, cur, r;

	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%d", &n);
		level = 0, prev = 0, r = 0;
		scanf("%d", &cur);
		lev[0] = prev = cur;
		for (ind = 1; ind < 12; ind++) {
			scanf("%d", &cur);
			seq[ind] = cur;
			if (cur > prev) {
				level++;
				r++;
				lev[level] = cur;
			}
			else if (cur < prev) {
				while ((level > 0) && (cur < lev[level])) {
					level--;
				}
				if (cur > lev[level]) {
					level++;
					r++;
					lev[level] = cur;
				}
			}
			prev = cur;
		}
		printf("%d %d\n", n, r);

	}
	return 0;
}
