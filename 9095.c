#include <stdio.h>

/*
문제 : 입력으로 들어오는 숫자 N을 1, 2, 3의 합만으로 만들 수 있는 가짓수를 구하여라.

해결 방법 : N을 1, 2, 3의 합만으로 만드는 가짓수는 (N - 1) + 1, (N - 2) + 2, (N - 3) + 3의 3가지가 있고, 이는 N - 1, N - 2, N - 3의 가짓수의 합과 같으므로
다이나믹 프로그래밍을 통해 만들 수 있다. 이때 초기항은 1(n == 1), 2(n == 2), 4(n == 3)이다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int mem[16] = { 0, };

int getres(int n) {
     if (mem[n]) return mem[n];
     if (n == 1) return 1;
     if (n == 2) return 2;
     if (n == 3) return 4;
     int a = getres(n - 1) + getres(n - 2) + getres(n - 3);
     mem[n] = a;
     return a;
}

int main(void) {
     int t, n;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d", &n);
          printf("%d\n", getres(n));
     }
     return 0;
}