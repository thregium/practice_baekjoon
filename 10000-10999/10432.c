#include <stdio.h>

/*
���� : 12���� ������ �̷���� �迭���� ���� ������ ���Ѵ�.

�ذ� ��� : �� ������ ������ �Ź� Ȯ���� ���� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : GNY 2014 B��
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
