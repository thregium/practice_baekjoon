#include <stdio.h>

long long int mem[256];
int chk[256] = { 0, };

long long int pa(int x) {
     if (chk[x]) return mem[x];
     if (x == 0) {
          chk[0] = 1;
          mem[0] = 0;
          return 0;
     }
     if (x == 1) {
          chk[1] = 1;
          mem[1] = 1;
          return 1;
     }
     if (x == 2) {
          chk[2] = 1;
          mem[2] = 1;
          return 1;
     }
     chk[x] = 1;
     return mem[x] = pa(x - 2) + pa(x - 3);
}

int main(void) {
     int n, t;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &t);
          printf("%lld\n", pa(t));
     }
     return 0;
}