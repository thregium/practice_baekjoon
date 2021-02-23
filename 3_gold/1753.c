#include <stdio.h>
#include <malloc.h>
#define INF 999999

/*
문제 : 정점들과 정점들 사이의 거리, 시작점이 주어졌을 때 시작점에서 각 정점까지의 최단거리를 구한다.(거리 <= 10, 정점 <= 20000, 간선 <= 300000)

주요 알고리즘 : 정점의 수가 많기 때문에 그래프는 인접 리스트를 이용해 구현한다. 다익스트라 알고리즘을 통해 시작점에서 각 정점까지의 최단거리를 구하되,
각 정점까지의 최솟값을 빠르게 뽑기 위해 우선순위 큐를 사용해야 한다. 각 정점까지의 거리를 구할 때마다 최소 힙에 정점의 위치를 집어넣고(최소 힙은 정점까지의 거리를 기준으로 집어넣음)
최솟값은 아직 뽑지 않은 정점이 나올 때까지 우선순위 큐에서 뽑아서 얻는다.(?)

해결 방법 : 그래프 이론, 다익스트라, 연결 리스트, 우선순위 큐
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
     int x = ++heapz; //맨 위에서 시작
     for (; (x > 1) && best[a] < best[heap[x / 2]]; x /= 2) {
          heap[x] = heap[x / 2]; //위쪽 노드를 한칸씩 내림
     }
     heap[x] = a;
}

int hpop(void) {
     int r = heap[1], l = heap[heapz--]; //맨 위, 맨 아래
     int p = 1, c = 2;

     while (c <= heapz) {
          if (c < heapz && best[heap[c]] > best[heap[c + 1]]) c++; //오른쪽이 더 작은 경우
          if (best[l] <= best[heap[c]]) break; //맨 아래 있던 노드가 더 작으면 중지
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