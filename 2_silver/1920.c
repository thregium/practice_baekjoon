#include <stdio.h>
#include <stdlib.h>

/*
���� : N���� ���ڵ��� �־�����, ���� M���� ���ڵ��� ���� ������ ���� �ִ��� ���θ� ����Ѵ�.(N, M <= 100000)

�ذ� ��� : O(N^2)���δ� �ذ��ϱ� �����Ƿ� ����Ʈ�� �̺� Ž���� �̿��� ���� ���θ� Ȯ���Ѵ�.

�ֿ� �˰��� : ����, �̺� Ž��
*/

int a[102400];

int cmp_a(const void* a, const void* b) {
     int ia, ib;
     ia = *(int*)a;
     ib = *(int*)b;
     return ia > ib ? 1 : ia == ib ? 0 : -1;
}

int main(void) {
     int n, m, x, *p;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a[i]);
     }
     qsort(a, n, sizeof(int), cmp_a);
     scanf("%d", &m);
     for (int i = 0; i < m; i++) {
          scanf("%d", &x);
          p = bsearch(&x, a, n, sizeof(int), cmp_a);
          printf("%d\n", !!p);
     }
     return 0;
}