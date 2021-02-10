#include <stdio.h>
#include <malloc.h>

/*
문제 : 수열이 주어지고, 이후로 수열의 한 원소를 갱신하거나 일정 구간의 합을 출력하는 쿼리에 응답한다.

해결 방법 : 세그먼트 트리를 통해 일정 구간의 합을 저장한다. 한 원소를 갱신할 때에는 리프 노드에서 역순으로 계산하고, 구간의 합을 출력할 때에는
구하고자 하는 구간이 현재 노드의 구간을 포함하는 경우 노드의 값을 반환, 겹치지 않는 경우 0을 반환, 둘 다 아닌 경우에는 양쪽 자식 노드의 합을 반환한다.
*/

long long s[1048576];

typedef struct stree {
     long long s;
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

void replace(stree* root, int x, long long y) {
     if (root->sz == 1) {
          root->s = y;
          return;
     }

     if (x < root->r->st) {
          replace(root->l, x, y);
     }
     else {
          replace(root->r, x, y);
     }
     root->s = (root->l ? root->l->s : 0) + (root->r ? root->r->s : 0);
}

long long getsum(stree* root, int x, int y) {
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
     long long a, b, c;
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
               replace(root, b, c);
          }
          else if (a == 2) {
               printf("%lld\n", getsum(root, b, c));
          }
     }
     
     return 0;
}