#include <stdio.h>
#include <malloc.h>
#define INF 999999

/*
���� : ������� ������ ������ �Ÿ�, �������� �־����� �� ���������� �� ���������� �ִܰŸ��� ���Ѵ�.(�Ÿ� <= 10, ���� <= 20000, ���� <= 300000)

�ֿ� �˰��� : ������ ���� ���� ������ �׷����� ���� ����Ʈ�� �̿��� �����Ѵ�. ���ͽ�Ʈ�� �˰����� ���� ���������� �� ���������� �ִܰŸ��� ���ϵ�,
�� ���������� �ּڰ��� ������ �̱� ���� �켱���� ť�� ����ؾ� �Ѵ�. �� ���������� �Ÿ��� ���� ������ �ּ� ���� ������ ��ġ�� ����ְ�(�ּ� ���� ���������� �Ÿ��� �������� �������)
�ּڰ��� ���� ���� ���� ������ ���� ������ �켱���� ť���� �̾Ƽ� ��´�.(?)

�ذ� ��� : �׷��� �̷�, ���ͽ�Ʈ��, ���� ����Ʈ, �켱���� ť
*/

typedef struct link {
     int v;
     int w;
     struct link* l;
} link;
link* links[25600];
int best[25600];
int heap[1048576];
int chk[25600];

int heapz = 0;

int hpush(int a) {
     int x = ++heapz; //�� ������ ����
     for (; (x > 1) && best[a] < best[heap[x / 2]]; x /= 2) {
          heap[x] = heap[x / 2]; //���� ��带 ��ĭ�� ����
     }
     heap[x] = a;
}

int hpop(void) {
     int r = heap[1], l = heap[heapz--]; //�� ��, �� �Ʒ�
     int p = 1, c = 2;

     while (c <= heapz) {
          if (c < heapz && best[heap[c]] > best[heap[c + 1]]) c++; //�������� �� ���� ���
          if (best[l] <= best[heap[c]]) break; //�� �Ʒ� �ִ� ��尡 �� ������ ����
          heap[p] = heap[c];
          p = c;
          c *= 2;
     }
     heap[p] = l;

     return r;
}

int main(void) {
     
     int va, v, e, k, u, w, s, m, c;
     scanf("%d %d%d", &va, &e, &k);
     for (int i = 0; i < e; i++) {
          scanf("%d %d %d", &u, &v, &w);
          link* l;
          l = malloc(sizeof(link));
          l->v = v;
          l->w = w;
          l->l = links[u];
          links[u] = l;
     }
     for (int i = 0; i <= va; i++) best[i] = INF;
     best[k] = 0;
     s = k;
     chk[k] = 1;
     for (int c = 0; c < va; c++) {
          for (link* i = links[s]; i; i = i->l) {
               if (best[s] + i->w <= best[i->v]) {
                    best[i->v] = best[s] + i->w;
               }
               hpush(i->v);
          }
          while (heapz) {
               m = hpop();
               if (!chk[m]) {
                    chk[m] = 1;
                    s = m;
                    //printf("%d ", m);
                    break;
               }
          }
     }
     for (int i = 1; i <= va; i++) {
          if (best[i] >= INF) printf("INF\n");
          else printf("%d\n", best[i]);
     }
     

     return 0;
}