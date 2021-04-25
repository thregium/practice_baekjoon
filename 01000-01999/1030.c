#include <stdio.h>

/*
문제 : 하얀 색인 전체 평면을 n*n개의 정사각형으로 나누고 중앙의 k*k개의 정사각형은 검게 칠한다. 이것을 s번 반복하였을 때 r1행 c1열에서 r2행 c2열까지의 결과를 출력한다.

해결 방법 : (r1, c1)부터 (r2, c2)까지의 좌표에 대해 (r, c)를 (n^(s-1))로 나눈 값을 n으로 나눈 나머지가 k 범위 안에 있다면 1을 반환하고 없다면 다시 s에서 1을 빼고 다시 반복한다.
여기서 k의 범위는 (n - k) / 2 <= r, c < (n + k) / 2이다. 그리고 s가 0이 된 경우에는 0을 반환한다.

주요 알고리즘 : 분할 정복
*/

int fractal(int s, int n, int k, int r, int c) {
     //해당 지점의 색상을 반환
	 if (s == 0) {
          return 0;
     }
     int rx = r, cx = c;
     for (int i = 1; i < s; i++) {
          rx /= n;
          cx /= n;
     }
     if (rx % n >= (n - k) / 2 && cx % n >= (n - k) / 2 && rx % n < (n + k) / 2 && cx % n < (n + k) / 2) {
          return 1;
     }
     else return fractal(s - 1, n, k, r, c);
}

int main(void) {
     int s, n, k, r1, r2, c1, c2;
     int res[60][60] = { 0, };
     scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);
     for (int r = r1; r <= r2; r++) {
          for (int c = c1; c <= c2; c++) {
               res[r - r1][c - c1] = fractal(s, n, k, r, c);
               printf("%d", res[r - r1][c - c1]);
          }
          printf("\n");
     }
     return 0;
}