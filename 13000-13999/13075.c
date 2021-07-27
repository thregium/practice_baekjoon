#include <stdio.h>
#include <malloc.h>

/*
문제 : 자연수 N(N <= 2^48)이 주어질 때, N번째 피보나치 수를 출력한다.

해결 방법 : 행렬 제곱을 이용해 계산하면 된다.

주요 알고리즘 : 수학, 분할 거듭제곱

출처 : IIPC 2015 C번
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
    int t;
    long long int n;
    mat unit, st, umul, res;
    for (int i = 1; i < 64; i++) mul2[i] = mul2[i - 1] * 2;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
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
        printf("%lld\n", res.m[1][0]);
    }
    return 0;
}