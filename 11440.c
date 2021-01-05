#include <stdio.h>
#include <malloc.h>

typedef struct mat {
     long long int m[2][2];
} mat;

long long int mul2[64] = { 1, };

mat matmul(int l, int m, int n, mat x, mat y) {
     mat t = { 0, };
     for (int i = 0; i < l; i++) {
          for (int j = 0; j < m; j++) {
               for (int k = 0; k < n; k++) t.m[i][j] = (t.m[i][j] + x.m[i][k] * y.m[k][j]) % 1000000007;
          }
     }
     return t;
}

mat matsqr(int n, mat x, int c) {
     if (c == 0) {
          for (int i = 0; i < n; i++) {
               for (int j = 0; j < n; j++) x.m[i][j] %= 1000000007;
          }
          return x;
     }
     else {
          mat y = matsqr(n, x, c - 1);
          return matmul(n, n, n, y, y);
     }
}

mat matbigmul(int n, mat x, long long int c) {
     for (int i = 62; i >= 0; i--) {
          if (c > mul2[i]) {
               return matmul(n, n, n, matsqr(n, x, i), matbigmul(n, x, c - mul2[i]));
          }
          else if (c == mul2[i]) {
               return matsqr(n, x, i);
          }
     }
}

int main(void) {
     long long int n, a, b;
     mat unit, st, umul, res;
     for (int i = 1; i < 64; i++) mul2[i] = mul2[i - 1] * 2;
     scanf("%lld", &n);
     unit.m[0][0] = 1;
     unit.m[0][1] = 1;
     unit.m[1][0] = 1;
     unit.m[1][1] = 0;
     st.m[0][0] = 1;
     st.m[1][0] = 0;
     umul = matbigmul(2, unit, n);
     res = matmul(2, 1, 2, umul, st);
     //res = matmul(n, mati, mati);
     a = res.m[1][0];
     umul = matbigmul(2, unit, n + 1);
     res = matmul(2, 1, 2, umul, st);
     //res = matmul(n, mati, mati);
     b = res.m[1][0];
     printf("%lld", a * b % 1000000007);
     return 0;
}