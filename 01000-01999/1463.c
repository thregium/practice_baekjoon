#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^6)이 주어질 때, N을 3으로 나누거나 2로 나누거나 1을 빼는 연산을 해서
1로 만들기 위해 필요한 최소 연산 횟수를 구한다.

해결 방법 : 연산을 할 때마다 수가 감소하므로 1부터 N까지 순서대로 올라가며 -1, /2, /3 중 가장 작은 값에 1을 더해 확인하는 방식으로 풀면 된다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int m[1048576];

int min(int a, int b) {
     return a < b ? a : b;
}

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) {
          if (i == 1) m[i] = 0;
          else {
               if (i % 3 == 0 && i % 2 == 0) m[i] = min(min(m[i / 3], m[i / 2]), m[i - 1]) + 1; //2와 3으로 나누어지는 경우
               else if (i % 3 == 0) m[i] = min(m[i / 3], m[i - 1]) + 1; //3으로 나누어지는 경우
               else if (i % 2 == 0) m[i] = min(m[i / 2], m[i - 1]) + 1; //2로 나누어지는 경우
               else m[i] = m[i - 1] + 1; //나누어지지 않는 경우
          }
     }
     printf("%d", m[n]);
     return 0;
}