#include <stdio.h>
#include <malloc.h>

/*
문제 : N(N <= 2^48)번째 피보나치 수를 10^9로 나눈 나머지를 구한다.

해결 방법 : 행렬 제곱을 이용해 구할 수 있다.

주요 알고리즘 : 수학, 행렬 거듭제곱

출처 : GNY 2015 C번
*/

typedef struct mat {
    long long int m[2][2];
} mat;

long long int mul2[64] = { 1, };

mat matmul(int l, int m, int n, mat x, mat y) {
    mat t = { 0, };
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) t.m[i][j] = (t.m[i][j] + x.m[i][k] * y.m[k][j]) % 1000000000;
        }
    }
    return t;
}

mat matsqr(int n, mat x, int c) {
    if (c == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) x.m[i][j] %= 1000000000;
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
    int p, k;
    long long n;
    mat unit, st, umul, res;
    for (int i = 1; i < 64; i++) mul2[i] = mul2[i - 1] * 2;
    unit.m[0][0] = 1;
    unit.m[0][1] = 1;
    unit.m[1][0] = 1;
    unit.m[1][1] = 0;
    st.m[0][0] = 1;
    st.m[1][0] = 0;
    //freopen("E:\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2015\\data\\c.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2015\\data\\c_t.out", "w", stdout);
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d %lld", &k, &n);
        umul = matbigmul(2, unit, n);
        res = matmul(2, 1, 2, umul, st);
        //res = matmul(n, mati, mati);
        printf("%d %lld\n", k, res.m[1][0]);
    }
    return 0;
}