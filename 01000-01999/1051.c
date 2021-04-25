#include <stdio.h>

/*
문제 : N * M 크기의 직사각형에 한 자리 숫자들이 적혀있을 때, 네 꼭짓점에 모두 같은 숫자가 적혀있는 정사각형 가운데 가장 큰 것을 구한다. (N, M <= 50)

해결 방법 : N과 M의 제한이 크지 않으므로 브루트 포스를 통해 모든 정사각형 후보들을 확인해본다.

주요 알고리즘 : 브루트 포스
*/

int small(int a, int b) {
     return a < b ? a : b;
}

int maxsquare(int n, int m, char a[64][64]) {
     for (int z = small(n, m); z >= 1; z--) {
		 //큰 정사각형부터 확인한다.
          for (int i = 0; i < n - (z - 1); i++) {
               for (int j = 0; j < m - (z - 1); j++) {
                    if (a[i][j] == a[i][j + (z - 1)] && a[i][j] == a[i + (z - 1)][j] && a[i][j] == a[i + (z - 1)][j + (z - 1)]) {
                         //네 꼭짓점이 모두 같은 경우 해결되었으므로 바로 값을 반환하고 함수를 종료한다.
						 return z * z;
                    }
               }
          }
     }
}

int main(void) {
     int n, m;
     char a[64][64];
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          scanf("%s", a[i]);
     }
     printf("%d", maxsquare(n, m, a));
     return 0;
}