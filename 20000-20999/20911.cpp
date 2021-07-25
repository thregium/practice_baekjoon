#include <stdio.h>
#include <set>
#include <map>
using namespace std;

/*
���� : ��ǥ��� �� M���� �񼮰� C(M, C <= 1000)���� ��ȸ�� �ִ�. ���� X�� �Ǵ� Y�࿡ ���� 2�� �̻� �ִ� ��� ��ȸ��
��ȭ�ȴٰ� �Ѵ�. �̶�, ���� �� �ϳ��� ������ ��, ��ȭ�� ��ȸ�� ���� ���� ���� �� �ִ� ���� ��ǥ�� ���Ѵ�.
���� �ٸ� ���̳� ��ȸ�� ��ĥ �� �ִ�.

�ذ� ��� : �� X��� Y�ະ�� ���� ���� ���Ѵ�. �� �������� ���� ������� ��ȸ�� ���� ���ϵ�, �̹� ��ȭ�� ��ȸ�� �����Ѵ�.
�� �������δ� ��ȭ���� ���� ��ȸ�� ���� ���� X��� Y���� ã�� �� ��ǥ���� ��ȭ�� ��ȸ�� ���� ���ϸ� �ȴ�.
�̶�, �������� �ִ� ��ȸ�� �� �� ���� �ʵ��� �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����?

��ó : GCPC 2020 K��
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
