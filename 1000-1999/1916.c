#include <stdio.h>
#include <malloc.h>

/*
문제 : 버스의 행선지 목록과 각각의 운임, 원하는 출발지와 목적지가 있을 때 출발지에서 목적지까지 버스를 통해 갈 수 있는 최소한의 요금을 구한다.

해결 방법 : 다익스트라 알고리즘을 통해 최단거리를 확인한다. 먼저, 출발지와 연결된 도시들까지의 거리를 확인하고, 연결되지 않은 곳은 거리를 (사실상) 무한대로 설정한다.
이후로는 현재까지 확인된 거리들 가운데 가장 가까운 곳을 기준으로 연결된 도시들까지의 거리를 확인하는 것을 반복한다.
모든 도시들의 거리를 확인하면 출발지와 도착지 사이의 거리를 확인하고 출력한다.

주요 알고리즘 : 그래프, 다익스트라
*/

typedef struct link {
     int v;
     int w;
     struct link* l;
} link;
link* links[25600];
int best[25600];
int chk[25600];

int main(void) {
     int n, m, u, v, w, k, l, s, o;
     //n : 도시의 갯수, m : 버스의 갯수
     //u : 출발지, v : 도착지, w : 요금
     //k : 시작지, l : 목적지
     //s : 현재 탐색 중인 장소, o : 다음 s를 찾기 위한 임시 변수
     scanf("%d %d", &n, &m);
     for (int i = 0; i < m; i++) {
          scanf("%d %d %d", &u, &v, &w);
          link* l;
          l = malloc(sizeof(link));
          l->v = v;
          l->w = w;
          l->l = links[u];
          links[u] = l;
     }
     for (int i = 0; i <= n; i++) best[i] = 999999999;
     scanf("%d %d", &k, &l);
     best[k] = 0;
     s = k;
     chk[k] = 1;
     for (int c = 0; c < n; c++) {
          for (link* i = links[s]; i; i = i->l) {
               if (best[s] + i->w < best[i->v]) best[i->v] = best[s] + i->w;
          }
          o = 0;
          for (int i = 1; i <= n; i++) {
               if (!chk[i] && best[i] < best[o]) {
                    o = i;
               }
          }
          //if (c == 0) break;
          chk[o] = 1;
          s = o;
     }
     printf("%d\n", best[l]);
     return 0;
}