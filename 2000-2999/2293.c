#include <stdio.h>

/*
문제 : n개의 동전이 각각의 가치를 갖고 있을 때(같을 수도, 다를 수도 있음), k원을 만드는 서로 다른 방법의 가짓수를 출력한다. (순서만 다른 것은 같은 것으로 본다.)

해결 방법 : m번째의 동전까지만 사용했을 때 l원을 만드는 방법으로 바꾸어 생각해 보면 f(m, l) = f(m - 1, l) + f(m, (l - g(m)))과 같다.(g(m)은 m번째 동전의 가치)
이때, 메모리 제한이 작으므로 메모리를 재활용해야 하는데, 점화식에서 f(m - 2) 이하는 사용하지 않으므로 f(m)을 전부 구하면 f(m)을 f(m - 1)에 복사하여 메모리를 재활용할 수 있다.
*/

int coins[128], mem[2][10240];

int main(void) {
     int n, k;
     scanf("%d %d", &n, &k);
     for (int i = 0; i < n; i++) {
          scanf("%d", &coins[i]);
     }
     for (int i = 0; i <= k; i++) {
          if (i % coins[0] == 0) mem[0][i] = 1;
     }
     for (int i = 1; i < n; i++) {
          mem[1][0] = 1;
          for (int j = 1; j <= k; j++) {
               if (j >= coins[i]) mem[1][j] = mem[0][j] + mem[1][j - coins[i]];
               else mem[1][j] = mem[0][j];
          }
          for (int j = 0; j <= k; j++) {
               mem[0][j] = mem[1][j];
          }
     }
     if(k > 0 && k <= 10000) printf("%d", mem[0][k]);
     return 0;
}