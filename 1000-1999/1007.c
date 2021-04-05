#include <stdio.h>
#include <math.h>

/*
문제 : 짝수개의 점(N <= 20)이 주어질 때, 이 점들을 전부 매칭해서 만든 벡터 합의 길이 가운데 최솟값을 구한다.

해결 방법 : 브루트 포스로 모든 점의 조합에 대해 검사하고, 벡터 합이 가장 작은 것을 출력한다.

주요 알고리즘 : 브루트 포스, 백트래킹, 기하학
*/

int cm[32], a[100][2];
double small;

void track(int n, int m, int x) {
     if (m == x) {
          int ax = 0, ay = 0, bx = 0, by = 0, c;
          for (int i = 0; i < n; i++) {
               c = 0;
               for (int j = 0; j < m; j++) {
                    if (cm[j] == i + 1) {
                         c = 1;
                         break;
                    }
               }
               if (c) {
                    ax += a[i][0];
                    ay += a[i][1];
               }
               else {
                    bx += a[i][0];
                    by += a[i][1];
               }
          }
		  //모든 벡터의 x성분과 y성분을 시작점, 끝점으로 나누어 각각 저장한다.
          double v = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
		  //저장한 각각의 성분을 끝점 - 시작점의 x성분과 y성분에 피타고라스 정리를 하여 합벡터의 크기를 구한다.
          if (v < small) small = v;
          return;
     }
     for (int i = 1; i <= n; i++) {
          if (x > 0 && i <= cm[x - 1]) continue;
          //printf("cm[%d] = %d\n", x, i);
          cm[x] = i;
          track(n, m, x + 1);
     }
}

int main(void) {
     int t, n;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d", &n);
          for (int j = 0; j < n; j++) {
               scanf("%d %d", &a[j][0], &a[j][1]);
          }
          small = 100000000.0;
          for (int j = 0; j < 32; j++) cm[j] = 0;
          track(n, n / 2, 0);
          printf("%.8lf\n", small);
     }
     return 0;
}