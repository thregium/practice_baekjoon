#include <stdio.h>

/*
문제 : 주어진 재귀함수를 효율적인 시간 안에 완료하도록 바꾼다.

해결 방법 : 메모이제이션을 이용해 같은 연산을 하는 횟수를 줄인다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int mem[32][32][32];

int w(int a, int b, int c) {
     if (a <= 0 || b <= 0 || c <= 0) return 1;
     if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
     if (mem[a][b][c]) return mem[a][b][c];
     if (a < b && b < c) return mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
     return mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(void) {
     while (1) {
          int a, b, c;
          scanf("%d %d %d", &a, &b, &c);
          if (a == -1 && b == -1 && c == -1) break;
          printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
     }
     return 0;
}