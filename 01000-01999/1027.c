#include <stdio.h>
#include <math.h>

/*
문제 : 수직선상에서 (i, 0)에서 시작하고, (i, Ai)에서 끝나는 선분이 N개(N < 50), (i < 10^9) 있다고 할 때,
다른 선분과 교차하지 않고 선분의 끝들끼리 가장 많이 이을 수 있는 선분을 구한다.

해결 방법 : ccw 알고리즘을 통해 한 점이 어떤 선분에 대해 어느 방향에 있는지를 정확하고 빠르게 구할 수 있다.
선분의 끝점끼리 선분을 이었을 때 중간에 ccw 값이 0 이상/이하(방향에 따라)인 지점이 있다면 선분이 교차한 것이다.

주요 알고리즘 : 기하학, ccw, 브루트 포스
*/

int max(int a, int b) {
     return a > b ? a : b;
}

int min(int a, int b) {
     return a < b ? a : b;
}

int main(void) {
     int n, s, t, r = 0;
     long long b[64];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%lld", &b[i]);
     for (int i = 0; i < n; i++) {
          s = 0;
          for (int j = 0; j < n; j++) {
			  //다른 모든 건물에 대해 검사
               t = 1;
               if (j == i) continue;
               for (int k = min(i, j) + 1; k < max(i, j); k++) {
                    if (j > i && (b[i] * j + b[j] * k + b[k] * i) - (b[j] * i + b[k] * j + b[i] * k) <= 0) {
						//오른쪽의 ccw값이 0 이하인 경우
                         t = 0;
                         break;
                    }
                    if (i > j && (b[i] * j + b[j] * k + b[k] * i) - (b[j] * i + b[k] * j + b[i] * k) >= 0) {
                         //왼쪽의 ccw값이 0 이상인 경우
						 t = 0;
                         break;
                    }
               }
               s += t;
               //printf("%d : %d = %d\n", i, j, t);
          }
          if (s > r) r = s;
     }
     printf("%d", r);
     return 0;
}