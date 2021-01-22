#include <stdio.h>

/*
문제 : 빨간 구슬과 파란 구슬, 구멍, 벽으로 이루어진 구슬 퍼즐이 있다. 퍼즐을 기울여 빨간 구슬을 구멍에 넣으면 성공이고, 파란 구슬이 들어가면 실패이다.
두 구슬이 동시에 들어가도 실패라고 할 때, 퍼즐을 성공하기 위해 최소로 필요한 이동 횟수를 출력한다. (단, 퍼즐의 크기는 10*10 이하이고, 퍼즐의 가장자리는 전부 벽이며,
빨간 구슬과 파란 구슬, 구멍은 전부 각각 1개씩이다.)

해결 방법 : 브루트 포스를 통해 가능한 모든 빨간 구슬과 파란 구슬의 위치에서 상하좌우 4 방향으로 이동했을 때의 빨간 구슬과 파란 구슬의 위치를 구한다.
각각의 위치를 정점, 이동시 위치와의 관계를 간선으로 잡고 그래프 형태로 구슬의 위치들을 만든다.
첫 구슬의 위치를 큐에 넣고 BFS를 통해 그래프를 순회하다가 10회 이내에 퍼즐을 성공한 경우 횟수를 출력하고, 10회동안 성공하지 못한 경우 -1을 출력한다.

주요 알고리즘 : 브루트 포스, 구현, 그래프 이론, BFS
*/

int marble[4096][4]; //[i] / 64 = 빨간 구슬의 좌표, [i] % 64 = 파란 구슬의 좌표, [j] = {0 : 위쪽, 1 : 오른쪽, 2 : 아래쪽, 3 : 왼쪽}
char map[16][16]; //처음 상태
int rs[2], bs[2], rt[2], bt[2]; //각 구슬의 시작, 임시 좌표
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int q[1048576]; //큐
qf = 0, qr = 0;
int chk[4096];

int track(int s) {
     q[qr++] = s;
     int d = 0, t, qs, f = 0; //d : 움직인 횟수, t : 큐에서 빼낸 값, qs : 한 바퀴 돌았을 때의 큐의 크기, f : 종료 여부 확인
     while (qr - qf) {
          qs = qr - qf;
          while (qs) {
               t = q[qf++];
               if (t == -1) {
                    qs--;
                    continue;
               }

               if (chk[t]) {
                    qs--;
                    continue;
               }
               else {
                    chk[t] = 1;
               }
               if (t == 10000) {
                    f = 1;
                    break;
               }
               for (int i = 0; i < 4; i++) {
                    if (marble[t][i]) {
                         q[qr++] = marble[t][i];
                    }
               }
               qs--;
          }
          if (f) {
               break;
          }
          d++;
          if (d > 10) {
               return -1;
          }
     }
     if (f) return d;
     else return -1;
}

int main(void) {
     int n, m, rf, bf;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          scanf("%s", map[i]);
          for (int j = 0; j < m; j++) {
               if (map[i][j] == 'R') {
                    rs[0] = i;
                    rs[1] = j;
                    map[i][j] = '.';
               }
               if (map[i][j] == 'B') {
                    bs[0] = i;
                    bs[1] = j;
                    map[i][j] = '.';
               }
          }
     }
     for (int i = 0; i < n - 2; i++) {
          for (int j = 0; j < m - 2; j++) {
               for (int k = 0; k < n - 2; k++) {
                    for (int l = 0; l < m - 2; l++) {
                         //각 구슬 위치에 따라 다음 행동의 구슬 위치 확인
                         if (i * 8 + j == k * 8 + l) continue;
                         if (map[i + 1][j + 1] != '.' || map[k + 1][l + 1] != '.') continue;
                         //구슬 위치가 될 수 없으면 생략
                         for (int v = 0; v < 4; v++) {
                              rt[0] = i + 1;
                              rt[1] = j + 1;
                              bt[0] = k + 1;
                              bt[1] = l + 1;
                              rf = 0;
                              bf = 0;

                              if ((v == 0 && i < k) || (v == 1 && j > l) || (v == 2 && i > k) || (v == 3 && j < l)) {
                                   //빨간 구슬이 먼저일 경우
                                   while (map[rt[0] + dx[v]][rt[1] + dy[v]] == '.') {
                                        if (v == 0) rt[0]--;
                                        if (v == 1) rt[1]++;
                                        if (v == 2) rt[0]++;
                                        if (v == 3) rt[1]--;
                                   }
                                   if (map[rt[0] + dx[v]][rt[1] + dy[v]] == 'O') rf = 1;
                                   else map[rt[0]][rt[1]] = 'R';
                                   while (map[bt[0] + dx[v]][bt[1] + dy[v]] == '.') {
                                        if (v == 0) bt[0]--;
                                        if (v == 1) bt[1]++;
                                        if (v == 2) bt[0]++;
                                        if (v == 3) bt[1]--;
                                   }
                                   if (map[bt[0] + dx[v]][bt[1] + dy[v]] == 'O') bf = 1;

                                   map[rt[0]][rt[1]] = '.';
                              }
                              else {
                                   //파란 구슬이 먼저일 경우
                                   while (map[bt[0] + dx[v]][bt[1] + dy[v]] == '.') {
                                        if (v == 0) bt[0]--;
                                        if (v == 1) bt[1]++;
                                        if (v == 2) bt[0]++;
                                        if (v == 3) bt[1]--;
                                   }
                                   if (map[bt[0] + dx[v]][bt[1] + dy[v]] == 'O') bf = 1;
                                   else map[bt[0]][bt[1]] = 'B';
                                   while (map[rt[0] + dx[v]][rt[1] + dy[v]] == '.') {
                                        if (v == 0) rt[0]--;
                                        if (v == 1) rt[1]++;
                                        if (v == 2) rt[0]++;
                                        if (v == 3) rt[1]--;
                                   }
                                   if (map[rt[0] + dx[v]][rt[1] + dy[v]] == 'O') rf = 1;

                                   map[bt[0]][bt[1]] = '.';
                              }

                              if (bf) {
                                   marble[i * 512 + j * 64 + k * 8 + l][v] = -1; //실패인 경우
                              }
                              else if (rf) {
                                   marble[i * 512 + j * 64 + k * 8 + l][v] = 10000; //성공인 경우
                              }
                              else {
                                   marble[i * 512 + j * 64 + k * 8 + l][v] = (rt[0] - 1) * 512 + (rt[1] - 1) * 64 + (bt[0] - 1) * 8 + (bt[1] - 1); //그 외인 경우
                              }
                         }
                    }
               }
          }
     }

     printf("%d", track((rs[0] - 1) * 512 + (rs[1] - 1) * 64 + (bs[0] - 1) * 8 + (bs[1] - 1)));

     return 0;
}