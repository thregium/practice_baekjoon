#include <stdio.h>
#include <stdlib.h>

int g[32], mem[32][81920];

int cmp1(const void* a, const void* b) {
     int ai = *(int*)a;
     int bi = *(int*)b;
     return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
     int k, m, w, s = 0;
     scanf("%d", &k);
     for (int i = 1; i <= k; i++) {
          scanf("%d", &g[i]);
          s += g[i];
     }
     //qsort(g + 1, k, sizeof(int), cmp1);
     mem[0][s] = 1;
     for (int i = 1; i <= k; i++) {
          for (int j = 0; j <= s * 2; j++) {
               if (mem[i - 1][j]) {
                    mem[i][j] = 1;
               }
               if (j >= g[i] && mem[i - 1][j - g[i]]) {
                    mem[i][j] = 1;
               }
               if (j <= s * 2 - g[i] && mem[i - 1][j + g[i]]) {
                    mem[i][j] = 1;
               }
          }
     }

     scanf("%d", &m);
     for (int i = 0; i < m; i++) {
          scanf("%d", &w);
          if (mem[k][w + s]) printf("Y ");
          else printf("N ");
     }
     return 0;
}