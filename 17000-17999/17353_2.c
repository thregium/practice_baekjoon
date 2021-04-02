#include <stdio.h>
#include <malloc.h>

/*
문제 : 떨어진 별의 수가 일부 기록되어 있다. 이때 새로운 별이 일정한 구간에 떨어지는데 떨어질 때에는 앞쪽 위치부터 뒤쪽 위치까지 순서대로
1개, 2개, 3개... 씩 떨어진다고 한다. 별의 떨어짐을 추가하고 특정한 위치에 떨어진 별의 수를 묻는 쿼리에 응답한다.

해결 방법 : 레이지 프로포케이션 기법을 이용한 세그먼트 트리를 통해 해결한다. 세그먼트 트리에는 바로 앞 구역과의 떨어진 별 수의 차이를 저장한다.
별이 떨어진 곳에는 세그먼트 트리에 1을 더하고 떨어진 곳의 바로 다음 위치에는 떨어진 별의 수만큼을 빼면 된다.
떨어진 별의 수를 셀 때에는 1번 위치부터 별의 수를 알기를 원하는 위치까지의 리프 노드의 합을 구하면 그 위치에 떨어진 별의 수와 같다.

주요 알고리즘 : 자료구조, 세그먼트 트리, 레이지 프로포케이션
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
          root->s = 0;
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
     int n, q;
     long long a, b, c;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &s[i]);
     }
     stree* root;
     root = calloc(1, sizeof(stree));
     root->st = 1;
     root->sz = n;
     maketree(root);

     scanf("%d", &q);
     for (int i = 0; i < q; i++) {
          scanf("%lld", &a);
          if (a == 1) {
               scanf("%lld %lld", &b, &c);
               replace(root, b, c, 1);
               replace(root, c + 1, c + 1, b - c - 1);
          }
          else if (a == 2) {
               scanf("%lld", &b);
               printf("%lld\n", getsum(root, 1, b) + s[b - 1]);
          }
     }
     return 0; 
}