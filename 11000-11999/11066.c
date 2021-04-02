#include <stdio.h>
#define MAXI 2147483647

/*
문제 : 서로 이웃한 파일들끼리 합쳐나가는 방식으로 K개의 파일들을 합치려고 한다. 이 때 드는 시간은 각 임시 파일들의 크기와 전체 파일의 크기를 합한 것이라고 할 때,
각 파일들의 크기가 주어지면 이 파일을 하나로 합치는데 드는 최소 시간을 구한다.

해결 방법 : i번부터 j번까지의 파일을 합치는데 드는 파일의 최솟값은 i번부터 i+l번까지의 최솟값과 i+l+1번부터 j번까지의 최솟값을 합한 것의 최솟값에
i번부터 j번까지의 파일 크기의 합과 같다. 단, i와 j가 같다면 합칠 필요가 없으므로 파일 크기를 더하지 않는다.
j - i가 1인 것부터 시작해서 k - 1인 것까지 순서대로 계산하면 결괏값은 i번부터 k - 1번까지 순서대로 계산한 것과 같다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int c[512], s[512], mem[512][512];

int small(int a, int b) {
     return a < b ? a : b;
}

int sumc(int a, int b) {
     return s[b] - (a == 0 ? 0 : s[a - 1]);
}

int main(void) {
     int t, k, b;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          scanf("%d", &k);
          for (int i = 0; i < k; i++) {
               scanf("%d", &c[i]);
               s[i] = (i == 0 ? 0 : s[i - 1]) + c[i];
          }
          for (int i = 1; i < k; i++) {
               for (int j = 0; j < k - i; j++) {
                    if (i == 0) {
                         mem[j][j] = 0;
                         continue;
                    }
                    b = MAXI;
                    for (int l = j; l < j + i; l++) {
                         b = small(b, mem[j][l] + mem[l + 1][j + i]);
                    }
                    mem[j][j + i] = b + sumc(j, j + i);
               }
          }
          printf("%d\n", mem[0][k - 1]);
     }
     return 0;
}