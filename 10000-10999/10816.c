#include <stdio.h>
#include <stdlib.h>

/*
���� : ������ �־�����, ���� ���ڵ��� �־��� �� ���߿� ���� ���ڵ��� ������ ��� �����ߴ��� ���� ����Ѵ�.

�ذ� ��� : ���� ������ ������ ���� �̺� Ž���� ���� �־��� �־��� ���ڰ� ó�� �����ϴ� ��ġ�� ���������� �����ϴ� ��ġ�� Ȯ���ϰ�, ���� ���̸� ����Ѵ�.

�ֿ� �˰��� : �̺� Ž��
*/

int a[524288];

int cmp_a(const void* a, const void* b) {
     int ia, ib;
     ia = *(int*)a;
     ib = *(int*)b;
     return ia > ib ? 1 : ia == ib ? 0 : -1;
}

int* bs_low(int* x, int* a, int n) {
     int* l = a;
     int* h = a + n;
     while (l + 1 < h) {
          int* m = l + (h - l) / 2;
          if (*m < *x) {
               l = m;
          }
          else h = m;
     }

     if (*a == *x) return a;

     if (*h != *x) {
          return NULL;
     }

     return h;
}

int* bs_high(int* x, int* a, int n) {
     int* l = a;
     int* h = a + n;
     while (l + 1 < h) {
          int* m = l + (h - l) / 2;
          if (*m > *x) {
               h = m;
          }
          else l = m;
     }

     if(!bsearch(x, a, n, sizeof(int), cmp_a) && l == a) return a;

     return h;
}

int main(void) {
     int n, m, x, * p, * q;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &a[i]);
     }
     qsort(a, n, sizeof(int), cmp_a);
     scanf("%d", &m);
     for (int i = 0; i < m; i++) {
          scanf("%d", &x);
          p = bs_low(&x, a, n);
          q = bs_high(&x, a, n);
          if (!p) printf("0 ");
          else printf("%d ", (q - p));
          //printf("%d ", p - a);
     }
     return 0;
}