#include <stdio.h>
#include <malloc.h>

/*
문제 : 100만개 이하의 수를 가진 수열에서 일정 구간의 수를 일정량 증가시키거나 일정 구간의 수의 합을 출력하는 쿼리에 응답한다. 쿼리의 수는 2만 이하이다.

해결 방법 : 세그먼트 트리에서 추가로 업데이트 여부를 저장한다. 업데이트시에는 구간 단위로 업데이트 할 수를 저장해놓고,
다음번에 겹치는 구간에서 업데이트가 이루어지는 경우 하위 구간으로 업데이트를 한다. 구간합을 구할 때 업데이트가 필요한 영역이 남아있는 경우
하위 구간으로 업데이트를 보내고 구간합을 구해온다.

주요 알고리즘 : 자료구조, 세그먼트 트리, 레이지 프로프케이션
*/

long long s[1048576];

typedef struct stree {
     long long s;
     long long p;
     int st;
     int sz;
     struct stree* l;
     struct stree* r;
} stree;

void maketree(stree* root) {
     if (root->sz == 1) {
          root->s = s[root->st - 1];
          return;
     }

     stree* l, * r;
     l = calloc(1, sizeof(stree));
     r = calloc(1, sizeof(stree));
     l->st = root->st;
     l->sz = root->sz / 2;
     r->st = root->st + root->sz / 2;
     r->sz = root->sz / 2 + root->sz % 2;
     root->l = l;
     root->r = r;

     maketree(l);
     maketree(r);
     root->s = (root->l ? root->l->s : 0) + (root->r ? root->r->s : 0);
}

void replace(stree* root, int x, int y, long long z) {
     if (root->p != 0) {
          if (root->l) root->l->p += root->p;
          if (root->r) root->r->p += root->p;
          root->s += root->p * root->sz;
          root->p = 0;
     }
     if (y < root->st || x > root->st + root->sz - 1) {
          return;
     }
     else if (x <= root->st && y >= root->st + root->sz - 1) {
          root->s += z * root->sz;
          if (root->l) root->l->p += z;
          if (root->r) root->r->p += z;
          return;
     }
     else {
          replace(root->l, x, y, z);
          replace(root->r, x, y, z);
          root->s = root->l->s + root->r->s;
     }
}

long long getsum(stree* root, int x, int y) {
     if (root->p != 0) {
          if (root->l) root->l->p += root->p;
          if (root->r) root->r->p += root->p;
          root->s += root->p * root->sz;
          root->p = 0;
     }
     if (y < root->st || x > root->st + root->sz - 1) {
          return 0;
     }
     else if (x <= root->st && y >= root->st + root->sz - 1) {
          return root->s;
     }

     else return getsum(root->l, x, y) + getsum(root->r, x, y);
}

int main(void) {
     int n, m, k;
     long long a, b, c, d;
     scanf("%d %d %d", &n, &m, &k);
     for (int i = 0; i < n; i++) {
          scanf("%d", &s[i]);
     }
     stree* root;
     root = calloc(1, sizeof(stree));
     root->st = 1;
     root->sz = n;
     maketree(root);
     for (int i = 0; i < m + k; i++) {
          scanf("%lld %lld %lld", &a, &b, &c);
          if (a == 1) {
               scanf("%lld", &d);
               replace(root, b, c, d);
          }
          else if (a == 2) {
               printf("%lld\n", getsum(root, b, c));
          }
     }

     return 0;
}