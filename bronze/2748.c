#include <stdio.h>

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
     int n;
     scanf("%d", &n);
     if (!n) printf("1 0");
     else printf("%d %d", fibo(n - 1), fibo(n));
     return 0;
}