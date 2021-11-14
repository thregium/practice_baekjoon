#include <stdio.h>
#include <stdlib.h>

/*
���� : 1�� �������� N(N <= 2000)�� �������� ���ʷ� �����̸� �ڽ��� ����Ѵ�. �ѹ��� �ִ� C(C <= 10000)�� ������
��� �����ϴٸ� ��� ������ �ִ� ������ ���Ѵ�. ���������� ������ ���� ����, �� ����� ���������θ� �̷������.

�ذ� ��� : ����� �� ������ �������� �����ϴ� ���� �������� �� �� �ִ�. �� ��۸��� ������ �ִ����� �ڽ���
����ϰ� �׶��� �ڽ� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����

��ó : ���� 2013 ��2��
*/

int cap[10240], box[10240][3];

int big(int a, int b) {
	return a > b ? a : b;
}

int small(int a, int b) {
	return a < b ? a : b;
}

int cmp1(const void* a, const void* b) {
	int ai = *((int*)a + 1);
	int bi = *((int*)b + 1);
	if(ai != bi) return ai > bi ? 1 : -1;
	ai = *(int*)a;
	bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main() {
	int n, c, m, r = 0, x, t;
	scanf("%d %d %d", &n, &c, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &box[i][0], &box[i][1], &box[i][2]);
	}
	qsort(box, m, sizeof(int) * 3, cmp1);
	for (int i = 0; i < m; i++) {
		x = 0;
		for (int j = box[i][0]; j < box[i][1]; j++) x = big(x, cap[j]);
		t = small(box[i][2], c - x);
		for (int j = box[i][0]; j < box[i][1]; j++) cap[j] += t;
		r += t;
	}
	printf("%d", r);
}