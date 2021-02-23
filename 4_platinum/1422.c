#include <stdio.h>
#include <string.h>

int num[1024];
int sorted[1024];

int biggeratt(int a, int b) {
     char ad[16] = { 0, }, bd[16] = { 0, };
     char lt[32] = { 0, }, rt[32] = { 0, };
     int t = a, t2;
     for (int i = a; i > 0; i /= 10) ad[0]++;
     for (int i = b; i > 0; i /= 10) bd[0]++;
     t2 = ad[0];
     for (int i = t2 - 1; i >= 0; i--) {
          ad[i] = t % 10 + 48;
          t /= 10;
     }
     t = b;
     t2 = bd[0];
     for (int i = t2 - 1; i >= 0; i--) {
          bd[i] = t % 10 + 48;
          t /= 10;
     }
     strcpy(lt, ad);
     strcat(lt, bd);
     strcpy(rt, bd);
     strcat(rt, ad);
     return strcmp(rt, lt) > 0 ? 1 : 0;
}

int main(void) {
     int k, n, l, h, j, lar = 0, prt = 0, z = 1;
     
     scanf("%d %d", &k, &n);
     for (int i = 0; i < k; i++) scanf("%d", &num[i]);
     for (int i = 0; i < k; i++) {
          if (num[i] > lar) lar = num[i];
     }
     
     while (z < k) {
          for (int i = 0; i < k; i += 2 * z) {
               l = i;
               h = i + z;
               j = 0;
               if (h >= k) h = k - 1;
               while (l < i + z || (h < i + 2 * z && h < k)) {
                    if (h < k && (biggeratt(num[l], num[h]) && h < i + 2 * z || l >= i + z || l >= h)) {
                         sorted[i + j] = num[h];
                         h++;
                    }
                    else {
                         sorted[i + j] = num[l];
                         l++;
                    }
                    j++;
               }
          }
          for (int i = 0; i < k; i++) num[i] = sorted[i];
          z *= 2;
     }
     if (k == 1) sorted[0] = num[0];
     //printf("%d\n", lar);
     for (int i = 0; i < k; i++) {
          if (prt == 0 && sorted[i] == lar) {
               for (int j = 0; j < n - k; j++) printf("%d\n", sorted[i]);
               prt = 1;
          }
          printf("%d\n", sorted[i]);
     }

     return 0;
}