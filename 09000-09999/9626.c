#include <stdio.h>

/*
문제 : M * N(M, N <= 10) 크기의 크로스워드 주위의 위쪽 U칸, 왼쪽 L칸, 오른쪽 R칸, 아래쪽 D(U, L, R, D <= 5)칸을
체스판 무늬로 채운 형태를 출력한다.

해결 방법 : (M + U + D) * (N + L + R) 크기의 체스판을 출력하되, U행부터 U + M행 전까지의 L열부터 L + N열 전까지 구간은
해당하는 문자를 출력한다. 또는 그 구간에서 L열일 때만 문자열을 출력하는 방법도 있다.

주요 알고리즘 : 구현

출처 : COCI 13/14#3 2번
*/

char cw[16][16];

int main(void) {
    int m, n, u, l, r, d;
    scanf("%d %d%d %d %d %d", &m, &n, &u, &l, &r, &d);
    for (int i = 0; i < m; i++) {
        scanf("%s", cw[i]);
    }
    for (int i = 0; i < m + u + d; i++) {
        for (int j = 0; j < n + l + r; j++) {
            if (i >= u && i < u + m && j >= l && j < l + n) {
                if (j == l) printf("%s", cw[i - u]);
                else continue;
            }
            else printf("%c", ((i + j) & 1) ? '.' : '#');
        }
        printf("\n");
    }
    return 0;
}