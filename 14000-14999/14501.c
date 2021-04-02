#include <stdio.h>

/*
문제 : N일까지 각 일의 소요시간과 수익이 주어지고, 정확히 N일까지만 일을 한다고 할 때, 얻을 수 있는 최대 수익을 출력한다.

해결 방법 : 앞에서 했던 일의 결과가 수익에 영향을 주므로 M일부터 N일까지 일했을 때 얻을 수 있는 수익으로 나누어 생각한다.
이 값은 M+1일부터 N일까지 일했을 때의 수익(일을 하지 않았을 때), (M+소요시간) 일부터 N일까지 일했을 때의 수익 중 큰 값과 같다. M > N인 경우는 0으로 생각한다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int ti[1572864], pi[1572864];
int mem[1572864] = { 0, };

int big(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     int n;
     scanf("%d", &n);
     //if (n >= 1500000) return 1 / mem[0];
     for (int i = 0; i < n; i++) {
          scanf("%d %d", &ti[i], &pi[i]);
     }
     for (int i = n - 1; i >= 0; i--) {
          mem[i] = big(mem[i + 1], (i + ti[i] > n) ? 0 : (mem[i + ti[i]] + pi[i]));
     }
     printf("%d", mem[0]);
     return 0;
}