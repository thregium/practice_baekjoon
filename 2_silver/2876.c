#include <stdio.h>

int stu[102400][2], gra[102400][5];

int main(void) {
     int n, h = 0;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) {
          scanf("%d %d", &stu[i][0], &stu[i][1]);
          for (int j = 0; j < 5; j++) {
               if (j == stu[i][0] - 1 || j == stu[i][1] - 1) {
                    gra[i][j] = gra[i - 1][j] + 1;
                    if (gra[i][j] > gra[0][j]) gra[0][j] = gra[i][j];
               }
               else {
                    gra[i][j] = 0;
               }
          }
     }

     for (int i = 1; i < 5; i++) {
          if (gra[0][i] > gra[0][h]) h = i;
     }
     printf("%d %d", gra[0][h], h + 1);
     return 0;
}