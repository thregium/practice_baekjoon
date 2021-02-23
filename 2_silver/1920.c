#include <stdio.h>
#include <stdlib.h>

/*
문제 : N개의 숫자들이 주어지고, 이후 M개의 숫자들을 각각 등장한 적이 있는지 여부를 출력한다.(N, M <= 100000)

해결 방법 : O(N^2)으로는 해결하기 어려우므로 퀵소트와 이분 탐색을 이용해 등장 여부를 확인한다.

주요 알고리즘 : 정렬, 이분 탐색
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