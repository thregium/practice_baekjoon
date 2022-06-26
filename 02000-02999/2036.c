#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ���� 10^6 ���� ������ �־��� ��, ������ 1�� �Ǵ� 2���� ���� ���� ����
�� �� �ִ� �ִ��� ���Ѵ�.

�ذ� ��� : 0�� 1�� �߽����� ���ʰ� �������� ������ ����� ����, ��� ������ ���� ó���Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ���̽� ��ũ
*/

int a[103000];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
	int n, l = -1, r;
	long long res = 0;
	scanf("%d", &n);
	r = n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp1);
	for (int i = 0; i < n - 1; i += 2) {
		if (a[i] <= 0 && a[i + 1] <= 0) res += (long long)a[i] * a[i + 1];
		else break;
		l = i + 1;
	}
	for (int i = n - 1; i > l + 1; i -= 2) {
		if (a[i] > 1 && a[i - 1] > 1) res += (long long)a[i] * a[i - 1];
		else break;
		r = i - 1;
	}
	for (int i = l + 1; i < r; i++) {
		res += a[i];
	}
	printf("%lld", res);
	return 0;
}
