#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
문제 : 일직선상에 집들이 있고, 각각의 집들을 3가지 색으로 칠하는 비용이 각각 주어질 때,
이웃한 집들을 같은 색으로 칠하지 않으면서 모든 집을 칠할 수 있는 최소 비용을 출력한다.

해결 방법 : 다이나믹 프로그래밍을 통해 각 집을 마지막으로 칠한 색에 따른 최소 비용을 저장하고,
이전 집까지 칠할 때의 비용 가운데 이번 집과 색이 겹치지 않으면서 가장 싼 것에 현재 집을 선택한 색으로 칠하는 방법의 비용으로 업데이트한다.
이후, 마지막 집에서 3가지 색 가운데 가장 싼 것을 출력한다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int mem[1024][3];
int price[1024][3] = { {201, 3, 959}, {132, 607, 359}, {601, 775, 848}, {462, 776, 920}, {74, 807, 671} };
int t, t2, t3;

int lt(int x, int y) {
     return x < y ? x : y;
}

int rgb(int x) {
     for (int i = 0; i < 3; i++) mem[0][i] = price[0][i];
     for (int i = 1; i < x; i++) {
          mem[i][0] = lt(mem[i - 1][1], mem[i - 1][2]) + price[i][0];
          mem[i][1] = lt(mem[i - 1][0], mem[i - 1][2]) + price[i][1];
          mem[i][2] = lt(mem[i - 1][0], mem[i - 1][1]) + price[i][2];
     }
     return lt(lt(mem[x - 1][0], mem[x - 1][1]), mem[x - 1][2]);
}

int main(void) {
     int n, s = 0;
     srand(time(NULL));
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d %d %d", &price[i][0], &price[i][1], &price[i][2]);
          /*
          price[i][0] = rand() % 1000;
          price[i][1] = rand() % 1000;
          price[i][2] = rand() % 1000;
          srand(rand());
          */
     }
     //for (int i = 0; i < n; i++) printf("#%d : %d %d %d\n", i + 1, price[i][0], price[i][1], price[i][2]);
     printf("%d", rgb(n));
     return 0;
}