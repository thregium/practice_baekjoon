#include <stdio.h>
#include <malloc.h>

typedef struct mat {
     long long int m[2][2];
} mat;

long long int mul2[64] = { 1, };

long long int gcd(long long int a, long long int b) {
     if (a == 0) return b;
     if (b == 0) return a;
     if (a > b) return gcd(a % b, b);
     else return gcd(a, b % a);
}

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
     long long int n, m;
     mat unit, st, umul, res;
     for (int i = 1; i < 64; i++) mul2[i] = mul2[i - 1] * 2;
     scanf("%lld %lld", &n, &m);
     unit.m[0][0] = 1;
     unit.m[0][1] = 1;
     unit.m[1][0] = 1;
     unit.m[1][1] = 0;
     st.m[0][0] = 1;
     st.m[1][0] = 0;
     umul = matbigmul(2, unit, gcd(n, m));
     res = matmul(2, 1, 2, umul, st);
     //res = matmul(n, mati, mati);
     printf("%lld", res.m[1][0]);
     return 0;
}