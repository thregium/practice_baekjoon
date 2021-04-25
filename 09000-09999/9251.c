#include <stdio.h>
#include <string.h>

char a1[1024], a2[1024];
int am[1024][1024] = { 0, };

int max(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     scanf("%s%s", &a1, &a2);
     for (int i = 0; i < strlen(a1); i++) {
          for (int j = 0; j < strlen(a2); j++) {
               if (a1[i] == a2[j]) am[i + 1][j + 1] = am[i][j] + 1;
               else am[i + 1][j + 1] = max(am[i + 1][j], am[i][j + 1]);
          }
     }
     printf("%d", am[strlen(a1)][strlen(a2)]);
     return 0;
}