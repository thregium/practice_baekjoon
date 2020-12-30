#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int itemw[120];
int itemv[120];
int items[120];
int bestv[102400] = { 0, };
//int besti[102400][120] = { 0, };

int big(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     int n, k, b, t;
     scanf("%d %d", &n, &k);
     srand(time(NULL));
     for (int i = 0; i < n; i++) {
          scanf("%d %d", &itemw[i], &itemv[i]);
          /*
          itemw[i] = rand() % 1000 + 1;
          itemv[i] = rand() % 1000 + 1;
          srand(rand());

     }
     for (int i = 0; i < n; i++) printf("%d %d\n", itemw[i], itemv[i]);
     */
     }
     for (int i = 0; i < n; i++) {
          for (int j = k; j >= itemw[i]; j--) {
               bestv[j] = big(bestv[j], bestv[j - itemw[i]] + itemv[i]);
          }
     }
     printf("%d", bestv[k]);
     return 0;
}