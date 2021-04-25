#include <stdio.h>
#include <malloc.h>

/*
문제 : 건물 w를 지어야 승리하는 게임이 있다고 한다. 그런데 어떠한 건물 y를 짓기 위해서는 선행하는 건물 x를 모두 지어야 한다.
건물은 동시에 건설 가능하고, 건물을 짓는 사이에 지체되는 시간은 없다고 가정하고, 각각의 건물을 짓는 시간과 건설 순서 규칙이 주어질 때 w를 짓는데 걸리는 최소 시간을 구한다.

해결 방법 : w를 짓는데 걸리는 시간은 w의 선행 건물들을 짓는데 걸리는 시간 가운데 가장 긴 시간 + w를 짓는데 걸리는 시간이다.
이를 이용해 w의 선행 건물들을 선행 건물이 없을 때까지 각각 탐색한 후 최댓값을 구해 w를 짓는데 걸리는 시간을 구할 수 있다.

주요 알고리즘 : 그래프 탐색, 다이나믹 프로그래밍
*/

typedef struct building {
     int d; //이 건물의 건설 시간
     int c; //이 건물까지의 건설시간
     int prevs;
     int nexts;
     struct building* prev[1024];
     struct building* next[1024];
} building;

building* allb[1024]; //각 건물들의 정보 저장

int build(building* w) {
     if (w->c >= 0) return w->c; //이 건물까지의 건설시간이 정해진 경우
     int t = 0;
     for (int i = 0; i < w->prevs; i++) {
          if(build(w->prev[i]) > t) t = build(w->prev[i]); //이전 건물까지의 건설시간 가운데 가장 큰 것을 선택
     }
     return w->c = t + w->d;
}

int main(void) {
     int t, n, k, x, y, w;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          for (int i = 0; i < 1024; i++) {
               //if (!tt) {
                    building* bt;
                    bt = calloc(1, sizeof(building));
                    allb[i] = bt;
               //}
               allb[i]->c = -1;
          }
          scanf("%d %d", &n, &k);
          for (int i = 1; i <= n; i++) {
               scanf("%d", &allb[i]->d);
          }
          for (int i = 1; i <= k; i++) {
               int a, b;
               scanf("%d %d", &x, &y);

               allb[x]->next[allb[x]->nexts] = allb[y];
               allb[x]->nexts++;
               allb[y]->prev[allb[y]->prevs] = allb[x];
               allb[y]->prevs++;
			   //건설 순서 정보 저장
          }
          scanf("%d", &w);
          printf("%d\n", build(allb[w]));
          for (int i = 0; i < 1024; i++) free(allb[i]);
     }
     //for (int i = 0; i < 1024; i++) free(allb[i]);
     return 0;
}
