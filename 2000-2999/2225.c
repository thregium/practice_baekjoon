#include <stdio.h>

/*
문제 : 0부터 N까지의 정수 가운데 합이 N이 되는 K개를 선택하는 가짓수를 구한다. 이때 같은 수를 여러 번 사용할 수 있고, 순서만 다른 것도 다른 것으로 친다.

해결 과정 : N이 0인 경우 몇개를 선택하든 0만 선택할 수 있으므로 1가지이고, K가 1인 경우는 N 한개만 선택 가능하므로 1가지이다.
그 외의 경우는 N - 1, K인 경우와 N, K - 1인 경우의 합이라는 점을 이용해 구할 수 있다.

주요 알고리즘 : 조합, 다이나믹 프로그래밍
*/

int mem[256][256];

int combi(int n, int k) {
     if (mem[n][k]) return mem[n][k];
     if (n == 0) return mem[n][k] = 1;
     if (k == 1) return mem[n][k] = 1;
     return mem[n][k] = (combi(n - 1, k) + combi(n, k - 1)) % 1000000000;
}

int main(void) {
     int n, k;
     scanf("%d %d", &n, &k);
     if (n > 0 && k > 0) printf("%d", combi(n, k));
     return 0;
}