#include <stdio.h>

/*
문제 : 위아래 2행으로 된 스티커집이 있다. 이 스티커에는 각각 점수가 적혀 있는데, 스티커 하나를 떼어내면 양 옆과 위 또는 아래의 스티커는 사용할 수 없다.
이때 이 스티커집에서 얻을 수 있는 최대 점수를 구한다.

해결 방법 : 스티커집에서 윗줄과 아랫줄을 뗐을 때의 각각의 점수를 따로 저장한다. 바로 왼쪽 열의 반대쪽 줄과 2칸 왼쪽 열의 위, 아랫줄을 각각 비교해서
가장 큰 값과 현재 스티커를 뗐을 때의 점수를 더하면 그 스티커를 뗐을 때의 최고 점수가 된다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int sticker[102400][2], mem[102400][2];

int big(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     int t, n;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          scanf("%d", &n);
          for (int i = 0; i < n; i++) {
               scanf("%d", &sticker[i][0]);
          }
          for (int i = 0; i < n; i++) {
               scanf("%d", &sticker[i][1]);
          }
          mem[0][0] = sticker[0][0];
          mem[0][1] = sticker[0][1];
          for (int i = 1; i < n; i++) {
               if (i >= 2) {
                    mem[i][0] = big(big(big(mem[i - 2][0], mem[i - 2][1]), mem[i - 1][1]) + sticker[i][0], mem[i - 1][0]);
                    mem[i][1] = big(big(big(mem[i - 2][1], mem[i - 2][0]), mem[i - 1][0]) + sticker[i][1], mem[i - 1][1]);
               }
               else {
                    mem[i][0] = big(mem[i - 1][1] + sticker[i][0], mem[i - 1][0]);
                    mem[i][1] = big(mem[i - 1][0] + sticker[i][1], mem[i - 1][1]);
               }
          }
          if (n >= 1) printf("%d\n", big(mem[n - 1][0], mem[n - 1][1]));
     }
     return 0;
}