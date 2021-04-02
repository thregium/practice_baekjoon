#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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