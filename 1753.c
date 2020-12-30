#include <stdio.h>
#include <malloc.h>

typedef struct link {
     int v;
     int w;
     struct link* l;
} link;
link* links[25600];
int best[25600];
int heap[25600];
int chk[25600];

int heapz = 0;

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
     for (int i = 0; i <= va; i++) best[i] = 99999999;
     best[k] = 0;
     s = k;
     chk[k] = 1;
     for (int c = 0; c < va; c++) {
          for (link* i = links[s]; i; i = i->l) {
               if(best[s] + i->w < best[i->v]) best[i->v] = best[s] + i->w;
          }
          m = 0;
          for (int i = 1; i <= va; i++) {
               if (!chk[i] && best[i] < best[m]) {
                    m = i;
               }
          }
          //if (c == 0) break;
          chk[m] = 1;
          s = m;
     }
     for (int i = 1; i <= va; i++) {
          if (best[i] > 10000000) printf("INF\n");
          else printf("%d\n", best[i]);
     }
     return 0;
}