#include <stdio.h>

/*
���� : �� �� �� ������ �̼����� �󵵿� ����û������ ��ġ�� ��Ÿ�� �ִ�. �� �� �̼������� ���� 4�������� ��������, ����û���Ⱑ �ְų� �� �������� ��쿡�� ������ �ʴ´�.
�� ���� ������ ���� ���� �̼������� ����û���Ⱑ ����Ű�� �ٶ��� ���� Ư�� �������� �帣��, ����û����� ������ ��� �������.
���� �ð����� �� ���� �ݺ��ȴٰ� �� �� t �ð� �� �� ��ü�� �̼����� �󵵸� ���Ѵ�.

�ذ� ��� : ������ �ð����� �̼������� Ȯ��� ������ �帧�� ������ �̷�����Ƿ� ���� ������ �����Ѵ�.
Ȯ���� ���, �̸� ������ �󵵸� Ȯ���� ��, �� ������ Ȯ�� ���ο� ���� ������ �̼������� ������Ų��. Ȯ���� ������ ������ �������� ������ ���ϱ� ���� �ٸ� �޸𸮿� �����Ѵ�.
�帧�� ������ ���⸶�� ������ �帧�� ������ �̼������� �̵��� �����Ѵ�.
���������� �� ��ü�� �󵵸� Ȯ���� �� ����Ѵ�.

�ֿ� �˰��� : ����
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