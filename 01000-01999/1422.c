#include <stdio.h>
#include <string.h>

/*
문제 : K개의 자연수에서 N(N, K <= 1000)개를 뽑아낸 후 이어붙여서 만들 수 있는 수 가운데 가장 큰 것을 찾는다.
단, 각 수는 최소 1번씩은 써야 한다.

해결 방법 : 먼저, 모든 수를 한번씩 이어야 하는데, 잇는 순서는 두 수를 이었을 때, 더 큰 값이 되도록 정렬하면 최적의 순서가 된다.
수들을 이은 뒤에는 맨 뒤 또는 맨 앞에 가장 큰 수를 남은 횟수만큼 반복하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

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