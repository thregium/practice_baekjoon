#include <stdio.h>
#include <malloc.h>

/*
���� : ������ ���� ���� �Ϻ� ��ϵǾ� �ִ�. �̶� ���ο� ���� ������ ������ �������µ� ������ ������ ���� ��ġ���� ���� ��ġ���� �������
1��, 2��, 3��... �� �������ٰ� �Ѵ�. ���� �������� �߰��ϰ� Ư���� ��ġ�� ������ ���� ���� ���� ������ �����Ѵ�.

�ذ� ��� : ������ ���������̼� ����� �̿��� ���׸�Ʈ Ʈ���� ���� �ذ��Ѵ�. ���׸�Ʈ Ʈ������ �ٷ� �� �������� ������ �� ���� ���̸� �����Ѵ�.
���� ������ ������ ���׸�Ʈ Ʈ���� 1�� ���ϰ� ������ ���� �ٷ� ���� ��ġ���� ������ ���� ����ŭ�� ���� �ȴ�.
������ ���� ���� �� ������ 1�� ��ġ���� ���� ���� �˱⸦ ���ϴ� ��ġ������ ���� ����� ���� ���ϸ� �� ��ġ�� ������ ���� ���� ����.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��, ������ ���������̼�
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