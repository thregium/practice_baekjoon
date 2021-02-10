#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

/*
문제 : 히스토그램으로 만들 수 있는 직사각형 가운데 가장 넓은 것을 구한다.
해결 방법 : 히스토그램에서 가장 높이가 낮은 막대를 기준점으로 잡고 (현재 구간의 길이 * 막대의 높이)를 현재까지 넓이의 최댓값과 비교하고 더 큰 경우 최댓값을 바꾼다.
그 후 다시 구간을 (시작점, 기준점 - 1), (기준점 + 1, 끝점)으로 나누어 다시 위의 과정을 반복한다.
이때 시작점이 끝점보다 큰 경우는 음수를 반환하고, 시작점과 끝점이 같은 경우는 막대의 높이를 반환한다.

최솟값을 구할 때에는 O(N^2) 방식으로는 시간이 오래 걸리므로 구간의 최솟값을 O(NlgN) 시간에 구할 수 있는 세그먼트 트리를 이용한다.
각각의 노드에는 구간의 시작점과 끝점, 구간의 최솟값의 번호가 들어가고 왼쪽 서브트리는 (시작점, 시작점 + (끝점 - 시작점) / 2) 구간, 오른쪽 서브트리는 (시작점 + (끝점 - 시작점) / 2 + 1, 끝점) 구간이다.
먼저 트리를 만들고 리프노드에만 각각의 최솟값의 번호를 집어넣는다. 그리고 다시 트리를 후위순회하여 노드의 리프노등의 최솟값을 비교하여 최솟값의 번호를 집어넣는다.
최솟값을 찾을 때에는 구간을 확인 후 구하고자 하는 구간이 더 넓으면 노드의 값을 반환, 서로 겹치지 않으면 -1을 반환, 모두 아닌 경우 양쪽 서브트리로 내려가는 것을 반복하고 반환된 값들을 비교해 찾는다.

재귀형으로 함수를 작성시 재귀의 수가 많아져 오류가 일어날 수 있으므로 재귀 대신 스택을 사용하는 형태로 작성해야 한다.

주요 알고리즘 : 분할 정복, 스택, 세그먼트 트리
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