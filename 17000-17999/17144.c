#include <stdio.h>

/*
문제 : 방 안 각 지점의 미세먼지 농도와 공기청정기의 위치가 나타나 있다. 방 안 미세먼지는 주위 4방향으로 퍼지지만, 공기청정기가 있거나 방 귀퉁이인 경우에는 퍼지지 않는다.
방 안의 먼지가 퍼진 다음 미세먼지는 공기청정기가 일으키는 바람에 따라 특정 방향으로 흐르고, 공기청정기로 들어오는 경우 사라진다.
단위 시간마다 위 일이 반복된다고 할 때 t 시간 후 방 전체의 미세먼지 농도를 구한다.

해결 방법 : 각각의 시간마다 미세먼지의 확산과 공기의 흐름이 별도로 이루어지므로 둘을 별도로 생각한다.
확산의 경우, 미리 지점의 농도를 확인한 후, 각 방향의 확산 여부에 따라 지점의 미세먼지를 증감시킨다. 확산이 완전히 끝나기 전까지는 간섭을 피하기 위해 다른 메모리에 저장한다.
흐름은 각각의 방향마다 공기의 흐름을 생각해 미세먼지의 이동을 구현한다.
마지막으로 방 전체의 농도를 확인한 후 출력한다.

주요 알고리즘 : 구현
*/

int room[64][64] = { 0, };
int next[64][64] = { 0, };

void diffusion(int r, int c) {
     for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
               int d = room[i][j];
               if (room[i][j] >= 0) {
                    if (i > 0 && room[i - 1][j] >= 0) {
                         d -= room[i][j] / 5;
                         d += room[i - 1][j] / 5;
                    }
                    if (j > 0 && room[i][j - 1] >= 0) {
                         d -= room[i][j] / 5;
                         d += room[i][j - 1] / 5;
                    }
                    if (i < r - 1 && room[i + 1][j] >= 0) {
                         d -= room[i][j] / 5;
                         d += room[i + 1][j] / 5;
                    }
                    if (j < c - 1 && room[i][j + 1] >= 0) {
                         d -= room[i][j] / 5;
                         d += room[i][j + 1] / 5;
                    }
               }
               next[i][j] = d;
          }
     }
     
     for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) room[i][j] = next[i][j];
     }
}

void clean(int r, int c, int cln) {
     for (int i = 1; i < r - 1; i++) {
          if (i < cln) {
               next[i][0] = room[i - 1][0];
          }
          else if(i > cln + 1) {
               next[i][0] = room[i + 1][0];
          }
     }
     for (int i = 0; i < c - 1; i++) {
          next[0][i] = room[0][i + 1];
          next[r - 1][i] = room[r - 1][i + 1];
     }
     for (int i = 0; i < r; i++) {
          if (i < cln) {
               next[i][c - 1] = room[i + 1][c - 1];
          }
          else if (i > 0 && i > cln + 1) {
               next[i][c - 1] = room[i - 1][c - 1];
          }
     }
     for (int i = 2; i < c; i++) {
          next[cln][i] = room[cln][i - 1];
          next[cln + 1][i] = room[cln + 1][i - 1];
     }
     next[cln][1] = 0;
     next[cln + 1][1] = 0;
     next[cln][0] = -1;
     next[cln + 1][0] = -1;
     for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
               //if(i == 0 || i == r - 1 || j == 0 || j == c - 1 || j == cln || j == cln + 1) room[i][j] = next[i][j];
               room[i][j] = next[i][j];
          }
     }
}

int main(void) {
     int r, c, t, cln = 2;
     scanf("%d %d %d", &r, &c, &t);
     for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) scanf("%d", &room[i][j]);
     }
     for (int i = 0; i < r; i++) {
          if (room[i][0] < 0) {
               cln = i;
               break;
          }
     }

     
     for (int i = 0; i < t; i++) {
          diffusion(r, c);
          clean(r, c, cln);
          /*
          int dust = 0;
          printf("\n");
          for (int i = 0; i < r; i++) {
               for (int j = 0; j < c; j++) {
                    printf("%d ", room[i][j]);
                    if (room[i][j] > 0) dust += room[i][j];
               }
               printf("\n");
          }
          printf("%d", dust);
          */
     }
     
     int dust = 0;
     for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
               //printf("%d ", room[i][j]);
               if(room[i][j] > 0) dust += room[i][j];
          }
          //printf("\n");
     }
     printf("%d", dust);
     
     return 0;
}