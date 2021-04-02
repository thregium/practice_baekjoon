#include <stdio.h>
#include <malloc.h>
#define MAXI 2147483647

/*
���� : �����⿡�� �� ���� ���� ��ȭ�� ��ȭ�� ������ �� ���� ��, �������� ��ġ�� ������ ��ȭ�� ���� �־����� ��ȭ�� �ּ� �� ȸ �Ͼ���� ����Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� �̿��� �������� ��ġ�� �ش� �������� ������ ��ȭ�� �ּڰ��� �����Ѵ�. �̶�, �������� ��ġ�� �� �� �ִ� ������ �ſ� �����Ƿ�
����� ������ �����Ⱑ �ִ� ��ġ���� �Ѵ�. ��� �������� ������ �����ϸ� ��ü �������� �ּڰ��� ������ ��ġ�� �ּڰ��� �ҷ��ͼ� �ᱣ���� �ּڰ��� ���ϰ�
�ּڰ��� ���� �������� �ٽ� Ž���� �Ѵ�. ������ ����ų� ���� ���� �����Ⱑ ���� ��쿡�� 0�� ��ȯ�Ѵ�. �� ��° ���ķδ� �ᱣ���� �ּڰ� - ���� �ּڰ��� ���Ѵ�.
Ž���� �Ϸ�Ǹ� �ᱣ���� ��ȯ�Ѵ�.

//�ٸ� Ǯ�� : �������� ��ġ�� ������� ������ ��, ��ȭ�� ���� ���� �����⿡ ���� ���� ��� ���� ��������� ���̸�ŭ�� ���س�����. ���� ��쿡�� ������ �ʴ´�.

�ֿ� �˰��� : �׸��� �˰���, ���׸�Ʈ Ʈ��?
*/

typedef struct detector {
     int p;
     int c;
} detector;

typedef struct seg {
     detector n;
     int s;
     int e;
     struct seg* l;
     struct seg* r;
} seg;

int stack[204800][3];
int top = 0;

int small(int a, int b) {
     return a < b ? a : b;
}

void newnode(seg* root, int p, int c) {
     if (root->s == root->e) {
          detector d = { root->s, c };
          root->n = d;
          return;
     }
     if ((root->s + root->e) / 2 >= p) {
          if (root->l) {
               newnode(root->l, p, c);
          }
          else {
               seg* l;
               l = calloc(1, sizeof(seg));
               l->s = root->s;
               l->e = (root->s + root->e) / 2;
               root->l = l;
               newnode(l, p, c);
          }
     }
     else {
          if (root->r) {
               newnode(root->r, p, c);
          }
          else {
               seg* r;
               r = calloc(1, sizeof(seg));
               r->s = (root->s + root->e) / 2 + 1;
               r->e = root->e;
               root->r = r;
               newnode(r, p, c);
          }
     }

     detector ld = { -1, -1 }, rd = { -1, -1 };
     if (root->l) ld = root->l->n;
     if (root->r) rd = root->r->n;
     if ((root->l ? ld.c : MAXI) < (root->r ? rd.c : MAXI)) {
          root->n = ld;
     }
     else {
          root->n = rd;
     }
}

detector findsmall(seg* root, int s, int e) {
     if (root->s > e || root->e < s) {
          detector d = { root->s, MAXI };
          return d;
     }
     else if (root->s >= s && root->e <= e) {
          return root->n;
     }
     else {
          detector ld = { -1, MAXI }, rd = { -1, MAXI };
          if (root->l) ld = findsmall(root->l, s, e);
          if (root->r) rd = findsmall(root->r, s, e);
          if ((root->l ? ld.c : MAXI) < (root->r ? rd.c : MAXI)) {
               return ld;
          }
          else {
               return rd;
          }
     }
}

long long totalcalls(seg* root, int s, int e, int h) {
     long long result = 0;

     while (1) {
          if (s > e) {
               if (top == 0) {
                    break;
               }
               else {
                    s = stack[top - 1][0];
                    e = stack[top - 1][1];
                    h = stack[--top][2];
                    continue;
               }
          }
          else if (s == e) {
               int c = findsmall(root, s, e).c;
               result += (c == MAXI ? 0 : c - (long long)h);
               if (top == 0) {
                    break;
               }
               else {
                    s = stack[top - 1][0];
                    e = stack[top - 1][1];
                    h = stack[--top][2];
                    continue;
               }
          }
          detector d = findsmall(root, s, e);
          if (d.c == MAXI) {
               if (top == 0) {
                    break;
               }
               else {
                    s = stack[top - 1][0];
                    e = stack[top - 1][1];
                    h = stack[--top][2];
                    continue;
               }
          }

          result += d.c - (long long)h;
          stack[top][0] = s;
          stack[top][1] = d.p - 1;
          stack[top++][2] = d.c;
          s = d.p + 1;
          h = d.c;
          continue;
          //return (d.c - (long long)h) + totalcalls(root, s, d.p - 1, d.c) + totalcalls(root, d.p + 1, e, d.c);
     }

     return result;
}

int main(void) {
     int n, m, p, c;
     long long r;
     seg* root;
     root = calloc(1, sizeof(seg));
     detector d = { 0, MAXI };
     root->n = d;
     scanf("%d %d", &n, &m);
     root->e = m;
     for (int i = 0; i < n; i++) {
          scanf("%d %d", &p, &c);
          //p = i + 1;
          //c = 1 + i;
          newnode(root, p, c);
     }
     r = totalcalls(root, root->s, root->e, 0);
     printf("%lld", r);
     return 0;
}