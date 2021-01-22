#include <stdio.h>
#include <malloc.h>

long long s[1048576];

typedef struct stree {
     long long s;
     long long p;
     long long p2;
     int st;
     int sz;
     struct stree* l;
     struct stree* r;
} stree;

long long big(long long a, long long b) {
     return a > b ? a : b;
}

long long small(long long a, long long b) {
     return a < b ? a : b;
}

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

void lazy(stree* root) {
     if (root->l) {
          if (root->l->p != 0) {
               lazy(root->l);
          }
          else root->l->p += root->p;
     }
     if (root->r) {
          if (root->r->p != 0) {
               lazy(root->r);
          }
          root->r->p += root->p + (root->l ? root->l->sz : 0);
     }
     root->s += root->p * root->sz + (root->sz - 1) * root->sz / 2;
     root->p = 0;
}

void replace(stree* root, int x, int y, long long z) {
     if (root->p != 0) {
          lazy(root);
     }
     if (y < root->st || x > root->st + root->sz - 1) {
          return;
     }
     else if (x <= root->st && y >= root->st + root->sz - 1) {
          root->s += z * root->sz + (root->sz - 1) * root->sz / 2;
          if (root->l) {
               if (root->l->p != 0) {
                    lazy(root->l);
               }
               root->l->p += z;
          }
          if (root->r) {
               if (root->r->p != 0) {
                    lazy(root->r);
               }
               root->r->p += z + (root->l ? root->l->sz : 0);
          }
          return;
     }
     else {
          replace(root->l, x, y, z);
          if (root->r && x >= root->st) {
               z += (root->r->st - small(root->r->st, x));
          }
          else if (root->r) {
               z += ((long long)root->r->st - root->st);
          }
          replace(root->r, x, y, z);
          root->s = (root->l ? root->l->s : 0) + (root->r ? root->r->s : 0);
     }
}

long long getsum(stree* root, int x) {
     if (root->p != 0) {
          lazy(root);
     }
     if (root->sz == 1) return root->s;

     if (x < root->r->st) return getsum(root->l, x);
     else return getsum(root->r, x);
}

int main(void) {
     int n, q;
     long long a, b, c;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%lld", &s[i]);
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
          }
          else if (a == 2) {
               scanf("%lld", &b);
               printf("%lld\n", getsum(root, b));
          }
     }

     return 0;
}