#include <stdio.h>

/*
문제 : 
int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
다음과 같은 함수에서 0과 1의 출력 횟수를 구한다.

해결 방법 : 메모이제이션을 통해 각 함수에서 0의 출력 횟수와 1의 출력 횟수를 기억한 뒤 해당 함수들을 호출 할 때에는
실제로 함수를 호출하지 않고 0의 출력 횟수와 1의 출력 횟수만 추가한다.

주요 알고리즘 : 다이나믹 프로그래밍
*/

int mem[100];
int chk[100] = { 0, };
int z = 0, o = 0;

int fibo(int x) {
     if (chk[x]) return mem[x];
     if (x == 0) {
          chk[0] = 1;
          mem[0] = 0;
          z++;
          return 0;
     }
     if (x == 1) {
          chk[1] = 1;
          mem[1] = 1;
          o++;
          return 1;
     }
     chk[x] = 1;
     return mem[x] = fibo(x - 1) + fibo(x - 2);
}

int main(void) {
     int n, t;
     scanf("%d", &n);
     for(int i = 0; i < n; i++) {
         scanf("%d", &t);
         if (!t) printf("1 0\n");
         else printf("%d %d\n", fibo(t - 1), fibo(t));
     }
     return 0;
}