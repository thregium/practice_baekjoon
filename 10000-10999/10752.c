#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
문제 : R * C(R, C <= 15) 크기의 격자에 'R'과 'B'가 쓰여 있다. 이때, 가장 왼쪽 위 칸에서 출발해서 가장 오른쪽 아래 칸까지
더 행과 열 수가 큰 색이 다른 칸으로 이동하는 것을 반복하며 가장 오른쪽 아래 칸으로 이동하는 방법의 가짓수를 구한다.

해결 방법 : 왼쪽 위 칸부터 차례로 이동하며 해당 칸의 왼쪽 위에 있는 모든 칸들 가운데 해당 칸과 반대 색인 모든 칸의
가짓수를 더하는 것을 반복하면 된다. 이때, 맨 왼쪽 위 칸을 1로 초기화해야 함에 유의한다.

주요 알고리즘 : DP

출처 : USACO 2015F B3번
*/

char grid[32][32];
int mem[32][32];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hopscotch.in", "r");
        fo = fopen("hopscotch.out", "w");
    }
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", grid[i] + 1);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (i == 1 && j == 1) mem[i][j] = 1;
            for (int ii = 1; ii < i; ii++) {
                for (int jj = 1; jj < j; jj++) {
                    if (grid[i][j] != grid[ii][jj]) mem[i][j] += mem[ii][jj];
                }
            }
        }
    }
    printf("%d", mem[r][c]);
    return 0;
}