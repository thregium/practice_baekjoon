#include <stdio.h>
#include <malloc.h>
#define MAXI 2147483647

/*
문제 : 10만개 이하의 정수로 이루어진 배열이 주어질 때 최대 10만개의 최대, 최솟값 쿼리에 응답한다.

해결 방법 : 세그먼트 트리에 구간별로 최댓값과 최솟값을 저장하고 이후 구간별 부분값들을 통해 최소, 최댓값을 확인하는 방식으로 해결한다.

주요 알고리즘 : 자료구조, 트리, 세그먼트 트리
*/

typedef struct stree {
     int m;
     int x;
     int s;
     int e;
     struct stree* l;
     struct stree* r;
} stree;

int arr[102400];

int small(int a, int b) {
     return a < b ? a : b;
}

int big(int a, int b) {
     return a > b ? a : b;
}

void maketree(stree* root) {
     if (root->s == root->e) {
          root->m = arr[root->s - 1];
          root->x = arr[root->s - 1];
          return;
     }

     stree* l, * r;
     l = calloc(1, sizeof(stree));
     r = calloc(1, sizeof(stree));
     l->s = root->s;
     l->e = (root->s + root->e) / 2;
     r->s = (root->s + root->e) / 2 + 1;
     r->e = root->e;
     root->l = l;
     root->r = r;
     maketree(l);
     maketree(r);

     root->m = small(l->m, r->m);
     root->x = big(l->x, r->x);
}

int getmin(stree* root, int a, int b) {
     if (root->s > b || root->e < a) return MAXI;
     else if (root->s >= a && root->e <= b) return root->m;
     else return small(getmin(root->l, a, b), getmin(root->r, a, b));
}

int getmax(stree* root, int a, int b) {
     if (root->s > b || root->e < a) return -MAXI;
     else if (root->s >= a && root->e <= b) return root->x;
     else return big(getmax(root->l, a, b), getmax(root->r, a, b));
}

int main(void) {
     int n, m, a, b;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          scanf("%d", &arr[i]);
     }

     stree* root;
     root = calloc(1, sizeof(stree));
     root->s = 1;
     root->e = n;
     maketree(root);

     for (int i = 0; i < m; i++) {
          scanf("%d %d", &a, &b);
          printf("%d %d\n", getmin(root, a, b), getmax(root, a, b));
     }
     return 0;
}