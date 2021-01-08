#include <stdio.h>
#include <malloc.h>

/*
문제 : 종이에 3가지 숫자가 적혀있고, 종이를 계속 9등분 해서 같은 숫자만 적혀있는 종이를 만들 때 숫자 별로 종이의 갯수를 구한다.

해결 방법 : 종이의 숫자가 전부 같은 경우 탐색을 종료하고 서로 다른 경우 9등분하여 남은 종이들 각각을 탐색한다. 탐색이 전부 종료되면 종이의 갯수를 출력한다.

주요 알고리즘 : 분할 정복
*/

char v[3072][3072];
int count[3];

void maketree(int size, int posx, int posy) {
     int r = 1;
     int t = v[posx][posy];
     for (int i = posx; i < posx + size; i++) {
          for (int j = posy; j < posy + size; j++) {
               if (v[i][j] != t) {
                    r = 0;
                    break;
               }
          }
          if (r == 0) break;
     }

     if (r) {
          count[t + 1]++;
          return;
     }
     else {
          maketree(size / 3, posx, posy);
          maketree(size / 3, posx, posy + size / 3);
          maketree(size / 3, posx, posy + size / 3 * 2);
          maketree(size / 3, posx + size / 3, posy);
          maketree(size / 3, posx + size / 3, posy + size / 3);
          maketree(size / 3, posx + size / 3, posy + size / 3 * 2);
          maketree(size / 3, posx + size / 3 * 2, posy);
          maketree(size / 3, posx + size / 3 * 2, posy + size / 3);
          maketree(size / 3, posx + size / 3 * 2, posy + size / 3 * 2);
     }
}

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               scanf("%d", &v[i][j]);
          }
     }
     maketree(n, 0, 0);
     for (int i = 0; i < 3; i++) {
          printf("%d\n", count[i]);
     }
     return 0;
}