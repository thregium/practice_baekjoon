#include <stdio.h>
#include <malloc.h>

/*
���� : ������ �־�����, ���ķ� ������ �� ���Ҹ� �����ϰų� ���� ������ ���� ����ϴ� ������ �����Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� ���� ���� ������ ���� �����Ѵ�. �� ���Ҹ� ������ ������ ���� ��忡�� �������� ����ϰ�, ������ ���� ����� ������
���ϰ��� �ϴ� ������ ���� ����� ������ �����ϴ� ��� ����� ���� ��ȯ, ��ġ�� �ʴ� ��� 0�� ��ȯ, �� �� �ƴ� ��쿡�� ���� �ڽ� ����� ���� ��ȯ�Ѵ�.
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