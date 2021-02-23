#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

/*
���� : ������׷����� ���� �� �ִ� ���簢�� ��� ���� ���� ���� ���Ѵ�.
�ذ� ��� : ������׷����� ���� ���̰� ���� ���븦 ���������� ��� (���� ������ ���� * ������ ����)�� ������� ������ �ִ񰪰� ���ϰ� �� ū ��� �ִ��� �ٲ۴�.
�� �� �ٽ� ������ (������, ������ - 1), (������ + 1, ����)���� ������ �ٽ� ���� ������ �ݺ��Ѵ�.
�̶� �������� �������� ū ���� ������ ��ȯ�ϰ�, �������� ������ ���� ���� ������ ���̸� ��ȯ�Ѵ�.

�ּڰ��� ���� ������ O(N^2) ������δ� �ð��� ���� �ɸ��Ƿ� ������ �ּڰ��� O(NlgN) �ð��� ���� �� �ִ� ���׸�Ʈ Ʈ���� �̿��Ѵ�.
������ ��忡�� ������ �������� ����, ������ �ּڰ��� ��ȣ�� ���� ���� ����Ʈ���� (������, ������ + (���� - ������) / 2) ����, ������ ����Ʈ���� (������ + (���� - ������) / 2 + 1, ����) �����̴�.
���� Ʈ���� ����� ������忡�� ������ �ּڰ��� ��ȣ�� ����ִ´�. �׸��� �ٽ� Ʈ���� ������ȸ�Ͽ� ����� ��������� �ּڰ��� ���Ͽ� �ּڰ��� ��ȣ�� ����ִ´�.
�ּڰ��� ã�� ������ ������ Ȯ�� �� ���ϰ��� �ϴ� ������ �� ������ ����� ���� ��ȯ, ���� ��ġ�� ������ -1�� ��ȯ, ��� �ƴ� ��� ���� ����Ʈ���� �������� ���� �ݺ��ϰ� ��ȯ�� ������ ���� ã�´�.

��������� �Լ��� �ۼ��� ����� ���� ������ ������ �Ͼ �� �����Ƿ� ��� ��� ������ ����ϴ� ���·� �ۼ��ؾ� �Ѵ�.

�ֿ� �˰��� : ���� ����, ����, ���׸�Ʈ Ʈ��
*/

typedef struct lhtree {
     int lo;
     int hi;
     int s;
     struct lhtree* l;
     struct lhtree* r;
} lhtree;

int n;

long long int his[102400];
int stack[102400][2];
int sttop = 0;

lhtree* tree;

long long int big(long long int a, long long int b) {
     return a > b ? a : b;
}
long long int small(long long int a, long long int b) {
     return a < b ? a : b;
}

void make_tree(lhtree* root, int lo, int hi) {
     if (lo == hi) {
          root->s = lo;
          root->lo = lo;
          root->hi = hi;
          return;
     }
     lhtree* l, *r;
     l = malloc(sizeof(lhtree));
     r = malloc(sizeof(lhtree));
     root->s = -1;
     root->lo = lo;
     root->hi = hi;
     root->l = l;
     root->r = r;
     make_tree(root->l, lo, lo + (hi - lo) / 2);
     make_tree(root->r, lo + (hi - lo) / 2 + 1, hi);
}

void tree_set_smallest(lhtree* root) {
     if (root->s >= 0) return;
     tree_set_smallest(root->l);
     tree_set_smallest(root->r);
     if (root->l->s >= 0 && root->r->s >= 0) {
          if (his[root->l->s] > his[root->r->s]) root->s = root->r->s;
          else root->s = root->l->s;
          return;
     }
}

int find_lowest(int start, int end, lhtree* root) {
     if (root->lo > end || root->hi < start) {
          return -1;
     }
     /*
     else if (root->lo > start && root->hi > end) {
          return find_lowest(start, end, root->l);
     }
     else if (root->lo < start && root->hi < end) {
          return find_lowest(start, end, root->r);
     }
     */
     else if (root->lo >= start && root->hi <= end) {
          return root->s;
     }
     else {
          int a, b;
          a = find_lowest(start, end, root->l);
          b = find_lowest(start, end, root->r);
          if (a < 0) return b;
          else if (b < 0) return a;
          else if (his[a] < his[b]) return a;
          else return b;
     }
}

long long int largest(int start, int end) {
     if (start > end) return 0;
     if (start == end) return his[start];
     lhtree* root = tree;
     int s = start, l = find_lowest(start, end, root), e = end;
     long long int r = 0;
     while (1) {
          //printf("s = %d, e = %d\n", s, e);
          if (s > e) {
               if (sttop == 0) break;
               s = stack[sttop - 1][0];
               e = stack[sttop - 1][1];
               sttop--;
               continue;
          }
          else if (s == e) {
               if (his[s] > r) r = his[s];
               if (sttop == 0) break;
               s = stack[sttop - 1][0];
               e = stack[sttop - 1][1];
               sttop--;
               continue;
          }
          l = find_lowest(s, e, root);
          if (s <= l - 1) {
               stack[sttop][0] = s;
               stack[sttop][1] = l - 1;
               sttop++;
          }
          if (l + 1 <= e) {
               stack[sttop][0] = l + 1;
               stack[sttop][1] = e;
               sttop++;
          }
          if (his[l] * (e - s + 1) > r) {
               //printf("%lld * %d = %lld\n", his[l], (e - s + 1), his[l] * (e - s + 1));
               r = his[l] * (e - s + 1);
          }
          s = stack[sttop - 1][0];
          e = stack[sttop - 1][1];
          sttop--;
     }
     return r;
}

int main(void) {
     while (1) {
          scanf("%d", &n);
          if (n == 0) break;
          srand(time(NULL));
          for (int i = 0; i < n; i++) {
               scanf("%lld", &his[i]);
               //his[i] = 1000000000 + i;
               //his[i] = rand() * 65536;
               //his[i] += rand();
               //srand(his[i]);
          }
          tree = malloc(sizeof(lhtree));
          make_tree(tree, 0, n - 1);
          tree_set_smallest(tree);
          printf("%lld\n", largest(0, n - 1));
     }
     return 0;
}