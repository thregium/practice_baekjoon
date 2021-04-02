#include <stdio.h>
#include <stdlib.h>

/*
문제 : 수열이 주어지고, 이후 숫자들이 주어질 때 나중에 나온 숫자들이 수열에 몇번 등장했는지 각각 출력한다.

해결 방법 : 먼저 수열을 정렬한 다음 이분 탐색을 통해 주어진 주어진 숫자가 처음 등장하는 위치와 마지막으로 등장하는 위치를 확인하고, 둘의 차이를 출력한다.

주요 알고리즘 : 이분 탐색
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