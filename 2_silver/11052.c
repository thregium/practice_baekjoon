#include <stdio.h>

/*
문제 : n과 각각의 p[i](i <= n)의 값이 주어질 때 i의 합을 n으로 맞출 수 있는 i의 조합 가운데 p[i]의 합이 가장 큰 조합의 p[i]의 합을 구한다.

해결 방법 : n의 값이 m일 때로 부분 문제를 정의한다. 이때 f(m)의 값은 M(f(m - 1) + p[1], f(m - 2) + p[2], ... f(m - m) + p[m])이 된다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int p[1024], mem[1024];

int main(void) {
     int n, l;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) {
          scanf("%d", &p[i]);
          l = 0;
          for (int j = 1; j <= n; j++) {
               if (i >= j && mem[i - j] + p[j] > l) l = mem[i - j] + p[j];
          }
          mem[i] = l;
     }
     printf("%d", mem[n]);
     return 0;
}