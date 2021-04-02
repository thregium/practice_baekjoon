#include <stdio.h>
#include <stdlib.h>
#define MAXI 2147483647

/*
���� : ���̰� 10�� ������ ������ �־��� ��, (x��°���� y��° ���̿� �ִ� �� ��� z���� ū ���� ����) ������ �����Ѵ�. ������ 10���� �����̴�.

�ذ� ��� : ���� ��Ʈ Ʈ���� �̿��� ���׸�Ʈ Ʈ���� �� ��帶�� ��� ���ҵ��� ���Ľ��� �����Ѵ�. ������ ������ ������ upper_bound ������ ����
z���� ū ���� ������ ��ġ�� ã�Ƴ� ����, ��ü ������ �������� ��ġ��ŭ�� �� ���� ���� �� ū ���� ������ ����Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��, ����, �̺� Ž��
*/

typedef struct mtree {
     int* a;
     int s;
     int e;
     struct mtree* l;
     struct mtree* r;
} mtree;

int arr[102400];

void maketree(mtree* root) {
     if (root->s == root->e) {
          root->a = malloc(sizeof(int));
          *(root->a) = arr[root->s - 1];
          return;
     }

     mtree* l, * r;
     l = calloc(1, sizeof(mtree));
     r = calloc(1, sizeof(mtree));
     l->s = root->s;
     l->e = (root->s + root->e) / 2;
     r->s = (root->s + root->e) / 2 + 1;
     r->e = root->e;
     root->l = l;
     root->r = r;

     maketree(root->l);
     maketree(root->r);

     root->a = malloc(sizeof(int) * (root->e - root->s + 1));
     int j = 0, k = 0;
     for (int i = 0; i < root->e - root->s + 1; i++) {
          if ((j >= (root->l->e - root->l->s + 1) ? MAXI : root->l->a[j]) < (k >= (root->r->e - root->r->s + 1) ? MAXI : root->r->a[k])) {
               root->a[i] = l->a[j];
               j++;
          }
          else {
               root->a[i] = r->a[k];
               k++;
          }
     }
}

int bigger(mtree* root, int s, int c) {
     int l = 0;
     int h = s - 1;
     while (h > l) {
          if (root->a[(l + h) / 2] > c) {
               h = (l + h) / 2;
          }
          else {
               l = (l + h) / 2 + 1;
          }
     }
     if (h == s - 1 && root->a[h] <= c) {
          h++;
     }
     return s - h;
}

int find(mtree* root, int a, int b, int c) {
     if (a > root->e || b < root->s) return 0;
     else if (a <= root->s && b >= root->e) return bigger(root, root->e - root->s + 1, c);
     else return find(root->l, a, b, c) + find(root->r, a, b, c);
}

int main(void) {
     int n, m, x, y, z;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &arr[i]);
          //arr[i] = i + 1;
     }
     mtree* root;
     root = calloc(1, sizeof(mtree));
     root->e = n;
     root->s = 1;
     maketree(root);
     
     scanf("%d", &m);
     for (int i = 0; i < m; i++) {
          scanf("%d %d %d", &x, &y, &z);
          printf("%d\n", find(root, x, y, z));
     }
     return 0;
}