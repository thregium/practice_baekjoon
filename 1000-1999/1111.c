#include <stdio.h>

/*
문제 : A[i] = A[i - 1] * a + b 꼴의 수열이 있다고 할 때, 수열이 주어지면 앞 형식인지 확인하고,
앞의 형식이라면 다음에 올 수를 구한다.

해결 방법 : 방정식을 통해 다음에 올 수의 후보를 줄이고 형식에 맞는지 확인한 후 다음에 올 수를 구한다.

주요 알고리즘 : 수학
*/

int main() {
     int n, a, b, p = 1, r = 0;
     int d[51] = { 0, };
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &d[i]);
     if (n > 2) {
		 //주어진 수가 3개 이상인 경우
          if (d[0] != d[1]) {
               a = (d[2] - d[1]) / (d[1] - d[0]);
               b = (d[0] * d[2] - d[1] * d[1]) / (d[0] - d[1]);
          }
          else if (d[2] == d[1]) {
               a = 1;
               b = 0;
          }
          else p = 0;
     }
     else if (n == 2 && d[1] == d[0]) {
		 //주어진 수가 2개이고 서로 같은 경우
          a = 1;
          b = 0;
     }
     else p = 2; //어떠한 수든 들어올 수 있는 경우
     for (int i = 2; i < n && p == 1; i++) {
          if (d[i] != d[i - 1] * a + b) p = 0;
     }
     if (p == 0) printf("B");
     else if (p == 2) printf("A");
     else printf("a : %d, b : %d, n : %d", a, b, d[n - 1] * a + b);
     return 0;
}