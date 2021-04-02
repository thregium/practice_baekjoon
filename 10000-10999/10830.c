#include <stdio.h>
#include <malloc.h>

typedef struct mat {
     int m[10][10];
} mat;

mat mati;

long long int mul2[64] = { 1, };

mat matmul(int n, mat x, mat y) {
     mat t = { 0, };
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               for (int k = 0; k < n; k++) t.m[i][j] = (t.m[i][j] + x.m[i][k] * y.m[k][j]) % 1000;
          }
     }
     return t;
}

mat matsqr(int n, mat x, int c) {
     if (c == 0) {
          for (int i = 0; i < n; i++) {
               for (int j = 0; j < n; j++) x.m[i][j] %= 1000;
          }
          return x;
     }
     else {
          mat y = matsqr(n, x, c - 1);
          return matmul(n, y, y);
     }
}

mat matbigmul(int n, mat x, long long int c) {
     for (int i = 62; i >= 0; i--) {
          if (c > mul2[i]) {
               return matmul(n, matsqr(n, x, i), matbigmul(n, x, c - mul2[i]));
          }
          else if (c == mul2[i]) {
               return matsqr(n, x, i);
          }
     }
}

int main(void) {
     int n;
     mat res;
     long long int b;
     for (int i = 1; i < 64; i++) mul2[i] = mul2[i - 1] * 2;
     scanf("%d %lld", &n, &b);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) scanf("%d", &mati.m[i][j]);
     }
     res = matbigmul(n, mati, b);
     //res = matmul(n, mati, mati);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) printf("%d ", res.m[i][j]);
          printf("\n");
     }
     return 0;
}