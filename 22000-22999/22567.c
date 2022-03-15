#include <stdio.h>

/*
문제 : N * N(N <= 500) 크기의 빙고 판에 두 명이 10^6 이하의 서로 다른 자연수들을 썼다.
두 명은 각각 U, V(U, V <= 13) 개의 줄이 완성되면 이긴다. M(M <= 10^6)개의 서로 다른 자연수(<= 10^6)들이
주어질 때, 해당 순서로 수들이 불리면 누가 이기는지 또는 비기는 지 구한다.

해결 방법 : 각 칸에 쓰인 수들을 입력받으면서 그 수에 해당하는 줄들을 전부 기록해둔다.
수의 범위가 작기 때문에 이것이 가능하다.
그 다음에는 수들이 주어질 때 마다 두 명의 그 수에 해당하는 줄들에 불린 수들의 개수를 갱신한다.
그 개수가 N개가 되는 줄들의 개수를 구하고 이 줄 수가 U, V가 되는 지 여부에 따라 답을 구하면 된다.
단, N이 1일 때에는 중복되는 줄을 기록하지 않아야 함에 유의한다.

주요 알고리즘 : 구현, 시뮬레이션, 애드 혹?

출처 : JAG 2010S3 J번
*/

int usm[512][512], nkm[512][512], usl[1024], nkl[1024];
short ust[1048576][5], nkt[1048576][5];

int main(void) {
    int n, u, v, m, x;
    scanf("%d %d %d %d", &n, &u, &v, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &usm[i][j]);
            ust[usm[i][j]][++ust[usm[i][j]][0]] = i;
            ust[usm[i][j]][++ust[usm[i][j]][0]] = 500 + j;
            if (i == j) ust[usm[i][j]][++ust[usm[i][j]][0]] = 1000;
            if (i == n - j - 1) ust[usm[i][j]][++ust[usm[i][j]][0]] = 1001;
            if (n == 1) ust[usm[i][j]][0] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &nkm[i][j]);
            nkt[nkm[i][j]][++nkt[nkm[i][j]][0]] = i;
            nkt[nkm[i][j]][++nkt[nkm[i][j]][0]] = 500 + j;
            if (i == j) nkt[nkm[i][j]][++nkt[nkm[i][j]][0]] = 1000;
            if (i == n - j - 1) nkt[nkm[i][j]][++nkt[nkm[i][j]][0]] = 1001;
            if (n == 1) nkt[nkm[i][j]][0] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= ust[x][0]; j++) {
            usl[ust[x][j]]++;
            if (usl[ust[x][j]] == n) u--;
        }
        for (int j = 1; j <= nkt[x][0]; j++) {
            nkl[nkt[x][j]]++;
            if (nkl[nkt[x][j]] == n) v--;
        }

        if (u <= 0 && v <= 0) printf("DRAW\n");
        else if (u <= 0) printf("USAGI\n");
        else if (v <= 0) printf("NEKO\n");
        if (u <= 0 || v <= 0) {
            return 0;
        }
    }
    printf("DRAW\n");
    return 0;
}