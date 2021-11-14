#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : N(N <= 10000)���� ����(-1000 <=, <= 1000)�� �־��� ��, ���� 2�� �Ǵ� 3���� ������ ������ ���� ū ���� ���Ѵ�.

�ذ� ��� : ���� 2������ ������ ���� ���� * ����, ��� * ����̰�, 3�������� ���� * ���� * ���, ��� * ��� * ����̴�.
���� ������ ���� �̷��� ������ ���� ã�Ƽ� ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ���̽� ��ũ

��ó : Daejeon 2017I H��
*/

int a[10240];

int cmp1(const void* a, const void* b) {
	int ai = *(int*)a;
	int bi = *(int*)b;
	return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
	int n, r = -INF;
	scanf("%d", &n);
	if (n < 3) return 1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), cmp1);
	if (r < a[0] * a[n - 1] * a[n - 2]) r = a[0] * a[n - 1] * a[n - 2];
	if (r < a[0] * a[1] * a[2]) r = a[0] * a[1] * a[2];
	if (r < a[0] * a[1]) r = a[0] * a[1];
	if (r < a[n - 1] * a[n - 2]) r = a[n - 1] * a[n - 2];
	printf("%d", r);
}