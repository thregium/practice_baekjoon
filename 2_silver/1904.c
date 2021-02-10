#include <stdio.h>

int mem[1024000];
int chk[1024000] = { 0, };
int z = 0, o = 0;

int tile(int x) {
     if (chk[x]) return mem[x];
     if (x == 0) {
          chk[0] = 1;
          mem[0] = 1;
          z++;
          return 1;
     }
     if (x == 1) {
          chk[1] = 1;
          mem[1] = 1;
          o++;
          return 1;
     }
     chk[x] = 1;
     return mem[x] = (tile(x - 1) % 15746 + tile(x - 2) % 15746) % 15746;
}

int main(void) {
     int n;
     scanf("%d", &n);
     printf("%d", tile(n));
     return 0;
}