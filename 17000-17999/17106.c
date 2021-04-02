#include <stdio.h>

/*
문제 : 주어진 빙고 칸에 있는 조건이 참이면 색칠하고 거짓이면 색칠하지 않는다고 할 때 이를 만족하는 빙고 판의 결과를 출력한다.

해결 방법 : 경우의 수가 충분히 적으므로 브루트 포스 알고리즘을 통해 칸마다의 모든 조건을 확인한다.

주요 알고리즘 : 브루트 포스
*/

int res[512], cell[25], bcell[25], bingo[12];
int alldir, colored, bingos, bcells, bcolors, count = 0;

int xor (int a, int b) {
     return ((a && !b) || (!a && b));
}

int main(void) {
     for (int i = 0; i < (1 << 25); i++) {
          colored = 0;
          for (int j = 0; j < 25; j++) {
               cell[j] = !!(i & 1 << j);
               colored += cell[j];
          }

          bingo[0] = cell[24] && cell[23] && cell[22] && cell[21] && cell[20]; // 1행
          bingo[1] = cell[19] && cell[18] && cell[17] && cell[16] && cell[15]; // 2행
          bingo[2] = cell[14] && cell[13] && cell[12] && cell[11] && cell[10]; // 3행
          bingo[3] = cell[9] && cell[8] && cell[7] && cell[6] && cell[5]; // 4행
          bingo[4] = cell[4] && cell[3] && cell[2] && cell[1] && cell[0]; // 5행
          bingo[5] = cell[24] && cell[19] && cell[14] && cell[9] && cell[4]; // A열
          bingo[6] = cell[23] && cell[18] && cell[13] && cell[8] && cell[3]; // B열
          bingo[7] = cell[22] && cell[17] && cell[12] && cell[7] && cell[2]; // C열
          bingo[8] = cell[21] && cell[16] && cell[11] && cell[6] && cell[1]; // D열
          bingo[9] = cell[20] && cell[15] && cell[10] && cell[5] && cell[0]; // E열
          bingo[10] = cell[24] && cell[18] && cell[12] && cell[6] && cell[0]; // \형 대각선
          bingo[11] = cell[20] && cell[16] && cell[12] && cell[8] && cell[4]; // /형 대각선

          bingos = 0;
          for (int j = 0; j < 12; j++) {
               bingos += bingo[j];
          }

          alldir = (bingo[0] || bingo[1] || bingo[2] || bingo[3] || bingo[4]) && (bingo[5] || bingo[6] || bingo[7] || bingo[8] || bingo[9]) && (bingo[10] || bingo[11]);

          bcell[24] = (bingo[0] || bingo[5] || bingo[10]);
          bcell[23] = (bingo[0] || bingo[6]);
          bcell[22] = (bingo[0] || bingo[7]);
          bcell[21] = (bingo[0] || bingo[8]);
          bcell[20] = (bingo[0] || bingo[9] || bingo[11]);
          bcell[19] = (bingo[1] || bingo[5]);
          bcell[18] = (bingo[1] || bingo[6] || bingo[10]);
          bcell[17] = (bingo[1] || bingo[7]);
          bcell[16] = (bingo[1] || bingo[8] || bingo[11]);
          bcell[15] = (bingo[1] || bingo[9]);
          bcell[14] = (bingo[2] || bingo[5]);
          bcell[13] = (bingo[2] || bingo[6]);
          bcell[12] = (bingo[2] || bingo[7] || bingo[10] || bingo[11]);
          bcell[11] = (bingo[2] || bingo[8]);
          bcell[10] = (bingo[2] || bingo[9]);
          bcell[9] = (bingo[3] || bingo[5]);
          bcell[8] = (bingo[3] || bingo[6] || bingo[11]);
          bcell[7] = (bingo[3] || bingo[7]);
          bcell[6] = (bingo[3] || bingo[8] || bingo[10]);
          bcell[5] = (bingo[3] || bingo[9]);
          bcell[4] = (bingo[4] || bingo[5] || bingo[11]);
          bcell[3] = (bingo[4] || bingo[6]);
          bcell[2] = (bingo[4] || bingo[7]);
          bcell[1] = (bingo[4] || bingo[8]);
          bcell[0] = (bingo[4] || bingo[9] || bingo[10]);

          bcells = 0;
          bcolors = 0;
          for (int j = 0; j < 25; j++) {
               bcells += bcell[j];
               bcolors += (!bcell[j] && cell[j]);
          }


          if (xor(cell[24], !bingo[11])) continue;
          if (xor(cell[23], !bcell[23])) continue;
          if (xor(cell[22], bingo[10])) continue;
          if (xor(cell[21], cell[6])) continue;
          if (xor(cell[20], bcell[20])) continue;
          if (xor(cell[19], !cell[9])) continue;
          if (xor(cell[18], alldir)) continue;
          //17번은 모든 경우에 가능
          if (xor(cell[16], (colored <= 17))) continue;
          if (xor(cell[15], !(bcells % 2))) continue;
          if (xor(cell[14], bcell[14])) continue;
          if (xor(cell[13], (bcolors >= 5))) continue;
          if (xor(cell[12], (!cell[12] || bcell[12]))) continue;
          if (xor(cell[11], (bingo[5] + bingo[6] + bingo[7] + bingo[8] + bingo[9] >= 2))) continue;
          if (xor(cell[10], (bcells >= 10))) continue;
          //if (((i & 1 << 9) && i & 1 << 19) || (!(i & 1 << 9) && !(i & 1 << 19))) continue; 19번과 동일
          if (xor(cell[8], (bingo[1] || bingo[8]))) continue;
          if (xor(cell[7], (cell[22] + cell[17] + cell[12] + cell[7] + cell[2] <= 3))) continue;
          //if (((i & 1 << 6) && !(i & 1 << 21)) || (!(i & 1 << 6) && (i & 1 << 21))) continue; 21번과 동일
          if (xor(cell[5], (bingo[10] || bingo[11]))) continue;
          if (xor(cell[4], cell[0])) continue;
          //3번 확인 불가
          if (xor(cell[2], cell[2])) continue;
          if (xor(cell[1], (bingos >= 3))) continue;
          //if (((i & 1) && !(i & 1 << 4)) || (!(i & 1) && (i & 1 << 4))) continue; 4번과 동일


          res[count++] = i;
     }


     for (int i = 0; i < count; i++) {
          for (int j = 4; j >= 0; j--) {
               for (int k = 4; k >= 0; k--) {
                    printf("%c", (res[i] & (1 << (j * 5 + k))) ? '#' : '.');
               }
               printf("\n");
          }
          printf("\n");
     }

     return 0;
}